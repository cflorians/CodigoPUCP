section .text
global _start

_start:
	mov  	rdi, 	10
	mov 	rsi, 	20
	call 	multiplicacion
	
adios:						; Finaliza el programa
	mov 	rdi, 	rax
	mov 	rax, 	60
	syscall

multiplicacion:
	mov 	rax, 	rdi
	mul 	rsi
	ret