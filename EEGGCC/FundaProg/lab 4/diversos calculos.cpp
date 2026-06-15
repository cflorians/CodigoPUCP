#include <stdio.h>
#include <math.h>

void solicitarIteraciones(int *);
void raizCubicaPorIteracion(double ,int ,double *);
double raizCubicaPorPow( double );
int verificarRaizCubica(double , double );
void calcularSumatoria(double ,int ,double *);

int main(){
	
	double numeroEntrada, numeroSalida;
	int numeroIteraciones;
	char opcion;
	
	printf("Menú de opciones:\n-Aproximar raíz cubica (A)\n-Calcular Sumatoria (B)\n");
	printf("Ingrese la opción: ");
	scanf(" %c", &opcion);
	
	if (opcion=='A'){
		printf("\nIngrese el numero de la raíz cúbica que desea calcular: ");
		scanf("%lf", &numeroEntrada);
		if (0<numeroEntrada){
			solicitarIteraciones( &numeroIteraciones);
			if (0<=numeroIteraciones && numeroIteraciones<=50){
				raizCubicaPorIteracion( numeroEntrada, numeroIteraciones, &numeroSalida);
				double raizCubica=raizCubicaPorPow( numeroEntrada);
				printf("\nLa raíz cúbica de %0.lf es %lf\n", numeroEntrada, numeroSalida);
				printf("La raíz cúbica calculada con Pow es %lf\n", raizCubica);
				if (verificarRaizCubica(numeroSalida, raizCubica)==1){
					printf("\nEl resultado obtenido es aceptado porque el error es menor a 0.0001");
				}
				else{
					printf("\nEl resultado obtenido NO es aceptado porque el error es mayor a 0.0001");
				}
			}
			else{
				printf("\nEl numero de iteraciones debe estar en [0;50]\n");
			}
		}
		else{
			printf("\nEl numero debe ser positivo");
		}
	}
	else{
		if (opcion=='B'){
			printf("\nIngrese el valor de X: ");
			scanf(" %lf", &numeroEntrada);
			if (1<=numeroEntrada && numeroEntrada<=5){
				solicitarIteraciones( &numeroIteraciones);
				if (0<=numeroIteraciones && numeroIteraciones<=10){
					calcularSumatoria( numeroEntrada, numeroIteraciones, &numeroSalida);
					printf("\nEl resultado de la sumatoria es: %lf", numeroSalida);
				}
				else{
					printf("\nEl numero de iteraciones debe estar entre [0;10]\n");
				}
			}
			else{
				printf("\nEl numero debe estar entre [1;5]");
			}
		}
		else{
			printf("\nOpción invalida");
		}
	}
	return 0;
}

void solicitarIteraciones(int *numeroIteraciones){
	printf("Ingrese la cantidad de veces que desea iterar: ");
	scanf("%d", numeroIteraciones);
}

void raizCubicaPorIteracion(double numeroEntrada,int numeroIteraciones,double *numeroSalida){
	double a=numeroEntrada;
	int n=1;
	double x=1.0;
	while (n<=numeroIteraciones){
		double xSig=(2*x+a/pow(x,2))/3;
		x=xSig;
		n++;
	}
	*numeroSalida = x;
}

double raizCubicaPorPow( double numeroEntrada){
	double x=1;
	while (pow(x,3)!=numeroEntrada){
		x++;
	}
	return x;
}

int verificarRaizCubica(double numeroSalida, double raizCubica){
	if (numeroSalida-raizCubica<0.0001 || raizCubica-numeroSalida<0.0001){
		return 1;
	}
	else{
		return 0;
	}
}

void calcularSumatoria(double numeroEntrada,int numeroIteraciones,double *numeroSalida){
	int i=0;
	double sumaTotal=0;
	double x=numeroEntrada;	
	while (i<numeroIteraciones){
		
		int k=1;
		double factorial_2i=1.0;
		while (k<=2*i){
			factorial_2i *= k;
			k++;
		}
		
		k=1;
		double factorial_2i_1=1.0;
		while (k<=2*i+1){
			factorial_2i_1 *= k;
			k++;
		}
		
		double suma = pow(x,2)/factorial_2i+pow(2+i,2)/factorial_2i_1;
		sumaTotal += suma;
		i++;
	}
	*numeroSalida=sumaTotal;
}
