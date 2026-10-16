#include <stdio.h>
#include <math.h>

int main(){
	
	double masa, estatura, imc;
	
	printf("Ingrese su peso en kg: \n");
	printf("> ");
	scanf("%lf", &masa);
	
	printf("Ingrese su estatura en metros: \n");
	printf("> ");
	scanf("%lf", &estatura);
	
	imc = masa/pow(estatura,2);
	
	if ( 18.5 <= imc && imc <= 24.9 ){
		printf("El peso es normal");
	}
	else{
		printf("El peso NO es normal");
	}
	
	return 0;
}
