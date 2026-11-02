section .text
global _start

_start:
	mov 	rax, 	0x0123456789abcdef
	mov 	rbx, 	0x6767676767676767
	mov 	rcx, 	0xcafecafecafecafe
	mov 	rdx, 	0xdad0dad0dad0dad0

	mov  	al,		0xca
	mov 	ah, 	0x00
	mov 	bx, 	0x15a
	mov  	edx,	0xbebe

adios:
	mov 	rax, 	60
	syscall