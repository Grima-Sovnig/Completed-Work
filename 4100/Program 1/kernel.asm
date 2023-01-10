BITS 32
GLOBAL k_printstr

k_printstr:
    push ebp
    mov ebp, esp
    
    pushf
    push eax
    push ebx
    push ecx
    push edx
    push esi
    push edi
    
    mov esi, [ebp+8]   ;string
    mov ebx, [ebp+12]  ;row
    mov ecx, [ebp+16]  ;column
    
    imul ebx, 80
    add ebx, ecx
    imul ebx, 2
    add ebx, 0xB8000
    mov edi, ebx

loop:
    cmp edi, 0xB8FA0
    jg loop_end

    cmp BYTE [esi], 0
    je loop_end

    movsb
    mov BYTE [edi], 31

    inc edi
    
    jmp loop

loop_end:
    pop edi
    pop esi
    pop edx
    pop ecx
    pop ebx
    pop eax
    popf
    pop ebp
    ret