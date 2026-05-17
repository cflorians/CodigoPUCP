#include <stdio.h>

int main(){
	
	int numero, cantDigitos;
	int digito1, digito2, digito3, digito4, digito5;
	int sumaDigitos, multDigitosPares, digitoIzq, digitoDer, divisiblePorMultiplicacion; 
	double divDigitosImpares;
	
	printf("Ingrese el número y su cantidad de dígitos: ");
	scanf("%d %d", &numero, &cantDigitos);
	digito4=0;
	digito5=0;
	//verificación de la cantidad de digitos
	if (3 <= cantDigitos && cantDigitos <= 5){
		if (cantDigitos == 3 && 100<=numero && numero<1000){
			//3 digitos
			digito1 = numero%10;
			digito2 = (numero%100-digito1)/10;
			digito3 = (numero-digito2-digito1)/100;
			digitoIzq = digito3;
			
			multDigitosPares=digito2;		
		}
		else{
			if (cantDigitos == 4 && 1000<=numero && numero<10000){
				//4 digitos
				digito1 = numero%10;
				digito2 = (numero%100-digito1)/10;
				digito4 = (numero/1000);
				digito3 = numero/100-10*digito4;
				digitoIzq = digito4;
				
				multDigitosPares=digito2*digito4;
			}
			else{
				if (cantDigitos == 5 && 10000<=numero && numero<100000){
					//5 digitos
				}
			}
		}
	
		sumaDigitos = digito1+digito2+digito3+digito4+digito5;
		printf("La suma de los dígitos del numero es %d\n", sumaDigitos);
		
		digitoDer = digito1;
		
		int digitoIzqMasDer = digitoIzq+digitoDer;
		int divisiblePorSuma = numero%sumaDigitos==0;
		
		if (multDigitosPares==0){
			divisiblePorMultiplicacion = 0;
			printf("La multiplicación de los digitos pares es 0\n");
		}
		else{
			divisiblePorMultiplicacion = numero%multDigitosPares==0;
		}
		//div digitos
		if (cantDigitos<=4){
			if(digito1==0 || digito3==0){
				divDigitosImpares = 0;
				printf("Por lo menos uno de los digitos impares es 0, no se puede realizar la division\n");
			}
			else{
				divDigitosImpares=(double)digito1/digito3;
			}
		}
		else{
			if(digito1==0 || digito3==0 || digito5==0){
				divDigitosImpares=0;
				printf("Por lo menos uno de los digitos impares es 0, no se puede realizar la division\n");
			}
			else{
				divDigitosImpares=(double)digito1/digito3;
			}
		}
		printf("El digito de la derecha es %d\n", digitoDer);
		printf("El digito de la izquierda es %d\n", digitoIzq);
		
		int divisibleDigIzqSumaDer = numero%digitoIzqMasDer==0;
		
		if (divisiblePorSuma && divisiblePorMultiplicacion && divisibleDigIzqSumaDer){
			printf("El numero es divisible por la suma de sus digitos, por ")
		}
	} 
	else{
		printf("Datos incorrectos");
	}
	return 0;
}
