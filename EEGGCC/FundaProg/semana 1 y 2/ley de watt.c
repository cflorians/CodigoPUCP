#include <stdio.h>

int main(){
	
	double resElectrica1, corriente1, corrienteA, motor1;
	double voltaje2, voltajeV, resElectrica2, resElectricaOm, motor2;
	int potenciaMenor1, potenciaMenor2;
	
	printf("Escenario 1, con datos de resistencia y corriente: \n");
	printf("Ingrese la resistencia eléctrica en ohmios: \n");
	printf("> ");
	scanf("%lf", &resElectrica1);
	printf("Ingrese la corriente en miliamperios:\n");
	printf("> ");
	scanf("%lf", &corriente1);
	
	corrienteA = corriente1/1000;
	
	motor1 = (resElectrica1*(corrienteA*corrienteA))/1000;
	printf("El motor del escenario 1, con resistencia de %lf ohmios y corriente de %lf A es: \n %lf \n", resElectrica1, corrienteA, motor1);
	
	printf("Escenario 2, con datos de voltaje y resistencia: \n");
	printf("Ingrese el voltaje en decivoltios: \n");
	printf("> ");
	scanf("%lf", &voltaje2);
	printf("Ingrese la resistencia en kiloohmios:\n");
	printf("> ");
	scanf("%lf", &resElectrica2);
	
	voltajeV = voltaje2/10;
	resElectricaOm = resElectrica2*1000;
	
	motor2 = ((voltajeV*voltajeV)/resElectricaOm)/1000;
	printf("El motor del escenario 2, con resistencia de %lf ohmios y voltaje de %lf V es:\n %lf\n", resElectricaOm, voltajeV, motor2);
	
	potenciaMenor1 = motor1 <= motor2;
	potenciaMenor2 = motor2 <= motor1;
	
	printf("El motor del escenario 1 tiene menor o igual potencia que el del escenario 2 : %s\n", potenciaMenor1 ? "VERDADERO": "FALSO");
	printf("El motor del escenario 2 tiene menor o igual potencia que el del escenario 1 : %s\n", potenciaMenor2 ? "VERDADERO": "FALSO");
	
	return 0;
}
