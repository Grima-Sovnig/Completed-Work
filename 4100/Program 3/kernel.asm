; Gabriel Snider
BITS 32
GLOBAL k_printstr
GLOBAL go
GLOBAL dispatch
GLOBAL dispatch_leave
GLOBAL outportb
GLOBAL init_timer_dev

EXTERN running
EXTERN queue
EXTERN enqueue
EXTERN dequeue
EXTERN lidtr

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

    mov esi, [ebp+8] ; string
    mov eax, [ebp+12] ; rows
    mov ebx, [ebp+16] ; col

    ;calculating offset
    imul eax, 80
    add eax, ebx
    imul eax, 2
    add eax, 0xB8000
    mov edi, eax

loop:

    ;comparing offest if greater than
    cmp edi, 0xB8F9E
    jg loop_end

    ;comparing string to 0
    cmp BYTE [esi], 0
    je loop_end

    movsb

    ;moving color onto screen
    mov BYTE [edi], 31

    ;moving to next letter
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

go:
    push DWORD [queue]
    call dequeue

    mov [running], eax
    
go_rest:
    mov esp, [eax]
    popad
    ret

dispatch:
    call yield

dispatch_leave:
    push eax
    mov al, 0x20
    out 0x20, al
    pop eax
    iret

yield:
    pusha

    mov esi, [running]
    mov [esi], esp

    push DWORD [running]
    push DWORD [queue]
    call enqueue
    jmp go

lidtr:
    push    ebp
    mov     ebp, esp

    push    eax
    mov     eax, [ebp+8]
    lidt    [eax]

    pop     eax
    pop     ebp
    ret

outportb:

    push ebp
    mov ebp, esp
    push edx
    push eax

    mov edx, [ebp+8]
    mov eax, [ebp+12]

    out dx, al

    pop eax
    pop edx
    pop ebp
    
    ret

init_timer_dev:

    push ebp
    mov ebp, esp
    push eax
    push edx

    mov edx, [ebp+8]
    imul dx, 1193

    mov al, 0b00110110
    out 0x43, al
    mov ax, dx
    out 0x40, al
    xchg ah, al
    out 0x40, al

    pop edx
    pop eax
    pop ebp

    ret
