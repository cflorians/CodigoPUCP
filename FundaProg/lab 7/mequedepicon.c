#include <stdio.h>
#include <math.h>

int validarDatos(int , int , char , int );
int calcularCifras(int );
void rotarCifras(int ,int ,char ,int ,int ,int ,int *,int *);

int main(){
	
	int num1, num2, rotaciones, cifras1, cifras2, nuevoNum1, nuevoNum2;
	char orden;
	
	do{
		printf("Ingrese un par de números: ");
		scanf("%d %d", &num1, &num2);
		if (num1==0 && num2==0){
			break;
		}
		else{
			printf("Ingrese el sentido de rotación (I-Izquierda, D-Derecha): ");
			scanf(" %c", &orden);
			printf("Ingrese la cantidad de veces a rotar los dígitos: ");
			scanf("%d", &rotaciones);
			if (validarDatos(num1, num2, orden, rotaciones)){
				cifras1=calcularCifras(num1);
				cifras2=calcularCifras(num2);
				rotarCifras(num1, num2, orden, rotaciones, cifras1, cifras2, &nuevoNum1, &nuevoNum2);
				printf("Los números con los dígitos rotados %d veces son: %d %d\n", rotaciones, nuevoNum1, nuevoNum2);
			}
			else{
				printf("Alguno de los datos ingresados no son correctos\n");
				
			}
		}
	}while(1);
	
	return 0;
}

int validarDatos(int num1, int num2, char orden, int rotaciones){
	return 0<num1 && 0<num2 && 0<rotaciones && (orden=='D' || orden=='d' || orden=='I' || orden=='i');
}

int calcularCifras(int n){
	int cifras=0;
	
	do{
		n/=10;
		cifras++;
	}while(n!=0);
	
	return cifras;
}

void rotarCifras(int num1,int num2,char orden,int rotaciones,int cifras1,int cifras2,int *nuevoNum1,int *nuevoNum2){
	int i=1;
	
	if (1<rotaciones){
		int dig1, dig2;
		do{
			if (orden=='D'){
				dig1=num1%10;
				num1/=10;
				dig2=num2%10;
				num2/=10;
				
				num1+=dig2*pow(10,cifras1-1);
				num2+=dig1*pow(10,cifras2-1);
			}
			else{
				dig1=num1/pow(10,cifras1-1);
				num1=num1%(int)pow(10, cifras1-1);
				dig2=num2/pow(10,cifras2-1);
				num2=num2%(int)pow(10, cifras2-1);
				
				num1=num1*10+dig2;
				num2=num2*10+dig1;
			}
			i++;
		}while(i<=rotaciones);
	}
	else{
		
	}
	*nuevoNum1=num1;
	*nuevoNum2=num2;
}
