; Problem 1
; Author:  Gabriel Snider
; Date:    2/14/2022

.586
.MODEL FLAT

.STACK  4096            ; reserve 4096-byte stack

.DATA                   ; reserve storage for data
number  DWORD   -105
number2 DWORD   105
sum     DWORD   ?

.CODE                           ; start of main program code
main    PROC
        mov     eax, number     ; first number to EAX
        add     eax, number2    ; add number2 to EAX
        mov     sum, eax        ; sum to memory

        mov   eax, 0            ; exit with return code 0
        ret
main    ENDP

END                             ; end of source code
