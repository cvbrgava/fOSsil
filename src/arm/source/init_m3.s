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

        AREA    Init, CODE, READONLY

; These are example exception vectors and exception handlers
; *****************
; Exception Vectors
; *****************

; Note: LDR PC instructions are used here because branch (B) instructions
; could not simply be copied (the branch offsets would be wrong).  Also,
; a branch instruction might not reach if the ROM is at an address >32MB).

;    ENTRY
    THUMB

    EXPORT m3_VectorTable

m3_VectorTable
    IMPORT top_of_stacks    ; defined in stack.s, located by scatter file
    DCD top_of_stacks

    IMPORT Reset_Handler
    DCD Reset_Handler

    END
