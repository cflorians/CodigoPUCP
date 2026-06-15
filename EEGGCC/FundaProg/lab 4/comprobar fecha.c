#include <stdio.h>
#include <math.h>

int main(){
	
	int fecha, dia, mes, year, numeroDia, diasDelMes, contadorMes, diasTotales, bisciesto;
	int numeroSemana;
	char diaSemanaInicial;
	
	printf("Ingrese fecha [AAAAMMDD]: ");
	scanf(" %d", &fecha);
	printf("Dia de la semana que inicia el año: ");
	scanf(" %c", &diaSemanaInicial);
	
	dia = fecha%100;
	mes = (fecha/100)%100;
	year = fecha/10000;

	contadorMes = 1;
	diasTotales = 0;
	numeroSemana = 1;
	
	bisciesto = year%400 == 0 || year%4==0 && year%100!=0;
	
	int mesImpar = (contadorMes+1)%2;	
	if (mes==2){
		if (bisciesto == 1){
				diasDelMes=29;
		}
		else{
				diasDelMes=28;
		}
	}
	else{
		if(mes<=7){
			if(mesImpar == 1){
				diasDelMes=30;
			}
			else{
				diasDelMes=31;
			}
		}
		else{
			if(mes == 1){
				diasDelMes=31;
			}
			else{
				diasDelMes=30;
			}
		}
	}
	
	if(dia<=diasDelMes && mes<=12){
		if (year%400 == 0){
			bisciesto = 1;
		}
		else{
			if (year%4==0 && year%100!=0){
				bisciesto = 1;
			}
			else{
				bisciesto = 0;
			}
		}
 
		while (contadorMes < mes){
			int mesImpar = (contadorMes+1)%2;	
			if (contadorMes==2){
				if (bisciesto == 1){
						diasDelMes=29;
				}
				else{
						diasDelMes=28;
				}
			}
			else{
				if(contadorMes<=7){
					if(mesImpar == 1){
						diasDelMes=30;
					}
					else{
						diasDelMes=31;
					}
				}
				else{
					if(mesImpar == 1){
						diasDelMes=31;
					}
					else{
						diasDelMes=30;
					}
				}
			}
			printf("numero mes %d\n", contadorMes);
			printf("dias del mes %d\n", diasDelMes);
			diasTotales = diasTotales + diasDelMes;
			contadorMes++;
		}
		diasTotales = diasTotales + dia;
		printf("Dia del año: %d\n", diasTotales);
		while (diasTotales > 7){
			diasTotales = diasTotales-7;
			numeroSemana = numeroSemana + 1;
		}
		printf("Semana del año: %d", numeroSemana);
	}
	else{
		printf("Fecha incorrecta");
	}
	
	return 0;
}
