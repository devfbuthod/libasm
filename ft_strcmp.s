section	.text
global	_ft_strcmp

_ft_strcmp:
	xor		rax, rax

.loop:
	mov		cl, byte [rdi + rax]
	mov		dl, byte [rsi + rax]
    cmp     cl, 0
    jz      .endr
	cmp		cl, dl
	jl		.endl
    jg      .endt
	inc		rax
	jmp		.loop

.endl:
	mov		rax, -1
	ret

.endt:
    mov		rax, 1
	ret

.endr:
    sub     cl, dl
    cmp     cl, 0
    jl      .endl
    jg      .endt
    movsx   rax, cl
    ret
