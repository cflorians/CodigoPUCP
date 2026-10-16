#include <stdio.h>
#include <math.h>

double calcularValorEsperado(double );
double calcularValorSerie(double , int );

int main(){
	
	double valorX, valorEsperado, resultado, error, mayorError=0;
	int cantExp, i=1, cantIt, peorI;
	
	printf("Ingrese el valor de X: ");
	scanf("%lf", &valorX);
	printf("Ingrese la cantidad de experimentos: ");
	scanf("%d", &cantExp);
	valorEsperado=calcularValorEsperado(valorX);
	printf("El valor esperado es: %lf\n", valorEsperado);
	
	do{
		printf("Ingrese la cantidad de iteraciones para el experimento %d: ", i);
		scanf("%d", &cantIt);
		resultado=calcularValorSerie(valorX, cantIt);
		printf("El valor obtenido es: %lf\n", resultado);
		error=fabs(resultado-valorEsperado);
		if (mayorError<=error){
			peorI=cantIt;
			mayorError=error;
		}
		i++;
	} while (i<=cantExp);
	
	printf("\nLa peor precisión se logra con %d iteraciones\n", peorI);
	
	return 0;
}

double calcularValorEsperado(double x){
	return x/pow(1-x,2);
}

double calcularValorSerie(double x, int cantIt){
	double sumatoria=0;
	int i=0;
	
	do{
		sumatoria+=i*pow(x,i);
		i++;
	} while(i<=cantIt);
	
	return sumatoria;
}
