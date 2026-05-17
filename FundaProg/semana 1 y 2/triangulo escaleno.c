#include <stdio.h>

int main(){
	
	int ladoAB, ladoBC, ladoAC, trianguloEscaleno;
	ladoAB = 3;
	ladoBC = 3;
	ladoAC = 8;
	trianguloEscaleno = ladoAB != ladoBC && ladoBC != ladoAC && ladoAB != ladoAC ;
	printf("%d",trianguloEscaleno);
	
	return 0;
	
}
