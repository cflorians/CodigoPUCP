#include <stdio.h>

int main(){
	
	int cantCaras, cantAristas, cantVertices, esPoliedroConvexo;
	
	cantCaras = 6;
	cantAristas = 9;
	cantVertices = 8;
	esPoliedroConvexo = cantCaras - cantAristas + cantVertices == 2;
	printf("%d",esPoliedroConvexo);
	
	return 0;
}
