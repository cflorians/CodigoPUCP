#include <stdio.h>
#include <math.h>

#define G 9.8

double calcularMRU(char);
double calcularMRUV(char);
double calcularCaidaLibre(char);

int main(){
	
	int numOperaciones;
	double resultado;
	char operacion;
	int i=1;
	
	printf("Ingrese la cantidad de evaluaciónes a realizar: ");
	scanf("%d", &numOperaciones);
	while (i<=numOperaciones){
		printf("\nIngrese la opción de ecuación a realizar: ");
		scanf(" %c", &operacion);
		if (operacion=='A'){
			resultado=calcularMRU(operacion);
			printf("La posición final con MRU es %.2lf\n", resultado);
		}
		else{
			if (operacion=='B'){
				resultado=calcularMRUV(operacion);
				printf("La posición final con MRUV es %.2lf\n", resultado);
			}
			else{
				resultado=calcularCaidaLibre(operacion);
				printf("La posición final con CAIDA LIBRE es %.2lf\n", resultado);
			}
		}
		i++;
	}
	return 0;
}

double calcularMRU(char operacion){
	double posInicial, velocidad, tiempo;
	double posFinal;
	printf("Ingrese la posición inicial: ");
	scanf("%lf", &posInicial);
	printf("Ingrese la velocidad: ");
	scanf("%lf", &velocidad);
	printf("Ingrese el tiempo: ");
	scanf("%lf", &tiempo);
	posFinal=posInicial+velocidad*tiempo;
	return posFinal;
}

double calcularMRUV(char operacion){
	double posInicial, velocidad, tiempo, aceleracion;
	double posFinal;
	printf("Ingrese la posición inicial: ");
	scanf("%lf", &posInicial);
	printf("Ingrese la velocidad: ");
	scanf("%lf", &velocidad);
	printf("Ingrese el tiempo: ");
	scanf("%lf", &tiempo);
	printf("Ingrese la aceleracion: ");
	scanf("%lf", &aceleracion);
	posFinal=posInicial+velocidad*tiempo+(0.5)*aceleracion*pow(tiempo,2);
	return posFinal;
}

double calcularCaidaLibre(char operacion){
	double altura, tiempo;
	double posFinal;
	printf("Ingrese la altura: ");
	scanf("%lf", &altura);
	printf("Ingrese el tiempo: ");
	scanf("%lf", &tiempo);
	posFinal=altura-0.5*G*pow(tiempo,2);
	return posFinal;
}
