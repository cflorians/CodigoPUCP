#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "funciones.h"

void leerDatosExactos(int*& datos,int& numDatos, const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    int buffer[100];
    int dato;
    numDatos = 0;
    while (true) {
        arch >> dato;
        buffer[numDatos] = dato;
        numDatos++;
        if (arch.eof()) break;
    }

    // ahora que tenemos el numero de datos, asignamos la memoria exacta
    datos = new int[numDatos];
    for (int i=0; i < numDatos; i++) datos[i] = buffer[i];
}

void imprimirDatos(int* datos,int numDatos, const char* nombArch) {
    ofstream reporte(nombArch, ios::out);
    if (not reporte.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    for (int i=0; i < numDatos; i++) reporte << datos[i] << endl;
}

void leerDatosExactos(int*& datos, const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    int buffer[100];
    int dato;
    int numDatos = 0;
    while (true) {
        arch >> dato;
        buffer[numDatos] = dato;
        numDatos++;
        if (arch.eof()) break;
    }

    datos = new int[numDatos+1]{};
    for (int i=0; i < numDatos; i++) datos[i] = buffer[i];
    // si es que en los datos hay un 0:     datos[numDatos] = -1;
}

void imprimirDatos(int* datos, const char* nombArch) {
    ofstream reporte(nombArch, ios::out);
    if (not reporte.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    for (int i=0; datos[i] != -1; i++) reporte << datos[i] << endl;
}
