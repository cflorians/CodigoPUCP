#include <stdio.h>
#include <math.h>

int main(){
	
	double masa, estatura, imc;
	
	printf("Ingrese su peso en kg: \n");
	printf("> ");
	scanf("%lf", &masa);
	
	printf("Ingrese su estatura en metros: \n");
	printf("> ");
	scanf("%lf", &estatura);
	
	imc = masa/pow(estatura,2);
	
	if ( imc < 18.5 ){
		printf("Bajo peso")	;
	}
	else{
		if ( imc < 25){
			printf("Peso normal");
		}
		else {
			if ( imc < 30){
				printf("Preobeso");	
			}
			else{
				if ( imc < 35){
					printf("Obesidad leve");
				}
				else {
					if ( imc < 40){
						printf("Obesidad media");
					}
					else{
						printf("Obesidad mórbida");
					}
				}
			}
		}
	}
	
	return 0;
}
