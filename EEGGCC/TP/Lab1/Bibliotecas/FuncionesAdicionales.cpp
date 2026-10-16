//
// Created by carlo on 4/09/2025.
//

#include "FuncionesAdicionales.h"

#include <iomanip>
#include <iostream>
using namespace std;

void mostrarFechaFormato(int dia, int mes, int anio)
{
    cout << setfill('0');
    cout << setw(2) << dia << "/" << setw(2) << mes << "/" << anio << endl;
    cout << setfill(' ');
}

void mostrarHoraFormato(int hora, int min, int seg)
{
    cout << setw(3) << ' ';
    cout << setfill('0');
    cout << setw(2) << hora << ":" << setw(2) << min << ":" << setw(2) << seg;
    cout << setfill(' ');
}

void separadorConCaracter(int ancho,char separador)
{
    cout << setfill(separador);
    cout << setw(ancho) << separador << endl;
    cout << setfill(' ');
}

void leerEscribirNombre(int &longitud)
{
    char letra;
    longitud = 0;
    cin >> letra;
    while (letra !=' ')
    {
        if (letra=='/' or letra=='-')
        {
            cout << ' ';
        }
        else{
            cout << letra;
        }
        longitud++;
        letra=cin.get();
    }
}

void mostrarPuntoLlegadaX_Y(int grad,int min,int seg, double dist)
{

}
