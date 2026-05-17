#include <stdio.h>

int main(){
	
	int ladoAB, ladoBC, ladoAC, esTriangulo;
	
	ladoAB = 3;
	ladoBC = 3;
	ladoAC = 3;
	
	esTriangulo = ladoAB + ladoBC > ladoAC && 
		ladoAB + ladoAC > ladoBC && 
		ladoBC + ladoAC > ladoAB;
	printf("%d",esTriangulo);
	
	return 0;
	
}
