;************************************************************************
; filename: stack.s							*
;									*
;;; Copyright ARM Ltd 2001. All rights reserved.			*
;************************************************************************
    PRESERVE8
        AREA    ProcessStacks, DATA, NOINIT, ALIGN=3
        EXPORT process_stack
; Create dummy variable used to locate stacks in memory
process_stack    SPACE   1
        END
