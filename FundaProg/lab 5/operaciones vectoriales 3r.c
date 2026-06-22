#include <stdio.h>

void leerDatos(int *, int *);
void operacionesVectoriales(int cantOperaciones, char operacion, double x1, double x2, double y1, double y2, double z1, double z2, int);


int main(){
	
	int cantOperaciones, cantDimensiones;
	char operacion;
	double x1, y1, z1, x2, y2, z2;
	double xR, yR, zR;
	int resultado;
	
	leerDatos(&cantOperaciones, &cantDimensiones);
	
	if (cantOperaciones>0 && cantDimensiones==3){	
		int i=1;
		while (i<=cantOperaciones){
			printf("Ingrese la operación a realizar entre los vectores tridimensionales: ");
			scanf(" %c", &operacion);
			printf("Ingrese las coordenadas del primer vector: ");
			scanf("%lf %lf %lf", &x1, &y1, &z1);
			printf("Ingrese las coordenadas del segundo vector: ");
			scanf("%lf %lf %lf", &x2, &y2, &z2);
			operacionesVectoriales(cantOperaciones, operacion, x1, x2, y1, y2, z1, z2, i );
			i++;
		}
	}
	else {
		printf("Debe ingresar una cantidad válida\n");
	}
	
	return 0;
}

void leerDatos(int *cantOperaciones, int *cantDimensiones){
	printf("Ingrese la cantidad de operaciones a realizar con los vectores: ");
	scanf("%d", cantOperaciones);
	printf("Ingrese la cantidad de dimensiones: ");
	scanf("%d", cantDimensiones);
}

void operacionesVectoriales(int cantOperaciones, char operacion, double x1, double x2, double y1, double y2, double z1, double z2, int i){
	
	int tipoMultiplicacion;
	double xR, yR, zR;
	int bandera = 1;
	
	if (operacion=='-'){
		xR = x1 - x2;
		yR = y1 - y2;
		zR = z1 - z2;
	}
	else{
		if (operacion=='+'){
			xR = x1 + x2;
			yR = y1 + y2;
			zR = z1 + z2;
		}
		else{
			if (operacion=='*'){
				printf("Ingrese el tipo de multiplicación a calcular: ");
				scanf("%d", &tipoMultiplicacion);
				if(tipoMultiplicacion==1){
					int resultado = x1*x2 + y1*y2 + z1*z2;
					bandera = 0;
					printf("Producto escalar: (%.2lf, %.2lf, %.2lf) * (%.2lf, %.2lf, %.2lf) = %lf\n", x1,y1,z1, x2,y2,z2, resultado);
				}
				else{
					if (tipoMultiplicacion==2){
						xR = y1*z2 - y2*z1;
						yR = -(x1*z2 - x2*z1);
						zR = x1*y2 - x2*y1;
						printf("Producto vectorial: ");
					}
					else{
						printf("El tipo de multiplicación debe ser 1 o 2\n");
						i=i-1;
					}
				}
			}
			else{
				printf("Ingrese un tipo de multiplicación valida\n");
				i=i-1;
			}
		}
	}
	if (bandera==1){
		printf("(%.2lf, %.2lf, %.2lf) %c (%.2lf, %.2lf, %.2lf) = (%.2lf, %.2lf, %.2lf)\n", x1, y1, z1, operacion, x2, y2, z2, xR, yR, zR);
	}
}

	


