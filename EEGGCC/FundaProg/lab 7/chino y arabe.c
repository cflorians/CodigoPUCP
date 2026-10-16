#include <stdio.h>

int validarOpcion(char );
int calcularValorCaracter(char );
void calcularNumeracionChina(int , int ,int *,int *);
void calcularNumeracionEgipcia(int ,int *);

int main(){
	
	char opcion, caracter;
	int numDecimal=0, valorCaracter, valorAnterior;
	int i=1;
	
	printf("Menú de opciones: \n");
	printf("C: Sistema de numeración chino.\nE: Sistema de numeración egipcio.\n");
	printf("Ingrese una opción:\n");
	scanf(" %c", &opcion);
	
	if(validarOpcion(opcion)){
		printf("\nIngrese los caracteres del sistema ");
		if (opcion=='C'){
			printf("chino: \n");
		}
		else{
			printf("egipcio: \n");
		}
		do {
			scanf(" %c", &caracter);
			valorCaracter=calcularValorCaracter(caracter);
			if (opcion=='C' && caracter!='Z'){
				calcularNumeracionChina(valorCaracter, i, &valorAnterior, &numDecimal);
				i++;
			}
			else{
				if (caracter!='Z')
					calcularNumeracionEgipcia(valorCaracter, &numDecimal);
			}
			if (caracter=='Z'){
				i--;
				if (i%2!=0){
					numDecimal+=valorAnterior;	
				}
				break;
			}
		} while(caracter!='Z');
		printf("El número es %d ", numDecimal);
		if (opcion=='C'){
			printf("y en el sistema de numeración china tiene %d cifras", i);
		}
	}
	else{
		printf("Opción inválida");
	}
	
	return 0;
}

int validarOpcion(char opcion){
	return opcion=='C' || opcion=='E';
}

int calcularValorCaracter(char caracter){
	if (caracter=='A'){
		return 1;
	}
	else{
		if (caracter=='B'){
			return 2;
		}
		else{
			if (caracter=='C'){
				return 3;
			}
			else{
				if (caracter=='D'){
					return 4;
				}
				else{
					if (caracter=='E'){
						return 5;
					}
					else{
						if (caracter=='F'){
							return 6;
						}
						else{
							if (caracter=='G'){
								return 7;
							}
							else{
								if (caracter=='H'){
									return 8;
								}
								else{
									if (caracter=='I'){
										return 9;
									}
									else{
										if (caracter=='J'){
											return 10;
										}
										else{
											if (caracter=='K'){
												return 100;
											}
											else{
												if (caracter=='L'){
													return 1000;
												}
												else{
													if (caracter=='M'){
														return 10000;
													}
													else{
														if (caracter=='N'){
															return 100000;
														}
														else{
															return 1000000;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void calcularNumeracionChina(int valorCaracter, int i, int *valorAnterior, int *numDecimal){
	if (i%2==0){
		*numDecimal+=(*valorAnterior)*(valorCaracter);
	}
	else{
		*valorAnterior=valorCaracter;
	}
}

void calcularNumeracionEgipcia(int valorCaracter,int *numDecimal){
	*numDecimal+=valorCaracter;
}
