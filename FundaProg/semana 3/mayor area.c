#include <stdio.h>
#include <math.h>

#define PI 3.14

int main(){
	
	double a, b, c, l;
	double areaT, areaH;
	
	printf("Ingrese los lados a, b y c del triangulo: \n");
	printf("a = ");
	scanf("%lf", &a);
	printf("b = ");
	scanf("%lf", &b);
	printf("c = ");
	scanf("%lf", &c);
	printf("Ingrese el lado del hexagono regular: \n");
	printf("l = ");
	scanf("%lf", &l);
	
	double s = (a+b+c)/2;
	areaT = sqrt(s*(s-a)*(s-b)*(s-c));
	
	areaH = (3*pow(l,2))/(2*tan(PI/6));
	
	if (areaT > areaH){
		printf("El triángulo posee mayor área");
	}
	else{
		printf("El hexágono posee mayor área");
	}
	return 0;
}
