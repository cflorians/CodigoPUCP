#include <stdio.h>

int main(){
	
	int a, b, primEc, segEc, terEc, resultado;
	
	printf("Ingrese a y b:\n> ");
	scanf("%d", &a);
	printf("> ");
	scanf("%d", &b);
	
	printf("El resultado de a=%d^4, b=%d^4 es:\n", a, b);
	
	primEc = (a*a*a*a)+(b*b*b*b);
	segEc = (a+b)*(a-b)*(((a+b)*(a+b))-2*a*b)+2*(b*b*b*b);
	terEc = ((((a+b)*(a+b))-2*(a*b))*(((a+b)*(a+b))-2*(a*b)))-2*((a*b)*(a*b));
	
	printf("De acuerdo a la primera ecuación: %d\n",primEc);
	printf("De acuerdo a la segunda ecuación: %d\n",segEc);
	printf("De acuerdo a la tercera ecuación: %d\n",terEc);
	
	resultado = primEc==segEc&&segEc==terEc;
	
	printf("Las tres ecuaciónes son iguales: %s\n",resultado ? "Hola Fundamentos de Programacion" : "Falso");
	
	return 0;
}
