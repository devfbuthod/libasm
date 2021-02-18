extern ___error
global  _ft_read

_ft_read:
    mov     rax, 0x2000003
    syscall
    jc      .error
    ret

.error:
    push    r9
    mov     r9, rax
    call    ___error
    mov     [rax], r9
    mov     rax, -1
    pop     r9
    ret
