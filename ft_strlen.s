section	.text
global	_ft_strlen

_ft_strlen:
	push	rcx
	xor		rcx, rcx

ft_strlen_core:
	cmp		[rdi], byte 0
	jz		ft_strlen_end
	inc		rcx
	inc		rdi
	jmp		ft_strlen_core

ft_strlen_end:
	mov		rax, rcx
	pop		rcx
	ret