#include <stdio.h>
#include <math.h>

int main(){
	
	int cantCalc, bandera;
	double energia;
	char tipoEnergia;
		
	printf("Ingrese la cantidad de cálculos de energía: ");
	scanf("%d", &cantCalc);
	
	int i=1;
	int opCorrectas=0;
	int energiaMenor=0;
	int iMenor=1;
	
	if (0<cantCalc && cantCalc<=10){
		printf("C: Energía cinetica\nG: Energía potencial gravitacional\nE: Energía potencial elástica\n");
		while (i<=cantCalc){
			printf("Ingrese el tipo de energía #%d: ", i);
			scanf(" %c", &tipoEnergia);
			if (tipoEnergia=='C' || tipoEnergia=='c'){
				double masa, velocidad;
				printf("Ingrese la masa (g) y la velocidad (m/s): ");
				scanf("%lf %lf", &masa, &velocidad);
				if (0<masa && masa<1000 && 0<velocidad && velocidad<50){
					energia = (1/2)*(masa/100)*pow(velocidad,2);
					opCorrectas++;
					bandera=1;
				}
				else{
					printf("Datos invalidos\n");
					bandera=0;
				}
			}
			else{
				if (tipoEnergia=='G'||tipoEnergia=='g'){
					double masa, altura;
					printf("Ingrese la masa (kg) y la altura (cm): ");
					scanf("%lf %lf", &masa, &altura);
					if (0<masa && masa<10 && 0<altura && altura<1000){
						energia = (masa)*9.81*(altura/100);
						opCorrectas++;
						bandera=1;	
					}
					else{
						printf("Datos invalidos\n");
						bandera=0;
					}
				}
				else{
					if (tipoEnergia=='E'||tipoEnergia=='e'){
						double posInicial, posFinal;
						printf("Ingrese la posicion inicial y final (m): ");
						scanf("%lf %lf", &posInicial, &posFinal);
						if (posFinal<posInicial && 0<posFinal){
							energia = (1/2)*2.35*(posInicial, posFinal);
							opCorrectas++;
							bandera=1;						
						}
						else{
							printf("Datos invalidos\n");
							bandera=0;
						}
					}
					else{
						printf("Tipo de energia ingresado incorrecto\n");
						bandera=0;
					}
				}
			}
			if (bandera==1){
				printf("Energía = %lf\n", energia);
			}
			if (i==1){
				energiaMenor=energia;
				iMenor=i;
			}
			else{
				if (energia<energiaMenor){
					energiaMenor=energia;
					iMenor=i;
				}
			}
			i++;
		}
		if (opCorrectas>0){
			printf("Se realizaron correctamente %d cálculos de energía\n", opCorrectas);
			printf("La menor energía es %lf y corresponde al cálculo numero %d\n", energiaMenor, iMenor);
		}
		else{
			printf("No se realizó correctamente ningún cálculo\n");
		}
	}
	else
		printf("La cantidad de calculos debe ser mayor a 0 y menor o igual a 10\n");
	
	return 0;
}
