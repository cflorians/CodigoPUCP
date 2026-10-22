# Repaso Parcial Perifericos

## Teclado y matriz de texto
> Entrada 1: Datos de un teclado
> Entrada 2: Teclado vacio (0) teclado con aun por leer (1)
> Entrada 3: no definido

> Salida 0: Matriz de texto
> Salida 1, 2 y 3: no definidas

### Programa en C:

``` C
	int main(){
		int dir_funcion = 0x40;
		bool avaiable
		char caracter;

		while (1){
			if (avaiable) lectura_escritura(&avaiable);
		}

		return 0;
	}

	void lectura_escritura(bool avaiable){
		caracter = RIO1;
		avaiable = RIO2;

		// escribimos en la matriz de texto
		WIO1 = caracter

		return;
	}
```

### Programa en Assambly

``` Assambly
	LOAD R7, 4
	LSL R7
	LSL R7
	LSL R7
	LSL R7 // aca tenemos en R7 el puntero a funcion
	LOAD R6, 3
	NOT R6
	LOAD R5, 1
	SUM R6, R5 // aca tenemos -3
	RIO2
	SRZ R2 //si es que el registro 2 (avaiable) es 0, entonces skipeamos el call
	CALL R7
	JUMPR R6
	--------Subrutina--------
	RIO1
	LOAD R4, 0
	SUM R4, R1
	WIO0
	RET
```

## Programa de clase
Switch a led
```
	LOAD R4, 6
	LOAD R0, 1
	LSL R4
	NOT R4
	SUM R4, R0
	RIO1 <- JUMPR salta aquí
	RIO2
	RIO3
	LOAD R5, 0
	LOAD R6, 0
	LOAD R7, 0
	SUM R5, R1
	SUM R6, R2
	SUM R7, R3
	WIO1
	WIO2
	WIO3
	JUMPR R4
```

Teclado a ram
```
	LOAD R0, 4
	LSL R0
	LSL R0
	LSL R0
	LSL R0
	SUM R7, R0
	LSL R0
	LOAD R5, 1
	LOAD R1, 3
	NOT R1
	SUM R1, R5
	LOAD R4, 3
	RIO3
	SRZ R3
	CALL R7
	JUMPR R1
	--------Subrutina--------
	RIO2
	WIO0
	LOAD R4, 0
	WIO0
	LOAD R4, 3
	WRITE [R0], R2
	SUM R0, R5
	RET
```