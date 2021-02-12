section	.text
global	_ft_strlen

_ft_strlen:
	push	rcx				; Empile rcx
	xor		rcx, rcx		; Met rcx à 0

ft_strlen_core:
	cmp		[rdi], byte 0	; Compare le caractere passé en parametre à un 0
	jz		ft_strlen_end	; Si la réponse précédente a renvoyé 0 on va a la fin du programme
	inc		rcx				; On incrémente rcx
	inc		rdi				; On incrémente rdi
	jmp		ft_strlen_core	; On boucle

ft_strlen_end:
	mov		rax, rcx		; On récupère la valeur au dessus de la pile
	pop		rcx				; On dépile et met RSP à jour
	ret						; On retourne