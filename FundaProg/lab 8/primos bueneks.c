#include <stdio.h>

int validarPrimo(int );
int validarPrimoBueno(int );

int main(){
	
	int inicio, fin, primo, primoBueno, cantPrimos=0, cantPrimosBuenos=0, cantNum=0;
	
	printf("Ingresar el rango en el cual se evaluarán los números primos: ");
	scanf("%d %d", &inicio, &fin);
	
	if (0<inicio && inicio<fin){
		printf("Lista de números primos en el rango: \n");
		int num = inicio;
		
		do{
			primo = validarPrimo(num);
			if (primo){
				primoBueno=validarPrimoBueno(num);
				cantPrimos++;
			}
			if (primoBueno){
				printf("%d es un número primo bueno\n");
				cantPrimosBuenos++;
			}
			else{
				printf("%d\n", num);
			}
			num++;
			cantNum++;
		} while(num<=fin);
		
		printf("En el rango [%d,%d] hay %d números primos\n", inicio, fin, cantPrimos);
		printf("En el rango [%d,%d] hay %d números primos buenos\n", inicio, fin, cantPrimosBuenos);
		double porcentajeBuenos = ((double)cantPrimosBuenos/cantNum)*100;
		printf("El porcentaje de números primos buenos en el rango es %.2lf %", porcentajeBuenos);
		
	}
	
	return 0;
}

int validarPrimo(int num){
	int divisor=1, cantDiv=0;
	
	do{
		if (cantDiv%divisor==0){
			cantDiv++;
		}
		divisor++;
	} while divisor<=num;
	
	if (cantDiv=2){
		return 1;
	}
	else{
		return 0;
	}
}

int validarPrimoBueno(int num){
	
}
