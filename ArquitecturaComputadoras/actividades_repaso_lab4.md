# Fecha en memoria
**Objetivo**: Guardar 25-09-26 en hexadecimal en 3 bytes de memoria
## Pseudo-Codigo
Carga 1
Carga 80 en R6
Carga 25 en R0
Guarda R0 en la RAM
Carga 9 en R0
Guarda R0 en la RAM
Carga 26 en R0
Guarda R0 en la RAM
## Pseudo-assambly
LOAD R7, 1  
LOAD R6, 4  
LSL R6  
LSL R6  
LSL R6  
LSL R6  
LSL R6  
LOAD R0, 4  
LSL R0  
SUM R1, R0  
SUM R1, R7  
LSL R0  
LSL R0  
LOAD R4, 5  
SUM R0, R4  
SUM R3, R6  
WRITE [R3], R0  
SUM R3, R7  
WRITE [R3], R1  
SUM R3, R7  
SUM R0, R7  
WRITE [R3], R0  

# Fibonacci
**Objetivo**: Generar todos los terminos de 8 bits de la serie de fibonacci en cierto espacio de memoria usando una subrutina
## Pseudo-codigo
a = 0
b = 1
llamadas = 7
ptr = 0x80
uno = 1
menos_uno = 0xFF
dir_fib = 0x24

main{
	repetir{
		fib()
		llamadas = llamadas-1
		if (llamadas = 0) terminar
	}
}

fib{
	memoria[ptr] = a;
	ptr = ptr+1;
	a = a+b;
	memoria[ptr] = b;
	ptr = ptr + 1
	b = b + a
	return
}
## Pseudo-assambly
LOAD R1, 1  
LOAD R2, 7  
LOAD R3, 4  
LSL R3  
LSL R3  
LSL R3  
LSL R3  
LSL R3  
NOT R7  
LOAD R6, 4  
LSL R6  
LSL R6  
LSL R6  
LOAD R5, 4  
SUM R6, R5  
LOAD R5, 1  
LOAD R4, 3  
NOT R4  
SUM R4, R5  
CALL R6  
SUM R2, R7  
SRZ R2  
JUMPR R4  
LOAD R4, 0  
JUMPR R4  

WRITE [R3], R0  
SUM R3, R5  
SUM R0, R1  
WRITE [R3], R1  
SUM R3, R5  
SUM R1, R0  
RET  

# Promedio 4 notas
## Assambly
LOAD R5, 1  
LOAD R6, 4  
LSL R6  
LSL R6  
LSL R6  
SUM R4, R6  
LSL R6  
LSL R6  
READ R0, [R6]  
SUM R6, R5  
READ R1, [R6]  
SUM R6, R5  
READ R2, [R6]  
SUM R6, R5  
READ R3, [R6]  
CALL R4  
JUMPR  

SUM R0, R1  
SUM R0, R2  
SUM R0, R3  
LSR R0  
LSR R0  
RET  