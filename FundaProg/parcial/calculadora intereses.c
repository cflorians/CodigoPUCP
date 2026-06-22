#include <stdio.h>
#include <math.h>

int validarDatos(double, int);
double calcularCuotaMensual(double ,double ,double );
void calcularMontos(int ,double ,double ,double *,double *);

int main(){
	
	double capital, cuotas;
	double interes, cuotaMensual;
	double montoTotal, montoInteres;
	
	printf("Ingrese el monto del préstamo: ");
	scanf("%lf", &capital);
	printf("Ingrese el número de cuotas en las que solicita el préstamo: ");
	scanf("%lf", &cuotas);
	if (validarDatos(capital, cuotas)==1){
		if (capital<5000){
			if (cuotas==12){
				interes=0.0135;
			}
			else{
				if (cuotas==24){
					interes=0.0145;
				}
				else{
					interes=0.0155;
				}
			}
		}
		else{
			if (cuotas==12){
				interes=0.011;
				}
			else{
				if (cuotas==24){
					interes=0.012;
				}
				else{
					interes=0.013;
				}
			}
		}
		cuotaMensual=calcularCuotaMensual(capital, cuotas, interes);
		calcularMontos(cuotas, capital, cuotaMensual, &montoTotal, &montoInteres);
		printf("El monto de la cuota a pagar en 12 meses es: %lf\n", cuotaMensual);
		printf("El monto final que se pagara incluyendo intereses es: %lf\n", montoTotal);
		printf("El monto del interes pagado es %lf\n", montoInteres);
	}
	else{
		printf("Ingresó algún dato incorrecto");
	}
	return 0;
}

int validarDatos(double capital,int cuotas){
	if (0<capital &&(cuotas==12||cuotas==24||cuotas==36)){
		return 1;
	}
	else{
		return 0;
	}
}

double calcularCuotaMensual(double p,double n,double r){
	return (p*r*pow(1+r,n))/(pow(1+r,n)-1);
}

void calcularMontos(int cuotas,double capital,double cuotaMensual,double *montoTotal,double *montoInteres){
	*montoTotal=cuotaMensual*cuotas;
	*montoInteres=(*montoTotal)-capital;
}
