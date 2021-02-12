section	.text
global	_ft_strcpy

_ft_strcpy:
    xor     rax, rax

ft_strcpy_core:
    mov     dl, byte [rsi + rax]
    mov     byte [rdi + rax], dl
    cmp     dl, 0
    jz      ft_strcpy_end
    inc     rax
    jmp     ft_strcpy_core

ft_strcpy_end:
    mov     rax, rdi
    ret
    

