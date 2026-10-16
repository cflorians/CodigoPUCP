#include <stdio.h>

int main(){
	
	double peso, coefEstatico, fuerza, fuerzaRozamiento;
	
	printf("Ingrese el peso de la caja en Newtons: \n");
	printf("> ");
	scanf("%lf", &peso);
	
	printf("Ingrese el coeficiente de rozamiento estático: \n");
	printf("> ");
	scanf("%lf", &coefEstatico);
	
	printf("Ingrese la fuerza en Newtons que se aplicara: \n");
	printf("> ");
	scanf("%lf", &fuerza);
	
	fuerzaRozamiento = coefEstatico * peso;
	
	if (fuerza > fuerzaRozamiento){
		printf("Si se mueve la caja");
	}
	else{
		printf("No se mueve la caja");
	}
	
	return 0;
}
