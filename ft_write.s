section .text
global  _ft_write

_ft_write:
    mov     rax, 1
    mov     rbx, rsi
    push    rbp
    call    _ft_strlen
    
