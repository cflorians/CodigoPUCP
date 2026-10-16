#include <stdio.h>

int main(){
	
	int a,b,c, solCompleja;
	
	a = 2;
	b = 4;
	c = 17;
	solCompleja = b*b - 4*a*c < 0;
	printf("%d",solCompleja);
	
	return 0;
}
