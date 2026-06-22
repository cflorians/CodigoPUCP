#include <stdio.h>

int main(){
	
	int anio, div4, div100, div400, esBisiesto;
	
	anio = 1600;
	
	div4 = anio - (anio/4)*4;
	div100 = anio - (anio/100)*100;
	div400 = anio - (anio/400)*400;
	
	esBisiesto = (div4 == 0 && (div100 != 0 || div400 ==0));
	printf("Es Bisiesto?: %d",esBisiesto);
	
	return 0;
	
}
