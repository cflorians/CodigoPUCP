#include <stdio.h>
#include <math.h>

int main(){
	
	double a, b, c ,d, discriminante;
	
	printf("Ingrese los valores de a, b, c y d respectivamente: \n");
	printf("a = ");
	scanf("%lf", &a);
	printf("b = ");
	scanf("%lf", &b);
	printf("c = ");
	scanf("%lf", &c);
	printf("d = ");
	scanf("%lf", &d);
	
	discriminante = 18*a*b*c*d - 4*pow(b,3)*d + pow(b,2)*pow(c,2) - 4*a*pow(c,3) - 27*pow(a,2)*pow(d,2);
	
	if (discriminante > 0){
		printf("La ecuación tiene 3 raíces reales distintas.");
	}
	else {
		printf("La ecuación no tiene 3 raíces reales distintas o no es cúbica.");
	}
	
	return 0;
}
