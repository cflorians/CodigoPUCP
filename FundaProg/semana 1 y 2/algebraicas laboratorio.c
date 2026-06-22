#include <stdio.h>

int main(){
	
	int a, b, c;
	int exp1, exp2, exp3;
	double idnt1, idnt2, idnt3;
	
	a = -1;
	b = 2;
	c = 1;
	
	exp1 = ((a*a*a)+(b*b*b)+(c*c*c)-3*a*b*c)==((a+b+c)*((a*a)+(b*b)+(c*c)-(a*b)-(b*c)-(a*c))) &&
			((a+b+c)*((a*a)+(b*b)+(c*c)-(a*b)-(b*c)-(a*c))==((a+b+c)*(((a-b)*(a-b))+((b-c)*(b-c))+((c-a)*(c-a)))/2));
	exp2 = ((a+b)*(b+c)*(c+a)+a*b*c)==((a+b+c)*(a*b+b*c+a*c));
	exp3 = ((a*b+b*c+c*a)*(a*b+b*c+c*a)==(a*a*b*b+a*a*c*c+b*b*c*c+2*a*b*c*(a+b+c)));
	
	idnt1 = ((a*a*a)+(b*b*b)+(c*c*c)-3*a*b*c);
	idnt2 = (a+b)*(b+c)*(c+a)+a*b*c;
	idnt3 = (a*b+b*c+c*a)*(a*b+b*c+c*a);

	printf("Las expresiones de la identidad 1 son iguales: %d\n", exp1);
	printf("Las expresiones de la identidad 2 son iguales: %d\n", exp2);
	printf("Las expresiones de la identidad 3 son iguales: %d\n", exp3);
	
	printf("La identidad 1 tiene como resultado: %lf\n",idnt1);
	printf("La identidad 2 tiene como resultado: %lf\n",idnt2);
	printf("La identidad 3 tiene como resultado: %lf\n",idnt3);
	
		
	return 0;
}
