#include <stdio.h>

int main(){
	
	int angA, angB, angC, angD, esCuadrilatero;
	
	angA = 90;
	angB = 30;
	angC = 90;
	angD = 90;
	esCuadrilatero = angA + angB + angC + angD == 360;
	printf("%d",esCuadrilatero);
	
	return 0;
}
