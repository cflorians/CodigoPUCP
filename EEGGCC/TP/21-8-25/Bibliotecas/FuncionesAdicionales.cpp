//
// Created by carlo on 21/08/2025.
//

#include "FuncionesAdicionales.h"

int validarEsCircuitoSerieParalelo (char tipo)
{
    return (tipo == 'A' || tipo == 'a' || tipo == 'B' || tipo == 'b');

}

double calcularVoltaje (double corriente, double resistencia)
{
    return (corriente * resistencia);
}

void calcularIntensidadParalelo (double voltaje, double resistencia1,
    double resistencia2, double *rTotal, double *corriente,
    double *corriente1, double *corriente2)
{
    (*rTotal) = (resistencia1 * resistencia2)/(resistencia1 + resistencia2);
    (*corriente) = voltaje / (*rTotal);
    (*corriente1) = voltaje/resistencia1;
    (*corriente2) = voltaje/resistencia2;
}