#include <stdio.h>
#include <math.h>

int validarNum(int );
int invertirNumeroDer(int );
int invertirNumeroIzq(int );

int main(){
	
	int num, bandera=1, nuevoNum=0, opcionIncorrecta=0;
	char sentido;
	
	do{
		printf("Ingrese un numero a invertir: ");
		scanf("%d", &num);
		
		switch (validarNum(num)){
			case 0:
				bandera=0;
				break;
			case 1:
				//hacemos la wbda
					printf("Seleccione si es por derecha (D,d) o por izquierda(I,i): ");
				do{
					scanf(" %c", &sentido);
					switch (sentido){
						case 'D':
						case 'd':
							nuevoNum=invertirNumeroDer(num);
							opcionIncorrecta=0;
							break;
						case 'I':
						case 'i':
							nuevoNum=invertirNumeroIzq(num);
							opcionIncorrecta=0;
							break;
						default:
							opcionIncorrecta=1;
							printf("Ingrese opcion valida\n");
					}
				} while (opcionIncorrecta==1);
				printf("El número invertido es: %d\n", nuevoNum);
				break;
			default:
				printf("El número ingresado debe ser positivo\n");
		}
	} while (bandera);
	
	return 0;
}

int validarNum(int num){
	if (0<num){
		return 1;
	}
	else{
		if (num<0){
			return 2;
		}
		else{
			return 0;
		}
	}
}

int invertirNumeroDer(int num){
	int digito, nuevo=0;
	do{
		digito=num%10;
		num/=10;
		nuevo=nuevo*10+digito;
	} while (num!=0);
	return nuevo;
}

int invertirNumeroIzq(int num){
	int digito, nuevo=0;
	int copia=num, cantDigitos=0;
	do{
		copia/=10;
		cantDigitos++;
	} while (0<copia);
	
	int i=1, suma=0;
	do{
		digito=num/pow(10,cantDigitos-i);
		num%=(int)pow(10,cantDigitos-i);
		
		if (i%2!=0){
			suma+=digito;
		}
		else{
			sumaPares
		}
		
		nuevo+=digito*(pow(10,i-1));
		i++;
	} while (num!=0);
	
	return nuevo;
}
