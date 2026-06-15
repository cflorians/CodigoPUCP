#include <stdio.h>

int main(){
	
	int escenario1, escenario2;
	double carga1, carga2, distancia, fuerza1, fuerza2;
	
	printf("Escenario 1: ley de Coulomb\n");
	printf("Ingrese la carga 1 en milicoulombos:\n");
	printf(">");
	scanf("%lf", &carga1);
	printf("Ingrese la carga 2 en coulombos:\n");
	printf(">");
	scanf("%lf", &carga2);
	printf("Ingrese la distancia que separa entre ambas cargas en micrometros:\n");
	printf(">");
	scanf("%lf", &distancia);
	
	double carga1Coulumbos = carga1/1000;
	double distanciaMetros = distancia/1000000;	
	
	printf("La carga 1 tiene %lf coulombos, la carga 2 tiene %lf coulombos y la distancia que separa ambas cargas es %.2f metros\n", carga1Coulumbos, carga2, distanciaMetros);
	
	double k = 9000000000;
	fuerza1 = k*(carga1Coulumbos*carga2)/(distanciaMetros*distanciaMetros);
	printf("La fuerza entre ambas cargas es %.0f Newtons\n", fuerza1);
	
	printf("Escenario 2: ley de Coulomb\n");
	printf("Ingrese la carga 1 en coulombos:\n");
	printf(">");
	scanf("%lf", &carga1);
	printf("Ingrese la carga 2 en microcoulombos:\n");
	printf(">");
	scanf("%lf", &carga2);
	printf("Ingrese la distancia que separa entre ambas cargas en metros:\n");
	printf(">");
	scanf("%lf", &distancia);
	
	double carga2Coulumbos = carga2/1000000;	
	
	printf("La carga 1 tiene %lf coulombos, la carga 2 tiene %lf coulombos y la distancia que separa ambas cargas es %.2f metros\n", carga1, carga2Coulumbos, distancia);
	
	fuerza2 = k*(carga1*carga2Coulumbos)/(distancia*distancia);
	printf("La fuerza entre ambas cargas es %.0f Newtons\n", fuerza2);
	
	int mayorVolumen = fuerza1>fuerza2;
	
	printf("El escenario 1 tiene mayor volumen que el escenario 2: %s\n", mayorVolumen? "VERDADERO":"FALSO");
	printf("El escenario 2 tiene mayor volumen que el escenario 1: %s\n", mayorVolumen? "FALSO":"VERDADERO");
	
	return 0;
}
