Algoritmo cuak
	
	//cuaaaaaak
	Escribir "1. Numero de cifras"
	Escribir "2. Extraer cifras de derecha a izquierda"
	Escribir "3. Extraer cifras de izquierda a derecha"
	Escribir "4. Cambio de base"
	Leer operacion
	Si operacion=1 O operacion=2 O operacion=3 O operacion=4 Entonces
		Escribir "Ingrese el numero a evaluar"
		Leer num
		Si 0<num Entonces
			
			Segun operacion Hacer
				1:
					//divides el numero entre 10 (sin contar los decimales con el trunc)
					//las veces que dividas entre 10 hasta que la copia sea 0 es la cantidad de cifras
					copiaNum <- num
					cantCifras <- 0
					Repetir
						//ambos valores se actualizan en cada iteracion
						copiaNum <- trunc(copiaNum/10)
						cantCifras <- cantCifras+1
					Mientras Que 0<copiaNum
					Escribir "El número ", num, " tiene ", cantCifras, " cifras"
				2:
					//inicias j para el numero de digito desde la derecha que sea
					j <- 1
					Repetir
						//el digito por derecha va a ser el residuo del numero entre 10
						//este valor se actualiza en cada iteracion
						digito <- copiaNum2 mod 10
						
						//tu nuevo numero va a ser quitando la cifra de la derecha
						//entonces divides entre 10 sin los decimales
						//este valor se actualiza en cada iteracion
						copiaNum2 <- trunc(copiaNum2/10)
						
						//imprimes el digito
						Escribir "Digito ", j, ": ", digito
						
						//sumas 1 a j para que pase al siguiente digito
						//este valor se actualiza en cada iteracion
						j <- j+1
					Mientras Que 0<copiaNum2 //cuando la copiaNum2 sea igual a 0 significa que ya no puedes seguir sacando digitos
				3:
					//necesitas el numero de digitos para poder dividir el numero desde un principio
					copiaNum <- num
					cantCifras <- 0
					Repetir
						//ambos valores se actualizan en cada iteracion
						copiaNum <- trunc(copiaNum/10)
						cantCifras <- cantCifras+1
					Mientras Que 0<copiaNum
					//como copiaNum ya vale 0, necesitamos otra nueva copia si despues queremos mostrar el numero original
					copiaNum2 <- num
					j <- 1
					Repetir
						//sacamos el primer digito desde la izquierda que es el de mayor valor numerico
						//entonces lo dividimos entre 10 elevado a su numero de cifras-j
						//este valor se actualiza en cada iteracion
						digito <- trunc(copiaNum2/(10^(cantCifras-j)))
						
						//el nuevo valor del numero sera el residuo que queda de la division anterior
						//este valor se actualiza en cada iteracion
						copiaNum2 <- copiaNum2 mod (10^(cantCifras-j))
						
						//imprimes el digito
						Escribir "Digito ", j, ": ", digito
						
						//sumas 1 a j para que pase al siguiente digito
						//este valor se actualiza en cada iteracion
						j <- j+1
					Mientras Que 0<copiaNum2
				4:
					//pides la base del destino
					Escribir "Ingrese la base de destino: "
					Leer base
					
					///BUSCA COMO SE CAMBIA DE BASE A MANO PARA QUE ENTIENDAS EL DESARROLLO
					//para imprimir el numero original utilizamos una copia para no afectar su valor y poder imprimirlo despues
					//el nuevo numero inicia desde 0 porque vamos a ir sumandole valores
					//k inicia en 0 porque si elevamos 10 a la 0 nos da 1 y eso queremos para colocar las cifras en orden
					copiaNum <- num
					nuevoNum <- 0
					k <- 0
					
					//hay 2 formas de hacerlo, en el lab de hoy pedian de izq a derecha
					//es mas dificil pero la idea es la misma
					//solo tendrias que usar la forma de sacar cifras por izquierda y multiplicarlas por 10^(cantCifras-k)
					//y si sale medio raro inicias desde k=1
					Repetir
						//sacamos desde la derecha el digito
						digito <- copiaNum mod base
						
						//actualizamos el num como ya sabemos
						copiaNum <- trunc(copiaNum/base)
						
						//el numero convertido sera la sucesion de sumar el valor anterior de nuevoNum al digito elevado a 10^k para ponerlo en orden
						nuevoNum <- nuevoNum + digito*10^k
						
						//sumamos 1 a k
						k <- k+1
					Mientras Que 0<copiaNum
					//mostramos el resultado
					Escribir "El número en base ", base, " es: ", nuevoNum
			Fin Segun
		FinSi
	SiNo
		Escribir "Operación incorrecta"
	FinSi
	
	
	
FinAlgoritmo
