Algoritmo imprimeTriangulos
	intentado<-0
	correcto<-0
	Repetir
		Escribir "Ingrese el tipo de triángulo a imprimir:"
		Leer tipo
		validarTipo<- tipo='I' o tipo='i' o tipo='D' o tipo='d' o tipo='H' o tipo='h' o tipo='A' o tipo='a' o tipo='L' o tipo='l'
		Si validarTipo Entonces
			
			Escribir "Ingrese un número positivo: "
			Leer n
			Si 0<n Entonces
				Segun tipo Hacer
					'I' o 'i':
						
						i<-1
						Repetir
							contador<-1
							Repetir
								Escribir "* " Sin Saltar
								contador<-contador+1
							Mientras Que contador<=i
							Escribir " "
							i<-i+1
						Mientras Que i<=n
						correcto<-correcto+1
					'D' o 'd':
						i<-1
						Repetir
							contador<-1
							Mientras contador<=n-i
								Escribir "  " Sin Saltar
								contador<-contador+1
							FinMientras
							contador2<-1
							Repetir
								Escribir "* " Sin Saltar
								contador2<-contador2+1
							Mientras Que contador2<=i
							Escribir " "
							i<-i+1
						Mientras Que i<=n
						correcto<-correcto+1
					'H' o 'h':
						i<-1
						Repetir
							contador<-1
							Mientras contador<(n-1)/2
								Escribir "  " Sin Saltar
								contador<-contador+1
							FinMientras
							contador2<-1
							Repetir
								Escribir "* " Sin Saltar
								contador2<-contador2+1
							Mientras Que contador2<=i
							Escribir " "
							i<-i+1
						Mientras Que i<=n
						correcto<-correcto+1
					'A' o 'a':
						Escribir "a"
					'L' o 'l':
						Escribir "l"
				Fin Segun
			SiNo
				Escribir "El número debe ser positivo" 
			Fin Si
		SiNo
			Escribir "Opción invalida"
			
		Fin Si
		intentado<-intentado+1
	Mientras Que validarTipo
	Escribir "La cantidad de triangulos generados correctamente es: ", correcto
	Escribir "La cantidad de triangulos fallidos es: ", intentado-correcto
	
FinAlgoritmo
