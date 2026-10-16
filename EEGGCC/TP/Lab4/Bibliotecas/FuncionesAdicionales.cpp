//
// Created by carlo on 28/09/2025.
//
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

#include "FuncionesAdicionales.h"
#define MAX_DIGITOS 50

void sumarNumerosMuyGrandes(int* numeroGrande1, int* numeroGrande2, int* totalGrande)
{
    int cantDigitos1, cantDigitos2, digitosTotal;
    ifstream arch("ArchivosDeDatos/NumerosASumar.txt", ios::in);
    if (not arch.is_open())
    {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }

    obtenerNumero(numeroGrande1, arch, cantDigitos1);
    while (arch.peek() != EOF)
    {
        obtenerNumero(numeroGrande2, arch, cantDigitos2);
        calcularTotal(numeroGrande1, cantDigitos1, numeroGrande2, cantDigitos2, totalGrande, digitosTotal);

        igualarArray(totalGrande, numeroGrande1, digitosTotal);
        cantDigitos1 = digitosTotal;
    }

    for (int i = digitosTotal-1; i >= 0; i--) {
        cout << totalGrande[i];
    }
}

void obtenerNumero(int *numero,ifstream &arch, int &cantDigitos)
{
    int i=0;
    cantDigitos=0;

    while (true)
    {
        arch >> numero[i];
        i++;
        cantDigitos++;
        if (arch.peek() == '\n' or arch.peek() == EOF)
        {
            break;
        }
    }
}

void calcularTotal(int *numero1, int cantDigitos1, int *numero2, int cantDigitos2, int *total, int &cantDigitostotal)
{
    int i=0, suma=0, excedente=0, dig1, dig2;
    cantDigitostotal=0;
    int pos1 = cantDigitos1-1;
    int pos2 = cantDigitos2-1;

    while (pos1 >= 0 or pos2 >= 0 or excedente>0)
    {
        if (pos1 >=0)
        {
            dig1 = numero1[pos1];
        }
        else
        {
            dig1=0;
        }
        if (pos2 >= 0)
        {
            dig2 = numero2[pos2];
        }
        else
        {
            dig2=0;
        }
        suma = dig1 + dig2 + excedente;
        excedente = suma/10;
        total[i] =  suma%10;

        i++;
        pos1--;
        pos2--;
    }
    cantDigitostotal = i;
}

void igualarArray(int *num1, int *num2, int cantDigitos)
{
    int i=0;
    for (i=0; i<cantDigitos; i++)
    {
        num2[i] = num1[i];
    }
}