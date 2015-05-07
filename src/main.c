#include "cm3_lib.h"
#include <stdio.h>
#include <time.h>
#include "fOSsil.h"
#include "main.h"

#define SYS_TICKS	100000
#define MIN_STACK_SIZE (sizeof(CONTEXT))

typedef void *p_func(void);

//TODO: Move to list.
TASK aTasks[4];

__inline void invoke_pendsv() {
	//invoke PEND_SV handler.
	SCB->ICSR |= 1 << 28;
}

__inline void clean_pendsv() {
	//invoke PEND_SV handler.
	SCB->ICSR |= 1 << 27;
}

__inline void _set_msp_active() {
	__set_CONTROL(__get_CONTROL() & (~2));	//bit_1 of Control reg.
	//__set_CONTROL(0);
}

__inline void _set_psp_active() {
	__set_CONTROL(__get_CONTROL() | (2));	//bit_1 of Control reg.
	//__set_CONTROL(3);
}

__inline void set_psp_task(TASK t) {
	__set_PSP(t.sp_process);
}

__ASM __inline uint32 save_psp_context()
{
	mrs r0, psp
	STMDB R0!,{R4-R11} 	// Save R4 to R11 in task stack (8 regs) LDR R1
	msr psp, r0
	bx lr
}

__ASM __inline uint32 restore_psp_context()
{
	MRS r0, psp
	LDMFD r0!, {r4-r11}
	MSR psp, r0
	BX lr
}

void PENDSV_Handler() {
	clean_pendsv();
	_set_psp_active();
}

void SYSTIC_Handler( void ) {
	static index=0;

#if defined(DEBUG)
	if((index % 1000)==0) {
		time_now = time(NULL);
		printf("Time elapsed: %d\n", time_now - start_t);
	}
#endif

	//save PSP context.
	aTasks[index].sp_process = save_psp_context();

	set_psp_task(aTasks[(index+1) % 4]);
	restore_psp_context();

	//Disable sys_tick.
	//SysTick->CTRL = 0;

	// Clear interrupt.
	SCB->ICSR |= 1<<SCB_ICSR_PENDSTCLR_Pos;

	index = (++index) % 4;
}

void task1() {
	static uint32 i = 0;
	while(1)
		i ++;
}

void task2() {
	static uint32 i = 0;
	while(1)
		i ++;
}

void task3() {
	static uint32 i = 0;
	while(1)
		i ++;
}

void task_exit() {
	while(1);
}

void task_idle() {
	while(1);
}

static void task_registration(TASK * t) {
	TASK_REG tr;

	//Register the task in memory.
	tr.return_addr = (uint32)(t->func_pointer) | 1;			//thumb mode address.
	tr.psr = 0x01000000;									//thumb mode.
	tr.LR = &task_exit;
	memcpy(t->sp_process - sizeof(tr) / sizeof(t->sp_process) , &tr, sizeof(tr));

	// Move SP_process.
	t->sp_process -= sizeof(CONTEXT) / sizeof(t->sp_process);
}

//TODO: remove the index parameter with ds_list.
void task_create(p_func pf, uint32 stack_size, int8 priority, uint8 index) {
	uint32 * psp = malloc(MIN_STACK_SIZE + stack_size);
	psp += stack_size / 4; 	//Bottom of stack.
	aTasks[index].func_pointer = pf;
	aTasks[index].sp_process = psp;
	aTasks[index].priority = priority;
	task_registration(aTasks + index);
}

void os_init() {
	//TODO: Vector table relocation.

	//Register Idle task.
	task_create(&task_idle, 0x10, -1, 0);
}

void os_run() {
	//Start with os_idle task.
	set_psp_task(aTasks[0]);
	_set_psp_active();

	//systick running.
	SysTick_Config(SYS_TICKS);

	task_idle();
}

void main() {
	// Interrupt registration.
	//vv_int_set_vector (PendSV_IRQn, PENDSV_Handler);

	list_testing();

	// OS init.
	os_init();

	// Register tasks.
	task_create(&task1, 0x10, 0, 1);
	task_create(&task2, 0x10, 0, 2);
	task_create(&task3, 0x10, 0, 3);

	// OS init.
	os_run();

	// Unreachable.
	while(1);
}
