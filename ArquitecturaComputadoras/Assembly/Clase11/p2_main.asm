section .data
arreglo:
	dq 7,3,10,4,5,2,6
section .text
global _start
%include "preg_2a_20240282.asm"
_start:
	mov rdi, arreglo ; colocamos la direccion del arreglo en rdi
	mov rsi, 7 ; colocamos la cantidad de numeros en rsi
	call subrutina ; llamamos a la subrutina
adios:
	mov rdi, rax ; movemos a rdi el resultado devuelto por la subrutina
	mov ra