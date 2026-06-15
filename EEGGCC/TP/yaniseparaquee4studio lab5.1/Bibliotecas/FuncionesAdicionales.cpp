#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "FuncionesAdicionales.h"

void cargarProductos(int* codigo, double* precio, int &cantidad)
{
    int n;
    char c;
    ifstream arch("ArchivosDeDatos/ejercicio.txt", ios::in);
    if (not arch.is_open())
    {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }

    cantidad = 0;

    while (arch >> codigo[cantidad])
    {
        arch >> n >> c >> n >> c >> n;
        arch >> precio[cantidad];

        while (arch.peek() != '\n')
        {
            arch.get();
            if (arch.eof()) break;
        }

        cantidad++;
    }
}

void mostrarArreglos(int *codigo, double* precio, int cantidad)
{
    int i=0;

    for (i=0;i<cantidad;i++)
    {
        cout << codigo[i] << setw(8) << fixed << setprecision(2) << precio[i] << endl;
    }
}

void eliminarRepetidos(int *codigo, double* precio, int cantidad, int *codSinRep, double* precioSinRep, int &cantSinRep)
{
    int i=0, j=0, tempInt;
    double tempDouble;
    bool esDuplicado;

    codSinRep[0] = codigo[0];
    precioSinRep[0] = precio[0];
    cantSinRep = 1;

    for (i=1 ; i<cantidad ; i++)
    {
        esDuplicado = false;
        for (j=0 ; j<cantSinRep ; j++)
        {
            if (codigo[i] == codSinRep[j])
            {
                esDuplicado = true;
                break;
            }
        }
        if (not esDuplicado)
        {
            codSinRep[cantSinRep] = codigo[i];
            precioSinRep[cantSinRep] = precio[i];
            cantSinRep++;
        }
    }
}

void ordenarArreglo(int *codSinRep, double* precioSinRep, int cantSinRep)
{
    int i=0, j=0, tempInt;
    double tempDouble;

    for (i=0 ; i<cantSinRep-1 ; i++)
    {
        for (j=0 ; j<cantSinRep-i-1 ; j++)
        {
            if (codSinRep[j] > codSinRep[j+1])
            {
                tempInt = codSinRep[j];
                tempDouble = precioSinRep[j];
                codSinRep[j] = codSinRep[j+1];
                precioSinRep[j] = precioSinRep[j+1];
                codSinRep[j+1] = tempInt;
                precioSinRep[j+1] = tempDouble;
            }
        }
    }
}

void hallarMinYMax(double* precioSinRep, int cantSinRep, double &min, double &max)
{
    int i=0;

    min = INT_MAX;
    max = 0;

    for (i=0;i<cantSinRep;i++)
    {
        if (precioSinRep[i] < min) min = precioSinRep[i];
        if (precioSinRep[i] > max) max = precioSinRep[i];
    }
}

double buscadorPrecio(int codigoBuscado, int *codSinRep, double* precioSinRep, int cantSinRep)
{
    int i=0;

    for (i=0; i<cantSinRep ; i++)
    {
        if (codigoBuscado == codSinRep[i])
        {
            return precioSinRep[i];
        }
    }
    return -1;
}