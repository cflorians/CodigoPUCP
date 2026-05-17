#include <stdio.h>

int main(){
	
	double pesoMedio, tallaMedia, perimetroCraneal;
	double cantidadEdad, peso, talla;
	char genero, edad;
	
	int bandera = 1;
	
	printf("Ingrese si se evaluara a niños (H) o a niñas (M): \n");
	printf("> ");
	scanf(" %c", &genero);
	/*que genero es*/
	if (genero == 'H'){
		printf("Ingrese M si el niño tiene meses o A si tiene años: \n");
	}
	else{
		printf("Ingrese M si la niña tiene meses o A si tiene años: \n");
	}	
	/*si es genero valido, pide edad*/
	
	printf("> ");
	scanf(" %c", &edad);

	/*pide cantidad de meses o años*/
	if (edad == 'M'){
		printf("Ingrese la cantidad de meses: \n");
		printf("> ");
		scanf("%lf", &cantidadEdad);
		}
	else {
		if (edad == 'A'){
			printf("Ingrese la cantidad de años: \n");
			printf("> ");
			scanf("%lf", &cantidadEdad);
		}
		else {
			bandera = 0;
			printf("Debe ingresar una opción válida para medir la edad");
		}
	}

	/*esto es tipo una tabla con los datos dependiendo del numero de meses o años*/
	if (genero == 'H'){
		if (cantidadEdad == 0){
			pesoMedio = 3.4;
			tallaMedia = 50.3;
			perimetroCraneal = 34.8;
		}
		else {
			if (cantidadEdad == 3){
				pesoMedio = 6.2;
				tallaMedia = 60;
				perimetroCraneal = 41.2;
			}
			else{
				if (cantidadEdad == 6){
					pesoMedio = 8;
					tallaMedia = 67;
					perimetroCraneal = 44;
				}
				else{
					if (cantidadEdad == 9){
						pesoMedio = 9.2;
						tallaMedia = 72;
						perimetroCraneal = 46;
					}
					else{
						if (cantidadEdad == 1){
							pesoMedio = 10.2;
							tallaMedia = 76;
							perimetroCraneal = 47.3;
						}
					}
				}
			}
		}
	}
	else{
		if (genero == 'M'){
			if (cantidadEdad == 0){
				pesoMedio = 3.4;
				tallaMedia = 50.3;
				perimetroCraneal = 34.1;
			}
			else {
				if (cantidadEdad == 3){
					pesoMedio = 5.6;
					tallaMedia = 59;
					perimetroCraneal = 40;
				}
				else{
					if (cantidadEdad == 6){
						pesoMedio = 7.3;
						tallaMedia = 65;
						perimetroCraneal = 42.8;
					}
					else{
						if (cantidadEdad == 9){
							pesoMedio = 8.6;
							tallaMedia = 70;
							perimetroCraneal = 44.7;
						}
						else{
							if (cantidadEdad == 1){
								pesoMedio = 9.5;
								tallaMedia = 74;
								perimetroCraneal = 46;
							}
						}
					}
				}
			}
		}
		else {
			bandera = 0;
			printf("Ingrese una opcion válida para medir la edad");
		}
	}
	
	if (bandera == 1){
		if (genero == 'H'){
			printf("El niño debe tener como peso %.1lf kg, como altura media %.0lf cm y como perímetro craneal %.1lf para la edad ingresada\n", pesoMedio, tallaMedia, perimetroCraneal);		
		}
		else{
			printf("La niña debe tener como peso %.1lf kg, como altura media %.0lf cm y como perímetro craneal %.1lf para la edad ingresada\n", pesoMedio, tallaMedia, perimetroCraneal);			
		}
	}

	if (bandera == 1){
		printf("Ingrese el peso del niño o niña en Kg: \n");
		printf("> ");
		scanf("%lf", &peso);
		printf("Ingrese la talla del niño o niña en metros: \n");
		printf("> ");
		scanf("%lf", &talla);
		double tallaCm = talla*100;
	
		if (peso > pesoMedio){
			printf("El peso es mayor al peso medio que debería tener\n");
		}
		else{
			if (peso < pesoMedio){
				printf("El peso es menor al peso medio que debería tener\n");
			}
			else{
				printf("El peso es igual al peso medio\n");
			}
		}
		
		if (talla > tallaMedia){
			printf("La altura es mayor que la altura que debería tener\n");
		}
		else{
			if (talla < tallaMedia){
				printf("La altura es menor que la altura que debería tener\n");
			}
			else {
				printf("La altura es igual a la altura media\n");
			}
		}
	}
	
	return 0;
}
