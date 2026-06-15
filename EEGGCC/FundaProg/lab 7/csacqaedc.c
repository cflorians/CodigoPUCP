#include <stdio.h>

int main (){
	
	int numero, resultado;
	char opcion;
	
	printf("menu\n");
	printf("A: verificar fibonacci\n");
	printf("B: verificar tribonacci\n");
	printf("B: verificar pell\n");
	printf("Ingrese una opcion: ");
	scanf(" %c", &opcion);
	
	if (opcion=='A'||opcion=='B'||opcion=='C'){
		 do{
			printf("Ingrese un numero: ");
		 	scanf("%d", numero);
		 	if (0<numero){
		 		break;
			}
		 } while(1);
		 
		 switch (opcion){
		 	case 'A':
		 		resultado=verificarFibonacci(numero);
		 		if (resultado){
		 			printf("Si es num de fibonacci\n");
				}
				else{
					printf("No es num de fibonacci\n");
				}
				break;
			case 'B':
				resultado=verificarTribonacci(numero);
				if (resultado){
					printf("Si es num de tribonacci\n");
				}
				else{
					printf("no es num de tribonacci\n");
				}
				break;
			case 'C':
				resultado=verificarPell(numero);
				if (resultado){
					printf("si es num de pell\n");
				}
				else{
					printf("no es num de pell\n");
				}
				break;
		 }
	}
	else{
		printf("opcion invalida")
	}
	
	return 0;
}
