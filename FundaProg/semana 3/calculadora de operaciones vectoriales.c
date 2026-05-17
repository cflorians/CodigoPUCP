#include <stdio.h>

int main(){
	
	double ux, uy, vx, vy, rx, ry;
	char operador;
	
	int bandera = 1;
	
	printf("Ingrese la operación vectorial a realizar: ");
	scanf("%lf %lf %c %lf %lf", &ux, &uy , &operador, &vx, &vy);
	
	if ( operador == '+'){
		rx = (ux+vx);
		ry = (uy+vy);
	}
	else {
		if ( operador == '-'){
			rx = (ux-vx);
			ry = (uy-vy);
		}
		else {
			if ( operador == '.'){
				bandera = 0;
				double resultado = (ux*vx) + uy*vy;
				printf("El resultado de (%0.lf,%0.lf)%c(%0.lf,%0.lf) = %0.lf", ux, uy, operador, vx, vy, resultado);
			}
			else {
				bandera = 0;
				printf("Operador invalido");
			}
		}
	}
	
	if (bandera){
		printf("El resultado de (%0.lf,%0.lf)%c(%0.lf,%0.lf) = (%0.lf,%0.lf)", ux, uy, operador, vx, vy, rx, ry);
	}	
	return 0;
}
