#include <stdio.h>

int main(){
	
	double baseMenor, baseMayor, alturaTrapecio, alturaTriangulo;
	double areaTrapecio, areaTriangulo, areaPentagono;
	double areaTotal1, areaTotal2, areaTotal3;
	int areaMenor;
	
	baseMayor = 10.76;
	baseMenor = 5;
	alturaTrapecio = 4;
	alturaTriangulo = 3.75;
	
	areaTriangulo = (baseMenor*alturaTriangulo)/2;
	areaTrapecio = ((baseMayor+baseMenor)*alturaTrapecio)/2;
	areaPentagono = ((5*baseMayor)*(baseMayor/1.45))/2;
	
	areaTotal1 = areaTriangulo+areaTrapecio+areaPentagono;
	
	printf("El área de la figura 1 es: %lf\n", areaTotal1);
	printf("La cual esta compuesta por el area del triángulo: %lf\n",areaTriangulo);
	printf("La cual esta compuesta por el area del trapecio: %lf\n",areaTrapecio);
	printf("La cual esta compuesta por el area del pentágono : %lf\n",areaPentagono);
	
	baseMayor = 3.56;
	baseMenor = 2.6;
	alturaTrapecio = 8.5;
	alturaTriangulo = 1.76;
	
	areaTriangulo = (baseMenor*alturaTriangulo)/2;
	areaTrapecio = ((baseMayor+baseMenor)*alturaTrapecio)/2;
	areaPentagono = ((5*baseMayor)*(baseMayor/1.45))/2;
	
	areaTotal2 = areaTriangulo+areaTrapecio+areaPentagono;
	
	printf("El área de la figura 2 es: %lf\n", areaTotal2);
	printf("La cual esta compuesta por el area del triángulo: %lf\n",areaTriangulo);
	printf("La cual esta compuesta por el area del trapecio: %lf\n",areaTrapecio);
	printf("La cual esta compuesta por el area del pentágono : %lf\n",areaPentagono);
	
	baseMayor = 9.75;
	baseMenor = 3.56;
	alturaTrapecio = 2.3;
	alturaTriangulo = 0.56;
	
	areaTriangulo = (baseMenor*alturaTriangulo)/2;
	areaTrapecio = ((baseMayor+baseMenor)*alturaTrapecio)/2;
	areaPentagono = ((5*baseMayor)*(baseMayor/1.45))/2;
	
	areaTotal3 = areaTriangulo+areaTrapecio+areaPentagono;
	
	printf("El área de la figura 3 es: %lf\n", areaTotal3);
	printf("La cual esta compuesta por el area del triángulo: %lf\n",areaTriangulo);
	printf("La cual esta compuesta por el area del trapecio: %lf\n",areaTrapecio);
	printf("La cual esta compuesta por el area del pentágono : %lf\n",areaPentagono);
	
	areaMenor = (1*(areaTotal1<=areaTotal2&&areaTotal1<+areaTotal3)) +
				(2*(areaTotal2<=areaTotal1&&areaTotal2<+areaTotal3)) +
				(3*(areaTotal3<=areaTotal2&&areaTotal3<+areaTotal1));
				
	printf("La figura %d es la que tiene menor área", areaMenor);
	
	return 0;
}
