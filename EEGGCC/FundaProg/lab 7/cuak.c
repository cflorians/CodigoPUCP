#include <stdio.h>
#include <math.h>

void calcularValorPi(int ,double *);

int main(){
	
	int iteraciones;
	double pi;
	char tipoAplicacion;
	
	printf("Ingrese el número de iteraciones para calcular Pi: ");
	scanf("%d", &iteraciones);
	
	if (5<iteraciones && iteraciones<=20){
		printf("Ingrese el tipo de aplicación del Número Pi\n");
		printf("(Periodo del péndulo [P], Área lateral de superficie de un cono [C] o Área de una Elipse [E]):\n");
		printf("> ");
		scanf(" %c", &tipoAplicacion);
		if (tipoAplicacion=='P' || tipoAplicacion=='C' || tipoAplicacion=='E'){
			calcularValorPi(iteraciones, &pi);
			if (tipoAplicacion=='P'){
				double longitud, aceleracion, periodo;
				printf("Ingrese la longitud del péndulo (metros): ");
				scanf("%lf", &longitud);
				printf("Ingrese la aceleración del péndulo (m/s²): ");
				scanf("%lf", &aceleracion);
				periodo=2*pi*sqrt(longitud/aceleracion);
				printf("El periodo de un péndulo de longitud %.2lf y aceleración %.2lf es %.2lf segundos\n", longitud, aceleracion, periodo);
			}
			else{
				double area;
				if (tipoAplicacion=='C'){
					double radio, lado;
					printf("Ingrese el radio de la base del cono (metros): ");
					scanf("%lf", &radio);
					printf("Ingrese el lado lateral del cono (metros): ");
					scanf("%lf", &lado);
					area=pi*radio*lado;
					printf("El área lateral de un cono de radio %.2lf en la base y lado lateral %.2lf es %.2lf metros", radio, lado, area);
				}
				else{
					double longMayor, longMenor;
					printf("Ingrese la longitud del semieje mayor de la elipse (metros): ");
					scanf("%lf", &longMayor);
					printf("Ingrese la longitud del semieje menor de la elipse (metros): ");
					scanf("%lf", &longMenor);
					area=pi*longMayor*longMenor;
					printf("El área de una elipse se semiejes %.2lf y %.2lf es %.2lf metros²", longMayor, longMenor, area);
				}
			}
		}
		else{
			printf("La aplicación ingresada no es válida\n");
		}
	}
	else{
		printf("El número de iteraciones debe ser mayor a 5 y menor o igual 20.\n");
	}
	
	return 0;
}

void calcularValorPi(int iteraciones,double *pi){
	double x1, xn;
	int i=1;
	x1=sqrt(2);
	while (i<=iteraciones){
		xn=sqrt(2-(2*sqrt(1-(pow(x1, 2))/4)));
		x1=xn;
		i++;
	}
	*pi=xn;
}
