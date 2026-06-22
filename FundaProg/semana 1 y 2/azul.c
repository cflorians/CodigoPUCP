#include <stdio.h>

int main(){
	
	int longitud_de_onda, esAzul;
	
	longitud_de_onda = 470;
	esAzul = longitud_de_onda >= 460 && longitud_de_onda <= 482;
	printf("%d",esAzul);
	
	return 0;
}
