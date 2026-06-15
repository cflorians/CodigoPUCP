//
// Created by carlo on 21/08/2025.
//

#include "FuncionesAuxiliares.h"

int validarOpcion(int opcion)
{
    return (opcion=='A' or opcion == 'a' or opcion == 'B' or opcion == 'b' or opcion == 'C' or opcion == 'c');
}

double calcularVoltaje(double R,double I)
{
    return R*I;
}

void calcularResistenciaIntesidades(double voltaje,double resistencia1,double resistencia2,
    double *rTotal,double* corriente, double* corriente1,double *corriente2)
{
    *rTotal=(resistencia1 * resistencia2)/(resistencia1 + resistencia2);
    *corriente1 = voltaje/resistencia1;
    *corriente2 = voltaje/resistencia2;
    *corriente = (*corriente1 + *corriente2);
}