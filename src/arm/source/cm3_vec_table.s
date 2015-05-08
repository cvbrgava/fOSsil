; 
; All data and information contained in or disclosed by this document are
; confidential and proprietary information of QUALCOMM Incorporated, and all
; rights therein are expressly reserved. By accepting this material, the
; recipient agrees that this material and the information contained therein are
; held in confidence and in trust and will not be used, copied, reproduced in
; whole or in part, nor its contents revealed in any manner to others without
; the express written permission of QUALCOMM Incorporated.
; 
; This technology was exported from the United States in accordance with the
; Export Administration Regulations. Diversion contrary to U.S. law prohibited.
; ------------------------------------------------------------------------------



    PRESERVE8

        AREA    CM3_VecTable, DATA, READWRITE, ALIGN=9

; These are example exception vectors and exception handlers
; *****************
; Exception Vectors
; *****************

; Note: LDR PC instructions are used here because branch (B) instructions
; could not simply be copied (the branch offsets would be wrong).  Also,
; a branch instruction might not reach if the ROM is at an address >32MB).

;    ENTRY
    THUMB

    EXPORT cm3_VectorTable

cm3_VectorTable
    IMPORT top_of_stacks    ; defined in stack.s, located by scatter file
    DCD top_of_stacks

    IMPORT Reset_Handler
    DCD Reset_Handler
    
    IMPORT NMI_Handler [WEAK] 
    DCD NMI_Handler
    
    IMPORT HardFault_Handler [WEAK]
    DCD HardFault_Handler

    IMPORT MemManageFault_Handler [WEAK]
    DCD MemManageFault_Handler

    IMPORT BusFault_Handler [WEAK]
    DCD BusFault_Handler

    IMPORT UsageFault_Handler [WEAK]
    DCD UsageFault_Handler

    DCD 0       ; Reserved Space
    DCD 0
    DCD 0
    DCD 0

    IMPORT SVC_Handler [WEAK]
    DCD SVC_Handler

    IMPORT DebugMon_Handler [WEAK]
    DCD DebugMon_Handler

    DCD 0           ; Reserved space

    IMPORT PendSV_Handler [WEAK]
    DCD PendSV_Handler

    IMPORT SYSTIC_Handler 
    DCD SYSTIC_Handler

; IRQ Handlers for 64 interrupt routines

    IMPORT IRQ_Handler [WEAK]
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler
    DCD IRQ_Handler


    END
