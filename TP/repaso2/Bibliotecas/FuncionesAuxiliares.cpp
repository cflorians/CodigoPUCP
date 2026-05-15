//
// Created by carlo on 30/08/2025.
//

#include "FuncionesAuxiliares.h"
#include <cmath>

int transfomrarFormato(int frec, int canales, int bits, int duracion)
{
    int resultado;

    transformarBinario(frec);

    return resultado;
}

double transformarBinario(int n)
{
    double resto, i=0;
    double binario=0.0;

    do
    {
        resto = n%2;
        n = n/2;
        binario += resto*pow(10,i);

        i++;
    }   while (0<n);

    return binario;
}

double transformarBaseDiez(double n)
{
    double i=0.0, resultado=0.0;
    int digito;
    do
    {
        digito = (int)n%10;
        n = n/10;
        resultado += digito*pow(2,i);

        i++;
    }   while (0<n);

    return resultado;
}