	section .text
	global _start

	_start:
		mov 	AL, 	1 	; 	setea en 1 el registro AL dentro de RAX

	lazito:
		inc 	RAX			; 	incrementa en 1 RAX
		cmp  	RAX, 	10	; 	RAX = 10 ?
		jne 	lazito		; 	Si no es igual, regresa a lazito

	adios:
		mov 	RAX, 	60	;	syscall exit
		syscall 			; 	syscall de numero RAX