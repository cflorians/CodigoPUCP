#include <stdio.h>

int main(){
	
	double ladoAB, ladoBC, ladoCD, ladoDA;
	double anguloA, anguloB, anguloC, anguloD;
	int esCuadrado, esRectangulo, esRombo, esRomboide;
	
	ladoAB = 2.2;
	ladoBC = 2.2;
	ladoCD = 2.2;
	ladoDA = 2.2;
	
	anguloA = 80.5;
	anguloB = 99.5;
	anguloC = 80.5;
	anguloD = 99.5;
	
	esCuadrado = ladoAB == ladoBC &&
		ladoBC == ladoCD &&
		ladoCD == ladoDA &&
		anguloA == anguloB &&
		anguloB == anguloC &&
		anguloC == anguloD &&
		anguloD == 90;
	printf("Es cuadrado?: %d  ",esCuadrado);
	
	esRectangulo =  ladoAB == ladoCD &&
		ladoBC == ladoDA &&
		ladoAB != ladoBC &&
		anguloA == anguloB &&
		anguloB == anguloC &&
		anguloC == anguloD &&
		anguloD == 90;
	printf("Es Rectangulo?: %d  ",esRectangulo);

	esRombo = ladoAB == ladoBC &&
		ladoBC == ladoCD &&
		ladoCD == ladoDA &&
		anguloA == anguloC &&
		anguloB == anguloD &&
		(anguloA < 90 && anguloB > 90 || anguloA >90 && anguloB < 90);
	printf("Es Rombo?: %d  ",esRombo);

	esRomboide =  ladoAB == ladoCD &&
		ladoBC == ladoDA &&
		ladoAB != ladoBC &&
		ladoCD != ladoDA &&
		anguloA == anguloB &&
		anguloA == anguloC &&
		anguloB == anguloD &&
		anguloA < 90 && anguloB > 90 ||
		anguloA >90 && anguloB < 90;
	printf("Es Romboide?: %d  ",esRomboide);

	return 0;
}
