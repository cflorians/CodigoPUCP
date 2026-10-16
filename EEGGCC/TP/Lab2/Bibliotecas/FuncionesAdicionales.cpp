//
// Created by carlo on 15/09/2025.
//

#include "FuncionesAdicionales.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void verificarApertura(ifstream &archDatos, ofstream &archReporte)
{
    if (not archDatos.is_open())
    {
        cout << "Error al abrir el archivo de datos" << "ArchivosDeDatos/datos.txt" << endl;
        exit(1);
    }
    if (not archReporte.is_open())
    {
        cout << "Error al abrir el archivo de reporte" << "ArchivosDeReporte/reporte.txt" << endl;
        exit(1);
    }
}

void mostrarNombre(ifstream &entrada, ofstream &salida)
{
    char c;
    int longitud=0;
    entrada.get(c);
    while (c != ']' and c != '\n' and not entrada.eof())
    {
        if (c == '/' or c=='_')
        {
            c = ' ';
        }
        salida.put(c);
        entrada.get(c);
        longitud ++;
    }
    salida << setw(36-longitud) << ' ';
    saltarEspacios(entrada, salida);
}

void saltarEspacios(ifstream &entrada, ofstream &salida)
{
    char c;
    while (entrada.peek() == ' ' or entrada.peek() == '\n' and not entrada.eof())
    {
        entrada.get(c);
    }
    salida << " ";
}

void leerNumero(ifstream &entrada, ofstream &salida)
{
    int longitud=0, cantDecimales=0;
    double numEnt=0, numDec=0, numero=0;
    bool parteEntera=true;
    char n;
    while (entrada.peek() != ' ' and entrada.peek() != '\n' and not entrada.eof() or n == '.')
    {
        entrada.get(n);
        if (n=='.')
        {
            parteEntera=false;
        }

        if (parteEntera and n!=' ')
        {
            numEnt = numEnt*10 + (n-'0');
        }
        else if (n!=' ' and n!='.')
        {
            numDec = numDec*10 + (n-'0');
            cantDecimales++;
        }

        longitud++;
    }
    numero = numEnt + numDec/pow(10,cantDecimales);
    if (parteEntera)
    {
        salida << fixed << setprecision(0) << setw(6) << numero;
    }
    else
    {
        salida << fixed << setprecision(2) << setw(6) << numero;
    }
    salida << ' ';
    saltarEspacios(entrada, salida);
}
