section .data
texto:
	db	'Hola '
fin_texto:

section .text
global _start

_start:

	mov 	rbx,	1000000				; contador para el bucle					

bucle:

	mov		rdi,	1 					; fd de la terminal
	mov		rsi,	texto				; dirección de lo que se va a escribir 
	mov		rdx,	fin_texto - texto	; longitud de lo que imprimiremos
	mov		rax,	1					; syscall write
	syscall

	dec		rbx
	cmp		rbx,	0
	jne		bucle

adios:
	mov		rax,	60
	syscall