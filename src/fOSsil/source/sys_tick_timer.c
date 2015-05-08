/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "sys_tick_timer.h"

typedef void *intr_handler(void);

uint32 VECTOR_TABLE_BASE = 0x0;

void _get_vectortable_base(){

#if defined(QC_RPM)
	VECTOR_TABLE_BASE = 0x0010000;
#elif defined(PSOC4)
	VECTOR_TABLE_BASE = CY_INT_VECT_TABLE;
#endif

}

void _set_msp_active() {
	__set_CONTROL(0);
}

void _set_psp_active() {
	__set_CONTROL(3);
}

void systic_handler() {
	uint32 psp, msp;
	
	psp = __get_PSP();
	msp = __get_MSP();
	
	_set_psp_active();
	_set_msp_active();
	
}

void NVIC_set_vector(uint32 irq_n, intr_handler handler) {
	_get_vectortable_base();
	irq_n = ((uint32)(irq_n) + 0x10);
	((uint32 *)VECTOR_TABLE_BASE)[irq_n] = handler;
	return;
}

void systic_init() {
	//irq_n -> SysTick_IRQn
	//CyIntSetSysVector(CY_INT_SYSTICK_IRQN , systic_handler);
	NVIC_set_vector(SysTick_IRQn, systic_handler);
	SysTick_Config(0x1D4C00);
}

/* [] END OF FILE */
