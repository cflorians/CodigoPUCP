#include <stdio.h>
#include <math.h>

void leer_datos(int *);
int cant_digitos(int );
int es_feliz(int );
int es_primo(int );
int sum_digits_al_cuadrado(int );

int main(){
	
	int numero;
	
	printf("Ingrese el numero a evaluar: ");
	leer_datos(&numero);
	if (cant_digitos(numero)==2){
		if (es_feliz(numero)){
			if (es_primo(numero)){
				printf("Es un primo feliz");
			}
			else{
				printf("Es un feliz");
			}
		}
		else{
			if (es_primo(numero)){
				printf("Es primo infeliz");
			}
			else{
				printf("Es un infeliz");
			}
		}
	}
	else{
		printf("El número debe ser de 2 digitos");
	}
	
	return 0;
}

void leer_datos(int *numero){
	scanf("%d", numero);
}

int cant_digitos(int numero){
	if (numero-10<0){
		return 1;
	}
	else{
		if (numero-100<0){
			return 2;
		}
		else{
			return 3;
		}
	}
}

int es_feliz(int numero){
	int i=1;
	int n=numero;
	while (i<=8){
		n=sum_digits_al_cuadrado(n);
		i++;
	}
	if (n==1){
		return 1;
	}
	else{
		return 0;
	}
}

int es_primo(int numero){
	int i=1;
	int cantDivisores=0;
	while (i<=numero){
		if (numero%i==0){
			cantDivisores++;
		}
		i++;
	}
	if (cantDivisores==2){
		return 1;
	}
	else{
		return 0;
	}
}

int sum_digits_al_cuadrado(int n){
	int i=1;
	/*j lo usamos para no alterar el valor del n inicial*/
	int j=n;
	int cifra;
	int suma=0;
	while (i<=cant_digitos(n)){
		printf("num iteracion: %d\n", i);
		cifra=j%10;
		printf("cifra: %d\n", cifra);
		j=(j-cifra)/10;
		printf("j: %d\n", j);
		/*suma=suma+*/
		suma+=pow(cifra,2);
		printf("suma: %d\n", suma);
		i++;
	}
	return suma;
}
