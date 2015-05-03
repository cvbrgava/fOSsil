#include "cm3_lib.h"
#include <stdio.h>
#include <time.h>
#include "fOSsil.h"
#include "main.h"

time_t start_t, time_now;

uint32 psp_top;

TASK aTasks[2];


void invoke_pendsv() {
	//invoke PEND_SV handler.
	SCB->ICSR |= 1 << 28;
}

void clean_pendsv() {
	//invoke PEND_SV handler.
	SCB->ICSR |= 1 << 27;
}

void _set_msp_active() {
	__set_CONTROL(__get_CONTROL() & (~2));
	//__set_CONTROL(0);
}

void _set_psp_active() {
	__set_CONTROL(__get_CONTROL() | (2));
	//__set_CONTROL(3);
}

void set_psp_task(TASK t) {
	__set_PSP(t.sp_process);
}

__ASM uint32 save_psp_context() {
	mrs r0, psp
	STMDB R0!,{R4-R11} 	// Save R4 to R11 in task stack (8 regs) LDR R1
	msr psp, r0
	bx lr
}

__ASM uint32 restore_psp_context() {
	MRS r0, psp
	LDMFD r0!, {r4-r11}
	MSR psp, r0
	BX lr
}

__ASM void exc_return() {
	MOV R14, #0xFFFFFFFD
}

void SYSTIC_Handler( void ){
	static index=0;

	index++;
	SCB->ICSR |= 1<<SCB_ICSR_PENDSTCLR_Pos;

#if defined(DEBUG)
	if((index % 1000)==0) {
		time_now = time(NULL);
		printf("Time elapsed: %d\n", time_now - start_t);
	}
#endif

	//save PSP context.
	aTasks[0].sp_process = save_psp_context();

	set_psp_task(aTasks[1]);
	restore_psp_context();
	//exc_return();
}

void PENDSV_Handler() {
	clean_pendsv();

	_set_psp_active();

}

void task() {
	static uint32 i = 0;
	while(1)
		i ++;
}

void task_idle() {
	static uint32 i = 0;
	while(1)
		i ++;
}

void CONTEXT_INIT(CONTEXT * c) {
	c->cf.reg[0] = 0;
	c->cf.reg[1] = 0;
	c->cf.reg[2] = 0;
	c->cf.reg[3] = 0;
	c->cf.reg[4] = 0;
	c->cf.reg[5] = 0;
	c->cf.reg[6] = 0;
	c->cf.reg[7] = 0;


	c->sf.r0 = 0;
	c->sf.r1 = 0;
	c->sf.r2 = 0;
	c->sf.r3 = 0;
	c->sf.r12 = 0;
	c->sf.LR = 0;
	c->sf.return_addr = 0;
	c->sf.psr = 0;
}

void task_registration(TASK * t) {
	uint32 i;
	CONTEXT c;
	CONTEXT_INIT(&c);

	c.sf.return_addr = t->func_pointer;
	memcpy(t->sp_process - 16 , &c, 64);

	t->sp_process -= 16;
}

__ASM setTaskPC() {
	pop {pc}
}

void main() {
	volatile uint32 psp, msp;
	uint32 *psp0, *psp1;

	//printf("Hello World!\n");
	start_t = time(NULL);

	//vv_int_set_vector (PendSV_IRQn, PENDSV_Handler);

#if defined(DEBUG)
	psp = __get_PSP();
	msp = __get_MSP();
	printf("PSP: 0x%.8X, MSP: 0x%.8X\n", psp, msp);
#endif

	//systic_init();

	psp0 = (uint32 *)malloc(0x1000);
	psp0 += 0x1000 / 4;
	aTasks[0].func_pointer = &task_idle;
	aTasks[0].sp_process = psp0;
	//task_registration(aTasks[0]);

	//Tasks registration.
	psp1 = (uint32 *)malloc(0x1000);
	psp1 += 0x1000 / 4;
	aTasks[1].func_pointer = &task;
	aTasks[1].sp_process = psp1;
	task_registration(&aTasks[1]);

	// Even now content of stack pointers are invalid
	// Make valid stack pointer

	SysTick_Config( 100000 );

	set_psp_task(aTasks[0]);
	_set_psp_active();
	task_idle();

}

