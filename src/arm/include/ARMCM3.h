/**************************************************************************//**
 * @file     ARMCM3.h
 * @brief    CMSIS Cortex-M3 Core Peripheral Access Layer Header File
 *           for CM3 Device Series
 * @version  V1.03
 * @date     24. September 2010
 *
 * @note
 * Copyright (C) 2010 ARM Limited. All rights reserved.
 *
 * @par
 * ARM Limited (ARM) is supplying this software for use with Cortex-M 
 * processor based microcontrollers.  This file can be freely distributed 
 * within development tools that are supporting such ARM based processors. 
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/


#ifndef __ARMCM3_H__
#define __ARMCM3_H__

/*
 * ==========================================================================
 * ---------- Interrupt Number Definition -----------------------------------
 * ==========================================================================
 */

typedef enum IRQn
{
/******  Cortex-M3 Processor Exceptions Numbers ***************************************************/
  NonMaskableInt_IRQn         = -14,    /*!<  2 Cortex-M3 Non Maskable Interrupt */
  HardFault_IRQn              = -13,    /*!<  3 Cortex-M3 Hard Fault Interrupt   */
  MemoryManagement_IRQn       = -12,    /*!<  4 Cortex-M3 Memory Management Interrupt             */
  BusFault_IRQn               = -11,    /*!<  5 Cortex-M3 Bus Fault Interrupt    */
  UsageFault_IRQn             = -10,    /*!<  6 Cortex-M3 Usage Fault Interrupt  */
  SVCall_IRQn                 = -5,     /*!< 11 Cortex-M3 SV Call Interrupt      */
  DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M3 Debug Monitor Interrupt                 */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M3 Pend SV Interrupt      */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M3 System Tick Interrupt  */

/******  ARMCM3 specific Interrupt Numbers ********************************************************/
  IRQ0                        = 0,      /*!< GPIO Interrupt 0                      */
  IRQ1                        = 1,      /*!< GPIO Interrupt 1                      */
  IRQ2                        = 2,      /*!< GPIO Interrupt 2                      */
  IRQ3                        = 3,      /*!< GPIO Interrupt 3                      */
  IRQ4                        = 4,      /*!< GPIO Interrupt 4                      */
  IRQ5                        = 5,      /*!< GPIO Interrupt 5                      */
  IRQ6                        = 6,      /*!< GPIO Interrupt 6                      */
  IRQ7                        = 7,      /*!< GPIO Interrupt 7                      */
  IRQ8                        = 8,      /*!< GPIO Interrupt 8                      */
  IRQ9                        = 9,      /*!< GPIO Interrupt 9                      */
  IRQ10                       = 10,     /*!< GPIO Interrupt 10                     */
  IRQ11                       = 11,     /*!< GPIO Interrupt 11                     */
  IRQ12                       = 12,     /*!< GPIO Interrupt 12                     */
  IRQ13                       = 13,     /*!< GPIO Interrupt 13                     */
  IRQ14                       = 14,     /*!< GPIO Interrupt 14                     */
  IRQ15                       = 15,     /*!< GPIO Interrupt 15                     */
  IRQ16                       = 16,     /*!< GPIO Interrupt 16                     */
  IRQ17                       = 17,     /*!< GPIO Interrupt 17                     */
  IRQ18                       = 18,     /*!< GPIO Interrupt 18                     */
  IRQ19                       = 19,     /*!< GPIO Interrupt 19                     */
  IRQ20                       = 20,     /*!< GPIO Interrupt 20                     */
  IRQ21                       = 21,     /*!< GPIO Interrupt 21                     */
  IRQ22                       = 22,     /*!< GPIO Interrupt 22                     */
  IRQ23                       = 23,     /*!< GPIO Interrupt 23                     */
  IRQ24                       = 24,     /*!< GPIO Interrupt 24                     */
  IRQ25                       = 25,     /*!< GPIO Interrupt 25                     */
  IRQ26                       = 26,     /*!< GPIO Interrupt 26                     */
  IRQ27                       = 27,     /*!< GPIO Interrupt 27                     */
  IRQ28                       = 28,     /*!< GPIO Interrupt 28                     */
  IRQ29                       = 29,     /*!< GPIO Interrupt 29                     */
  IRQ30                       = 30,     /*!< GPIO Interrupt 30                     */
  IRQ31                       = 31,     /*!< GPIO Interrupt 31                     */
  IRQ32                       = 32,     /*!< GPIO Interrupt 32                     */
  IRQ33                       = 33,     /*!< GPIO Interrupt 33                     */
  IRQ34                       = 34,     /*!< GPIO Interrupt 34                     */
  IRQ35                       = 35,     /*!< GPIO Interrupt 35                     */
  IRQ36                       = 36,     /*!< GPIO Interrupt 36                     */
  IRQ37                       = 37,     /*!< GPIO Interrupt 37                     */
  IRQ38                       = 38,     /*!< GPIO Interrupt 38                     */
  IRQ39                       = 39,     /*!< GPIO Interrupt 39                     */
  IRQ40                       = 40,     /*!< GPIO Interrupt 40                     */
  IRQ41                       = 41,     /*!< GPIO Interrupt 41                     */
  IRQ42                       = 42,     /*!< GPIO Interrupt 42                     */
  IRQ43                       = 43,     /*!< GPIO Interrupt 43                     */
  IRQ44                       = 44,     /*!< GPIO Interrupt 44                     */
  IRQ45                       = 45,     /*!< GPIO Interrupt 45                     */
  IRQ46                       = 46,     /*!< GPIO Interrupt 46                     */
  IRQ47                       = 47,     /*!< GPIO Interrupt 47                     */
  IRQ48                       = 48,     /*!< GPIO Interrupt 48                     */
  IRQ49                       = 49,     /*!< GPIO Interrupt 49                     */
  IRQ50                       = 50,     /*!< GPIO Interrupt 50                     */
  IRQ51                       = 51,     /*!< GPIO Interrupt 51                     */
  IRQ52                       = 52,     /*!< GPIO Interrupt 52                     */
  IRQ53                       = 53,     /*!< GPIO Interrupt 53                     */
  IRQ54                       = 54,     /*!< GPIO Interrupt 54                     */
  IRQ55                       = 55,     /*!< GPIO Interrupt 55                     */
  IRQ56                       = 56,     /*!< GPIO Interrupt 56                     */
  IRQ57                       = 57,     /*!< GPIO Interrupt 57                     */
  IRQ58                       = 58,     /*!< GPIO Interrupt 58                     */
  IRQ59                       = 59,     /*!< GPIO Interrupt 59                     */
  IRQ60                       = 60,     /*!< GPIO Interrupt 60                     */
  IRQ61                       = 61,     /*!< GPIO Interrupt 61                     */
  IRQ62                       = 62,     /*!< GPIO Interrupt 62                     */
  IRQ63                       = 63      /*!< GPIO Interrupt 63                     */
} IRQn_Type;


/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

/* Configuration of the Cortex-M3 Processor and Core Peripherals */
#define __MPU_PRESENT             1         /*!< MPU present or not                               */
#define __NVIC_PRIO_BITS          2         /*!< Number of Bits used for Priority Levels          */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used     */


#endif  /* __ARMCM3_H__ */
