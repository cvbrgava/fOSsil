// 
// All data and information contained in or disclosed by this document are
// confidential and proprietary information of QUALCOMM Incorporated, and all
// rights therein are expressly reserved. By accepting this material, the
// recipient agrees that this material and the information contained therein are
// held in confidence and in trust and will not be used, copied, reproduced in
// whole or in part, nor its contents revealed in any manner to others without
// the express written permission of QUALCOMM Incorporated.
// 
// This technology was exported from the United States in accordance with the
// Export Administration Regulations. Diversion contrary to U.S. law prohibited.
// ------------------------------------------------------------------------------


/**
* @brief The file defines the IRQ related functions for Cortex M3
*
* @file  cm3_handlers.c
* @author Anand Acharya
* @date Wed Aug 03 14:29:58 2011
*
* @version
* $Revision: 1.3 $
* @par Last check in date:
* $Date: Thu Dec 15 17:48:25 2011 $
* @par Last check in by:
* $Author: acharya $
*/

#ifndef __M3_IRQ_HANDLERS_INCLUDED__
#define __M3_IRQ_HANDLERS_INCLUDED__

#include "cm3_lib.h"
#include <time.h>

extern time_t start_t, time_now;

   /**
   * @brief External symbol definitions
   * These symbols are defined elsewhere and are resolved during the linking.
   */
extern void process_stack(void);   // Defined in process_stack.s
extern void top_of_stacks(void);
extern void cm3_VectorTable(void);   // Defined in cm3_vec_table.s
extern void __main(void);

   /**
   * @brief Default Handler
   * These are default handlers for the system exceptions
   */

static __weak void C_NMI_Handler(void);
static __weak void C_HardFault_Handler(void);
static __weak void C_MemManageFault_Handler(void);
static __weak void C_BusFault_Handler(void);
static __weak void C_UsageFault_Handler(void);
static __weak void C_SVC_Handler(void);
static __weak void C_DebugMon_Handler(void);
//static __weak void C_PendSV_Handler(void);
static __weak void C_SYSTIC_Handler(void);
static __weak void C_IRQ_Handler(void);

    /**
    * @brief Reset Handler for the Cortex M3
    *
    * @param none
    *
    * @return none
    *
    * This is the Reset Handler for Cortex M3.
    */

void Reset_Handler(void);
void C_SYSTIC_Handler(void);
//____________________________________________________________________________


   /**
   * @brief Definition of default handlers
   *
   * All the default handlers implement infinite loop in order to halt the
   * test from proceeding in case of any exception or interrupt. The users are
   * required to override the handlers with their own.
   */
__weak void C_NMI_Handler(void){ while(1) { }; };
__weak void C_HardFault_Handler(void){ while(1) { }; };
__weak void C_MemManageFault_Handler(void){ while(1) { }; };
__weak void C_BusFault_Handler(void){ while(1) { }; };
__weak void C_UsageFault_Handler(void){ while(1) { }; };
__weak void C_SVC_Handler(void){ while(1) { }; };
__weak void C_DebugMon_Handler(void){ while(1) { }; };
__weak void C_PendSV_Handler(void){ while(1) { }; };
//__weak void C_SYSTIC_Handler(void){ while(1) { }; };
__weak void C_IRQ_Handler(void){ while(1) { }; };


   /**
   * @brief Register the default handlers
   *
   * The default handlers are now registered to the vector table with the
   * following assignments.
   */
vv_int_func_type NMI_Handler            = C_NMI_Handler;
vv_int_func_type HardFault_Handler      = C_HardFault_Handler;
vv_int_func_type MemManageFault_Handler = C_MemManageFault_Handler;
vv_int_func_type BusFault_Handler       = C_BusFault_Handler;
vv_int_func_type UsageFault_Handler     = C_UsageFault_Handler;
vv_int_func_type SVC_Handler            = C_SVC_Handler;
vv_int_func_type DebugMon_Handler       = C_DebugMon_Handler;
vv_int_func_type PendSV_Handler         = C_PendSV_Handler;
//vv_int_func_type SYSTIC_Handler         = C_SYSTIC_Handler;


   /**
   * @brief The implementation of the Reset Handler
   *
   * The reset handler only initializes the Process stack pointer and then
   * initializes the Vector table offset register with the value of vector
   * table offset in the memory.
   */

void Reset_Handler(void) {

  // Set the Process Stack
  __set_PSP(&process_stack);
    // Set the Main Stack
  __set_MSP(&top_of_stacks);
  // Update register
  SCB->VTOR = &cm3_VectorTable;
  // Jump to Main
  __main();
}

   /**
   * @brief The implementation of the Reset Handler
   *
   * The reset handler only initializes the Process stack pointer and then
   * initializes the Vector table offset register with the value of vector
   * table offset in the memory.
   */
/* kbpillai for testing 
#pragma arm section code="Init"
__asm void Reset_Handler(void) {

   IMPORT    top_of_stacks ; defined in stack.s and located by scatter file
   LDR    r0, =top_of_stacks
   MSR    msp, r0
   IMPORT    process_stack ; defined in process_stack.s and located by scatter file
   LDR    r0, =process_stack
   MSR    psp, r0
   IMPORT    cm3_VectorTable
   LDR    r0, =cm3_VectorTable
// SCB->VTOR = 0xE000ED08      
   LDR    r1, =0xE000ED08
   STR    r0, [r1]
   IMPORT    __main
   B      __main
   NOP
}
*/
//____________________________________________________________________________


    /**
    * @brief Method to set the Interrupt vector for system interrupts and IRQ
    *
    * @param IRQn - The enumeration for IRQ type to be registered
    * @param pFnc - Pointer to the function to be registered as ISR
    *
    * @return Pointer to old IRQ handler
    *
    * The function defines the exception handler for any system interrupts and
    * faults. The function can also be used to register the IRQ handlers
    * The function pointer becomes the new ISR function for the given
    * exception
    */

uint32_t vv_int_set_vector (IRQn_Type IRQn, vv_int_func_type  pFnc) {

  volatile uint32_t irqAddr;

  // Calculate the IRQ handler offset
  uint32_t irqNum =  (uint32_t)IRQn + 16;
  // Set the LSB to make sure the ISR is set for Thumb mode
  volatile uint32_t funcAddr = (uint32_t)pFnc | 0x1;

  // Calculate the address where the IRQ handler pointer is stored
  irqAddr = (uint32_t)(SCB->VTOR + (irqNum << 2));
  // Update the pointer with new function address
  *(uint32_t *)irqAddr = funcAddr;

  // Return older pointer.
  return irqAddr;
}


#endif
