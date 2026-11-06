subrutina:
	mov rcx, rsi ; movemos la cantidad de números al contador
	mov rsi, rdi ; movemos la direccion a rsi
	mov rax, 0 ; colocamos 0 en rax para limpiarlo

.bucle:
	cmp [rsi], rax ; comparamos si el numero actual es mayor
	jb .avanza ; saltamos la siguiente instruccion si rdx < rax
	mov rax, [rsi] ; colocamos el numero actual en rax
.avanza:
	add rsi, 8 ; avanza al siguiente numero
	loop .bucle ; vuelve al inicio del bucle
regresa:
	ret ; regresamos al main