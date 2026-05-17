#include <stdio.h>
#include <math.h>

int verificarBase(int ,int );
int cantCifras(int );
void calcularDivisoresPrimos(int ,int ,int *,int *,int *);
int verificarPrimo(int );

int main(){
	
	int num, base, div1=1, div2=1, div3=1;
	
	printf("Ingrese el número a encontrar: ");
	scanf("%d", &num);
	printf("Ingrese la base: ");
	scanf("%d", &base);
	
	if (0<num && verificarBase(num,base)){
		if (3<=cantCifras(num) && 3<=base && base<=10){
			printf("La cantidad de cifras que tiene el número %d es: %d\n", num, cantCifras(num));
			int i=0;
			do{
				calcularDivisoresPrimos(num, base, &div1, &div2, &div3);
				printf("%d x %d x %d = %d\n", div1, div2, div3, num);
				i++;
			}while(i<6);
		}
		else{
			if (base<3 || 10<base){
				printf("La base ingresada no es correcta\n");			
			}
			else{
				printf("La cantidad de cifras del número debe ser mayor o igual que 3\n");
			}
		}
	}
	else{
		printf("El número debe ser mayor que cero y/o encontrarse en la base indicada.\n");
	}
	
	return 0;
}

int verificarBase(int num,int base){
	int dig, baseValida=1;
	
	do{
		dig=num%10;
		if (base<=dig){
			baseValida=0;
		}
		num/=10;
	}while(1<num);
	
	return baseValida;
}

int cantCifras(int num){
	int cifras=0;
	
	do{
		num/=10;
		cifras++;
	}while(1<=num);
	
	return cifras;
}

void calcularDivisoresPrimos(int num,int base,int *div1,int *div2,int *div3){
	int i=1, divisor=2;
	do{
		if (verificarPrimo(divisor) && verificarBase(divisor, base) && num%divisor==0){
			num/=divisor;
			if (i==1){
				*div1=divisor;
			}
			else{
				*div2=divisor;
				*div3=num;
			}
			i++;
		}
		divisor++;
	}while(i<=3 && num>1 && divisor<num);
}

int verificarPrimo(int num){
	int i=1, divisores=0;
	
	do{
		if (num%i==0){
			divisores++;
		}
		i++;
	}while(i<=num);
	
	if (divisores==2){
		return 1;
	}
	else{
		return 0;
	}
}
