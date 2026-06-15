#include <stdio.h>

int main(){
	
	double diametroCasquete, alturaCasquete, radioCasquete, volumenCasquete1, volumenCasquete2, diametroEsfera, radioEsfera, alturaCasqueteEnM;
	
	printf("Escenario 1: casquete esférico\n");
	printf("Ingrese el diámetro de la base del casquete en milímetros:\n");
	printf(">");
	scanf("%lf", &diametroCasquete);
	
	radioCasquete = diametroCasquete/2000;
	
	printf("Ingrese la altura del casquete en metros: \n");
	printf(">");
	scanf("%lf", &alturaCasquete);
	
	volumenCasquete1 = ((3.14*alturaCasquete)/6)*(3*radioCasquete*radioCasquete+alturaCasquete*alturaCasquete);
	
	printf("El casquete esférico tiene una altura de %.1f metros y el radio es %.4f metros\n", alturaCasquete, radioCasquete);
	printf("El volumen del casquete esférico es: %lf metros^3\n", volumenCasquete1);

	printf("Escenario 2: casquete esférico\n");
	printf("Ingrese el diámetro de la esfera en metros:\n");
	printf(">");
	scanf("%lf", &diametroEsfera);
	
	radioEsfera = diametroEsfera/2;
	
	printf("Ingrese la altura del casquete en centimetros: \n");
	printf(">");
	scanf("%lf", &alturaCasquete);
	
	alturaCasqueteEnM = alturaCasquete/100;
	
	volumenCasquete2 = ((3.14*alturaCasqueteEnM*alturaCasqueteEnM)/3)*(3*radioEsfera-alturaCasqueteEnM);
	
	printf("El casquete esférico tiene una altura de %.2f metros y el radio de la esfera es %.2f metros\n", alturaCasqueteEnM, radioEsfera);
	printf("El volumen del casquete esférico es: %lf metros^3\n", volumenCasquete2);
	
	printf("----------------------------------------------------------------------------------------------\n");
	
	int mayor1, mayor2;
	
	mayor1 = volumenCasquete1 > volumenCasquete2;
	mayor2 = volumenCasquete2 > volumenCasquete1;
	
	printf("El escenario 1 tiene mayor volumen que el escenario 2: %s\n", mayor1? "VERDADERO":"FALSO");
	printf("El escenario 2 tiene mayor volumen que el escenario 1: %s\n", mayor2? "VERDADERO":"FALSO");	
		
	return 0;
}
