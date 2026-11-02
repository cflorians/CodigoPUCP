section .text
global _start

_start:
	mov 	rax, 	1					; rax = 1
	add 	rax,	0xcafd				; reg + inm -> rax = 0xcafe

	mov 	rax, 	0xa 				; rax = 0xa
	mov  	rbx,	0x7 				; rbx = 0x7
	add  	rax, 	rbx  				; reg + reg -> rax = 0x11

	mov 	rcx,	0xab				; rcx = ab
	mov 	rdx, 	0xcd				; rdx = cd
	add 	rcx, 	rdx					; reg + reg -> rcx = 0x178

	mov 	rax, 	1					; rax = 1
	add  	rax,   	0xffffffffffffffff	; desborda  -> rax = 0, CF = 1
	; CF es Carry Flag, cuando es 1 significa que hay desborde

adios:
	mov  	rax, 	60
	syscall