#include <stdio.h>
#include <math.h>

void leerDatos(double *valorX, int *numTerminos);
void CalcLogNatural(double valorX, int numTerminos, double *logaritmo);

int main (){
	
	double valorX, logaritmo;
	int numTerminos;
	
	leerDatos(&valorX, &numTerminos);
	if (0<numTerminos){
		if (0<valorX){
			CalcLogNatural(valorX, numTerminos, &logaritmo);
			printf("El logaritmo de %lf es %lf\n",valorX, logaritmo);
		}
		else{
			if (valorX<0){
				printf("El logaritmo de %lf es nan\n",valorX);
			}
			else{
				printf("El logaritmo de %lf es -inf\n",valorX);
			}
		}
	}
	else{
		printf("La cantidad de terminos debe ser mayor o igual a 0");
	}

	return 0;
}

void leerDatos(double *valorX, int *numTerminos){
	
	printf("Ingrese el valor de x: ");
	scanf("%lf", valorX);
	printf("Ingrese el numero de terminos: ");
	scanf("%d", numTerminos);
	
}

void CalcLogNatural(double valorX, int numTerminos, double *logaritmo){
	
	double n=0;
	double suma=0;
	while (n<numTerminos){
		double  termino = (1/(2*n+1))*pow(((valorX-1)/(valorX+1)), 2*n+1);
		suma = suma + termino;
		n++;
	}
	*logaritmo=2*(suma);

}
