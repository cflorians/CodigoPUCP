#include <stdio.h>

int main(){
	
	double a,b,c;
	double promedio, porcA;
	
	a = 15;
	b = 19;
	c = 16;
	
	promedio = (a+b+c)/3;
	porcA = (a*100)/(a+b+c);
	int total = a+b+c;
	
	printf("El promedio de los 3 números es %lf\n",promedio);
	printf("%1.lf corresponde al %1.lf%% de %d", a, porcA, total);
	
	return 0;
}

