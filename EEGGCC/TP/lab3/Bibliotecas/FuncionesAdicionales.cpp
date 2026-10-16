//
// Created by carlo on 18/09/2025.
//

#include "FuncionesAdicionales.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

void leerTexto(ifstream &entrada, ofstream &salida)
{
    char c;

    saltarEspacios(entrada);
    salida << ' ';

    entrada.get(c);
    while (c != ' ' and c != '\n' and !entrada.eof())
    {
        salida << c;
        entrada.get(c);
    }
}

void saltarEspacios(ifstream &entrada)
{
    char c;
    while (entrada.peek() == ' ')
    {
        entrada.get(c);
    }
}

void obtenerDnis(int codPais, int &dni, int &edad, ifstream &entrada, ofstream &salida)
{
    ifstream dnis("ArchivosDeDatos/dni_personas.txt", ios::in);

    int codActual;

    dnis >> codActual;
    if (codActual == codPais)
    {
        while (dnis.peek() != '\n' and !dnis.eof())
        {
            dnis >> dni;
            dnis >> edad;

        }
    }
}

void buscarPersona(int dni, int &dia, int &mes, int &agno, ifstream &entrada, ofstream &salida)
{
    ifstream personas("ArchivosDeDatos/dni_personas.txt", ios::in);

}