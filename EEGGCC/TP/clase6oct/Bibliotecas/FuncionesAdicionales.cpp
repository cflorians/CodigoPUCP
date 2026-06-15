//
// Created by carlo on 6/10/2025.
//
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

#include "FuncionesAdicionales.h"

void cargarArreglos(int* arrDni,int* arrFecha,double* arrDouble,int& cantDatos)
{
    int dia, mes, anio;
    char c;

    ifstream arch("ArchivosDeDatos/ejercicioClase.txt", ios::in);
    if (not arch.is_open())
    {
        cout << "Error al abrir el archivo de entrada." << endl;
        exit(1);
    }

    cantDatos = 0;

    while (arch >> arrDni[cantDatos])
    {
        while (arch.peek() == ' ') arch.get();
        while (arch.peek() != ' ') arch.get();

        arch >> dia >> c >> mes >> c >> anio;
        arrFecha[cantDatos] = anio*10000 + mes*100 + dia;

        arch >> arrDouble[cantDatos];

        cantDatos++;
    }
}

void imprimirReporteSimple(int* arrDni,int* arrFecha,double* arrDouble,int cantDatos)
{
    ofstream reporte("ArchivosDeReporte/ReporteSimple.txt", ios::out);\

    reporte << setw(6) << "DNI" << setw(10) << "FECHA" << setw(7) << "PAGO" << endl;
    for (int i = 0; i < cantDatos; i++)
    {
        reporte << arrDni[i] << ' ' << arrFecha[i] << ' ' << fixed <<
                setprecision(2) << arrDouble[i] << endl;
    }
}

void ordenarPorDni(int* arrDni,int* arrFecha,double* arrDouble,int cantDatos)
{
    int i=0, j=0, temp;
    double tempDouble;

    for (i=0;i<cantDatos-1;i++)
    {
        for (j=i+1;j<cantDatos;j++)
        {
            if (arrDni[i] > arrDni[j])
            {
                //intercambiar dnis
                temp = arrDni[i];
                arrDni[i] = arrDni[j];
                arrDni[j] = temp;
                //intercambiar fecha
                temp = arrFecha[i];
                arrFecha[i] = arrFecha[j];
                arrFecha[j] = temp;
                //intercambiar double
                tempDouble = arrDouble[i];
                arrDouble[i] = arrDouble[j];
                arrDouble[j] = tempDouble;
            }
        }
    }
}

void cargarArreglosOrdenado(int* arrDni,int* arrFecha,double* arrDouble,int& cantDatos)
{
    //para cargar arreglos en orden tenemos que:
    //obtener los datos
    //hallar la posicion de esos datos
    //desplazar todos los elementos que estan despues de esa posicion para poder insertarlo
    //dni nombre fecha pago
    int dia, mes, anio, dni, fecha, indice, i;
    char c;
    double pago;
    cantDatos = 0;
    ifstream arch("ArchivosDeDatos/ejercicioClase.txt", ios::in);

    while (arch >> dni)
    {
        indice=0;

        arch >> ws;
        while (arch.get()!=' ');

        arch >> dia >> c >> mes >> c >> anio;
        arch >> pago;
        fecha = anio*10000 + mes*100 + dia;

        //ahora buscamos la posicion de el dato por orden de dni
        i=cantDatos-1;
        while (i>=0 and arrDni[i]>dni)
        {
            arrDni[i+1] = arrDni[i];
            arrDouble[i+1] = arrDouble[i];
            arrFecha[i+1] = arrFecha[i];
            i--;
        }
        arrDni[i+1] = dni;
        arrDouble[i+1] = pago;
        arrFecha[i+1] = fecha;

        cantDatos++;
    }
}

void eliminarDelArreglo(int* arrDni,int* arrFecha,double* arrDouble,int& cantDatos, int dniAborrar)
{
    int i=0, j=0;

    for (i=0 ; i<cantDatos-1 ; i++)
    {
        if (arrDni[i] == dniAborrar)
        {
            for (j=i;j<cantDatos-1;j++)
            {
                arrDni[j] = arrDni[j+1];
                arrFecha[j] = arrFecha[j+1];
                arrDouble[j] = arrDouble[j+1];
            }
        }
    }
    cantDatos--;
}