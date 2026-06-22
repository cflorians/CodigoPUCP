#include <stdio.h>

int main(){
	
	int numero;
	printf("Ingrese el numero que desea saber si es primo o no: ");
	scanf("%d", &numero);
	if (1<numero){
		int i=2;
		int contadorDivisores=0;
		while(i*i<numero){
			if(numero%i==0){
				if (contadorDivisores<2){
					contadorDivisores++;
				}
				else{
					i=numero;
				}
			}
			i++;
		}
		if (contadorDivisores<=2){
			printf("%d ES primo", numero);
		}
		else{
			printf("%d NO es PRIMO", numero);
		}
	}
	else{
		printf("El numero debe ser mayor a 1");
	}
	return 0;
}
