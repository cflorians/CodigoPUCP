section .text
global _start

_start:
	mov 	rdi,	50
	mov		rsi, 	8
	mov		rdx,	2
	
	call 	resta3
	mov 	rdi, 	rax

adios:
	mov 	rax,	60
	syscall

resta3:
	;	Recibe 3 numeros
	;		1. rdi
	;		2. rsi
	;		3. rdx
	mov 	rax,	rdi
	sub		rax,	rsi
	sub		rax,	rdx
	ret