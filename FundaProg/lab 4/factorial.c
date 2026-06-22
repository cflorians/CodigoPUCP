#include <stdio.h>

int main(){
	
	int numero, factorial;
	int i=1;
	
	printf("Ingrese un numero: ");
	scanf("%d", &numero);
	factorial=numero;
	while (i<numero){
		factorial*=i;
		i++;
	}
	
	printf("%d! = %d", numero, factorial);
	
	return 0;
}
