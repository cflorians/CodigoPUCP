#include <stdio.h>
#include <math.h>

int validarDatos(double ,double ,double ,char);
void calcularPorcentajeGrasa(double ,double ,double ,double *,double *);
double calcularPorcentajeGrasaSiri(double );

int main(){
	
	double peso, talla, edad, imc, porcentajeGrasa, volumen, porcGrasaSiri, densidadCorporal;
	char atleta, formSiri;
	
	printf("Ingrese su peso (Kg), talla (metros) y edad: ");
	scanf("%lf %lf %lf", &peso, &talla, &edad);
	printf("Ingrese (S,s: atleta), (N,n: no atleta): ");
	scanf(" %c", &atleta);
	if (validarDatos(peso, talla, edad, atleta)){
		calcularPorcentajeGrasa(peso, talla, edad, &imc, &porcentajeGrasa);
		printf("Su índice de masa corporal es %lf\n", imc);
		printf("Su porcentaje de grasa corporal es %lf\n", porcentajeGrasa);
		printf("Si desea calcular el porcentaje de grasa corporal usando la fórmula de Siri ingrese S o s: ");
		scanf(" %c", &formSiri);
		if (formSiri=='S'||formSiri=='s'){
			printf("Ingrese su volumen corporal (litros)");
			scanf("%lf", &volumen);
			densidadCorporal=peso/volumen;
			porcGrasaSiri=calcularPorcentajeGrasaSiri(densidadCorporal);
			printf("Su porcentaje de grasa corporal usando la fórmula de Siri es: %lf\n", porcGrasaSiri);
		}
		else{
			printf("No se solicitó calcular el porcentaje de grasa corporal usando la fórmula de Siri");
		}
	}
	else{
		printf("Alguno de los valores ingresados es incorrecto");
	}
	return 0;
}

int validarDatos(double peso,double talla,double edad, char atleta){
	return 0<peso && 20<=edad && edad<=39 && 0<talla && (atleta=='S'||atleta=='s'||atleta=='N'||atleta=='n');
}

void calcularPorcentajeGrasa(double peso,double talla,double edad,double *imc,double *porcentajeGrasa){
	*imc=peso/pow(talla,2);
	*porcentajeGrasa=(1.2*(*imc))+(0.23*edad)-16.2;
}

double calcularPorcentajeGrasaSiri(double densidadCorporal){
	return ((4.95/densidadCorporal)-4.5)*100;
}
