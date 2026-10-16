#include <stdio.h>

void leerDatos(double *, int *);
void calcularRaizCuadrada(double ,double *,double *,double *);

int main(){
	
	double n, coef, promedio;
	double a=1;
	int i;
	int contador=1;
	
	leerDatos(&n, &i);
	if (0<n&&1<i){
		printf("i	N	a		N/a		Promedio\n");
		while (contador<=i){
			calcularRaizCuadrada(n,&a,&coef,&promedio);
			printf("%d	%0.lf	%lf	%lf	%lf\n", contador, n, a, coef, promedio);
			contador++;
		}
		printf("\nLa raíz cuadrada de %lf obtenida es %lf", n, promedio);
	}
	else{
		if (n<0){
			printf("El número debe ser positivo");
		}
		else{
			printf("La cantidad de iteraciones debe ser mayor a 1");
		}
	}
	
	return 0;
}

void leerDatos(double *n, int *i){
	printf("Ingrese un número positivo: ");
	scanf("%lf", n);
	printf("Ingrese la cantidad de iteraciones: ");
	scanf("%d", i);
}

void calcularRaizCuadrada(double n,double *a,double *coef,double *promedio){
	*coef=n/(*a);
	*promedio=((*a)+(*coef))/2;
	*a=*promedio;
}
