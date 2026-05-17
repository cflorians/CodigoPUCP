#include <stdio.h>

int main(){
	
	int a, b, c; 
	double promedio, porcentaje;

	a = 15;
	b = 19;
	c = 16;
	
	promedio = (a+b+c)/3;
	porcentaje = (a*100)/(a+b+c);
	
	printf("El promedio de los 3 números es %lf\n",promedio);
	printf("%d corresponde al %lf% %\n",a,porcentaje);
	
	return 0;
}
