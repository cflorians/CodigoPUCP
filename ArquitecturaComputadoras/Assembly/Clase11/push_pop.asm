section .text
global _start

_start:
	mov 	rax,	0x0123456789abcdef

	;push 	al 							; no se puede con al
	;push 	ah							; no se puede con ah (no se puede con 8 bits)
	push 	ax							; ax = 0xcdef
	;push	eax							; no se puede con eax (no se puede cno 32 bits)
	push	rax							; rax = 0x0123456789abcdef

										; es igual para los pop, solo con 16 y 64 bits 
	pop 	rax
	;pop 	eax
	pop  	ax
	;pop 	ah
	;pop 	al

	mov 	rax,	60
	mov 	rdi,	29
	syscall