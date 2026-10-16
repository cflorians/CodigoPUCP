#include <stdio.h>
#include <math.h>

int main(){
	
	double x, fx;
	
	printf("Ingrese el valor de x: \n");
	printf("> ");
	scanf("%lf", &x);
	
	if ( x <= -1 ){
		fx = fabs(pow(x,3));
	}
	else {
		if ( x <= 6 ){
			fx = pow(x,2)+4*x;
		}
		else {
			if ( x <= 14 ){
				fx = (pow(x,5)+5*x)/3;
			}
			else {
				fx = log(x)/log(5);
			}
		}
	}
	
	printf("F(%0.lf) = %lf", x, fx);
	
	return 0;
}
