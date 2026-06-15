Algoritmo clasificacionIMC
	Escribir "Ingrese su peso en kilogramos:"
	Leer peso
	Si 0<peso Entonces
		Escribir "Ingrese su talla en metros:"
		Leer altura
		Si 0<altura Entonces
			Escribir "Ingrese su edad:"
			Leer edad
			Si 20<=edad Y edad<=39 Entonces
				Escribir "Ingrese si es atleta: "
				Leer atleta
				Si atleta='S' O atleta='N' Entonces
					imc<-(peso)/(altura^2)
					porcentajeDeGrasa<-(1.2*imc)+(0.23*edad)-16.2
					Escribir "El porcentaje de grasa corporal calculado es: ", porcentajeDeGrasa
					Si atleta='S' Entonces
						ideal<-0
						Si edad<=29 Entonces
							Si porcentajeDeGrasa<11 Entonces
								ideal<-1
							Fin Si
						SiNo
							Si porcentajeDeGrasa<12 Entonces
								ideal<-1
							Fin Si
						Fin Si
						Si ideal=1 Entonces
							Escribir "El porcentje de grasa es ideal para un hombre atleta"
						SiNo
							Escribir "El porcentaje de grasa no es el ideal para un hombre atleta"
						FinSi
					SiNo
						Si edad<=29 Entonces
							imc<-imc+1
						FinSi
						Si porcentajeDeGrasa<12 Entonces
							Escribir "El porcentaje de grasa es muy bajo para un hombre que no es atleta"
							//es bajo 
						SiNo
							Si porcentajeDeGrasa<=14 Entonces
								Escribir "El porcentaje de grasa es el ideal para un hombre que no es atleta" 
								//es ideal
							SiNo
								Si porcentajeDeGrasa<=21 Entonces
									Escribir "El porcenaje de grasa es normal para un hombre que no es atleta"
									//es normal
								SiNo
									Escribir "El porcentaje de grasa es elevado para un hombre que no es atleta"
									//elevado
								Fin Si
							Fin Si
						Fin Si
					Fin Si
				SiNo
					Escribir "El indicador de atleta ingresado no es correcto"
				Fin Si
			SiNo
				Escribir "La edad ingresada no es correcta"
			Fin Si
		SiNo
			Escribir "La talla ingresada no es correcta"
		Fin Si
	SiNo
		Escribir "El peso ingresado no es correcto"
	Fin Si
	
FinAlgoritmo
