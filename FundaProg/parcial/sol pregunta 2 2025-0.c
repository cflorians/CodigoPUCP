#include <stdio.h>
#include <math.h>
#define DENSAIRE 1.225

int validarDatos(double ,double ,char );
void calcularRes_Ef_Aerodinamica(double ,double ,double ,double *,double *);
double calcularPotencia(double ,double );


int main(){
	
	int calcPotencia;
	double velocidad, area, coefArrastre;
	double resAerodinamica, efAerodinamica;
	char forma;
	
	printf("Ingrese la velocidad del objeto en km/h: ");
	scanf("%lf", &velocidad);
	printf("Ingrese el área frontal del objeto en cm^2: ");
	scanf("%lf", &area);
	printf("Ingrese la forma del objeto, (A)erodinamico, (P)rismatico, (I)rregular: ");
	scanf(" %c", &forma);
	if (validarDatos(velocidad, area, forma)){
		velocidad=velocidad/3.6;
		area=area/10000;
		if (forma=='A'){
			coefArrastre=0.1;
		}
		else{
			if (forma=='P'){
				coefArrastre=0.8;
			}
			else{
				coefArrastre=1.5;
			}
		}
		calcularRes_Ef_Aerodinamica(velocidad, area, coefArrastre,&resAerodinamica,&efAerodinamica);
		printf("¿Deseas calcular la potencia para vencer la resistencia aerodinámica? 1: Si, 0: No: ");
		scanf("%d", &calcPotencia);
		printf("\nRESULTADOS\n");
		printf("Fuerza de resistencia aerodinamica (N): %.2lf\n",resAerodinamica);
		if (calcPotencia){
			double potencia=calcularPotencia(resAerodinamica, velocidad);
			printf("Potencia necesaria (W): %.2lf\n",potencia);
		}
		printf("Eficiencia (N/m^2): %.2lf\n", efAerodinamica);
		if (efAerodinamica<100){
			printf("Muy eficiente aerodinámicamente\n");
		}
		else{
			if (efAerodinamica<500){
				printf("Moderadamente eficiente\n");
			}
			else{
				printf("Poco eficiente");
			}
		}
	}
	else{
		printf("Alguno de los datos ingresados no es correcto");
	}
	
	return 0;
}

int validarDatos(double velocidad,double area,char forma){
	return velocidad>0 && area>0 && (forma=='A' || forma=='P' || forma=='I');
	/*int validar=velocidad>0 && area>0 && (forma=='A' || forma=='B' || forma=='C');
	return validar */
}

void calcularRes_Ef_Aerodinamica(double velocidad,double area,double coefArrastre,double *resAerodinamica,double *efAerodinamica){
	*resAerodinamica=0.5*DENSAIRE*pow(velocidad,2)*coefArrastre*area;
	*efAerodinamica=(*resAerodinamica)/area;
}

double calcularPotencia(double resAerodinamica,double velocidad){
	return resAerodinamica*velocidad; 
}
