#include <stdio.h>

int main(){
	
	double capital, plazo, interes, saldo, saldoDeseado;
	
	printf("Ingrese el capital a depositar: \n");
	printf("> ");
	scanf("%lf", &capital);
	printf("Ingrese el plazo y la tasa de interes: \n");
	printf("> ");
	scanf("%lf", &plazo);
	printf("> ");
	scanf("%lf", &interes);
	printf("Ingrese el saldo final deseado: \n");
	printf("> ");
	scanf("%lf", &saldoDeseado);
	
	saldo = capital*(1+plazo*(interes*0.01));
	
	if (saldo > saldoDeseado){
		printf("Conviene depositar en el banco");
	}
	else{
		printf("NO conviene depositar en el banco");
	}
	return 0;
}
