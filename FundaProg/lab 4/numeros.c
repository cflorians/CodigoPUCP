#include <stdio.h>

int main(){
	
	int numCaracteres, numDecimal, repeticiones;
	char caracter, anterior;
	int valorActual, valorAnterior;
	
	int bandera = 1;
	
	printf("Ingresa el número de caracteres: ");
	scanf(" %d", &numCaracteres);
	printf("Ingrese cada uno de los caracteres \n");
	
	scanf(" %c", &anterior);
	//Devuelve el valor de "anterior" 
	if (anterior == 'M'){
		valorAnterior = 1000;
	}
	else{
		if (anterior == 'D'){
			valorAnterior = 500;
		}
		else{
			if (anterior == 'C'){
				valorAnterior = 100;
			}
			else{
				if (anterior == 'L'){
					valorAnterior = 50;
				}
				else{
					if (anterior == 'X'){
						valorAnterior = 10;
					}
					else{
						if (anterior == 'V'){
							valorAnterior = 5;
						}
						else{
							valorAnterior = 1;
						}
					}
				}
			}
		}
	}
	
	numDecimal = valorAnterior;
	int i = 1;
	
	while (i < numCaracteres){
		scanf(" %c", &caracter);
		// devuelve el valor de caracter actual
		if (caracter == 'M'){
			valorActual = 1000;
		}
		else{
			if (caracter == 'D'){
				valorActual = 500;
			}
			else{
				if (caracter == 'C'){
					valorActual = 100;
			}
				else{
					if (caracter == 'L'){
						valorActual = 50;
				}
					else{
						if (caracter == 'X'){
							valorActual = 10;
						}
						else{
							if (caracter == 'V'){
								valorActual = 5;
						}
							else{
								valorActual = 1;
							}
						}
					}
				}
			}
		}	
		// contar repes
		if (caracter == anterior){
			repeticiones++;
			if (repeticiones == 4){
				printf("No de puede ingresar 4 veces el mismo caracter \n");
				bandera = 0;
			}
		}
		else{
			repeticiones = 1;
		}
		
		if (valorActual > valorAnterior){
			numDecimal = numDecimal - 2*valorAnterior+valorActual; 
		}
		else{
			numDecimal = numDecimal + valorActual;
		}
		anterior = caracter;
		valorAnterior = valorActual;
		i++;
	}
	
	if (bandera=1){
		printf("El valor decimal es: %d", numDecimal);
	}
	
	return 0;
}
