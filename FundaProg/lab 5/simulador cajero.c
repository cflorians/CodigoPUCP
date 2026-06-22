#include <stdio.h>

void menuOpciones(int *, int, int);

int main(){
	
	int opcion;
	int saldo=1000;
	int i=0;
	int contador=1;
	while (i<1){
		menuOpciones(&opcion, saldo, contador);
		if (opcion==1){
			//retirar dinero
			saldo=retirarDinero(saldo);
			contador++;
		}
		else{
			if (opcion==2){
				saldo=depositarDinero(saldo);
				contador++;
			}
			else{
				if (opcion==3){
					//salir
					i++;
				}
				else{
					printf("Ingrese una opción valida\n");
				}
			}
		}
	}
	return 0;
}

void menuOpciones(int *opcion,int saldo,int contador){
	
	if(contador==1){
		printf("\nEl saldo inicial es de %d soles\n", saldo);
	}
	else{
		printf("\nEl nuevo saldo es de %d soles\n", saldo);
	}
	printf("\nQue acción deseas realizar\n");
	printf("1. Retirar dinero\n");
	printf("2. Depositar dinero\n");
	printf("3. Salir\n");
	printf("> ");
	scanf("%d", opcion);	
}

int retirarDinero(int saldo){
	int cantidad;
	int i=0;
	printf("\nRETIRAR DINERO\n");
	printf("\nEscriba la cantidad que desea retirar\n");
	while (i<1){
		printf("> ");
		scanf("%d", &cantidad);
		if (cantidad<=saldo){
			saldo=saldo-cantidad;
			i++;
		}
		else{
			printf("El monto a retirar excede el saldo actual\n");
			printf("Ingrese una cantidad valida\n");
		}
	}
	return saldo;
}

int depositarDinero(int saldo){
	int cantidad;
	printf("\nRETIRAR DINERO\n");
	printf("\nEscriba la cantidad que desea retirar\n");
	printf("> ");
	scanf("%d", &cantidad);
	saldo=saldo+cantidad;
	return saldo;
}
