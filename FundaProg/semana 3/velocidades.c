#include <stdio.h>

int main(){
	
	double vProm, vAng, vTan, angulo, distancia, tiempo, radio;
	char operacion;
	
	int bandera = 1;
	
	printf("Menú de opciones:\n (V) Velocidad promedio\n (W) Velocidad angular\n (T) Velocidad tangencial\n");
	printf("> ");
	scanf("%c", &operacion);
	
	if (operacion == 'V'){
		printf("Ingrese la distancia recorrida: \n");
		printf("> ");
		scanf("%lf", &distancia);
		if (distancia<0){
			bandera = 0;
			printf("La distancia debe ser un valor positivo");
		}
		printf("Ingrese el tiempo transcurrido: \n");
		printf("> ");
		scanf("%lf", &tiempo);
		if (tiempo<0){
			bandera = 0;
			printf("El tiempo debe ser un valor positivo");
		}
	}
	else{
		if (operacion == 'W' && bandera == 1){
			printf("Ingrese el cambio de angulo generado: \n", angulo);
			printf("> ");
			scanf("%lf", &angulo);
			if (angulo<0||angulo>360){
			bandera = 0;
			printf("El cambio de angulo debe estar entre 0 y 360");
			}
			if (bandera==1){
				printf("Ingrese el cambio de tiempo: \n");
				printf("> ");
				scanf("%lf", &tiempo);
			}
			if (tiempo<0){
				bandera = 0;
				printf("El tiempo debe ser un valor positivo");
			}
		}
		else {
			if (bandera == 1){	
				printf("Ingrese el radio de la trayectoria: \n");
				printf("> ");
				scanf("%lf ", &)
			}
		}
	}	
	
	return 0;
}
