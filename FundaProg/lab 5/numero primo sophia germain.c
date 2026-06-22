#include <stdio.h>
#include <math.h>

void calculoPrimosSophia(int ,double *, double *);
int verificarPrimo(int );

int main(){
	
	int numero, numero2;
	double valorC, conjetura;
	int verificar1, verificar2;
	
	printf("Ingrese el número: ");
	scanf("%d", &numero);
	
	if (0<numero){
		calculoPrimosSophia(numero, &valorC, &conjetura);
		printf("El valor de C es %lf y la conjetura: %lf\n", valorC, conjetura);
		verificar1=verificarPrimo(numero);
		numero2=2*numero+1;
		verificar2=verificarPrimo(numero2);
		if (verificar1){
			printf("El numero %d es primo\n", numero);
			if (verificar2){
				printf("El numero %d es primo\n", numero2);
				printf("El numero %d es un numero de Sophie Germain\n", numero);
			}
			else{
				printf("El numero %d es primo\n", numero);
				printf("El numero %d no es primo\n", numero);
			}
		}
		else{
			printf("El numero %d no es primo\n", numero);
		}
	}
	else{
		printf("El número es invalido\n");
	}
	
	return 0;
}

void calculoPrimosSophia(int numero,double *valorC, double *conjetura){
	double p=1;
	double total=1.0;
	double calculo;
	while (p<=numero){
		int verificarP=verificarPrimo(p);
		if (verificarP){
			calculo=(double)(p*(p-2))/pow(p-1,2);
		}
		total=total*calculo;
		p++;
	}
	*valorC=total;
	*conjetura=(2*(*valorC)*numero)/pow(log(numero),2);
}

int verificarPrimo(int n){
	if (n<2){
		return 0;
	}
	if (n==2){
		return 1;
	}
	if (n%2==0){
		return 0;
	}
	
	int i=3;
	int contador=0;
	while (i*i<=n){
		if (n%i==0){
			contador++;
		}
		i++;
	}
	if (2<contador){
		return 0;
	}
	else
		return 1;
}


