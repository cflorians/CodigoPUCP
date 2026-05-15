#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#include "funciones.h"

#define INCREMENTO 5

void leerDatosPorIncrementos(int*& datos,int& numDatos, const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    int capacidad = 0;
    int dato;
    datos = nullptr;
    numDatos = 0;

    while (true) {
        arch >> dato;
        if (capacidad == numDatos) incrementarLosEspacios(datos, numDatos, capacidad);
        datos[numDatos] = dato;
        numDatos++;
        if (arch.eof()) break;
    }
}

void incrementarLosEspacios(int*& datos,int numDatos,int& capacidad) {
    int* aux;
    capacidad += INCREMENTO;
    if (datos == nullptr) {
        datos = new int[capacidad]{};
    }
    else {
        aux = new int[capacidad];
        for (int i = 0; i < numDatos; i++) {
            aux[i] = datos[i];
        }
        delete datos;
        datos = aux;
    }
}

void leerDatosPorIncrementos(int*& datos, const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    int capacidad = 0;
    int dato;
    int numDatos = 0;
    datos = nullptr;
    while (true) {
        arch >> dato;
        if (arch.eof()) break;
        if (capacidad == numDatos) incrementarLosEspaciosSin(datos, numDatos, capacidad);
        datos[numDatos-1] = dato; // para comenzar numDatos = 1
        numDatos++;
    }
}

void incrementarLosEspaciosSin(int*& datos,int& numDatos,int& capacidad) {
    int* aux;
    capacidad += INCREMENTO;
    if (datos == nullptr) {
        datos = new int[capacidad]{};
        numDatos = 1; // esto sirve para poder dejar un 0 al final a la hora de la impresión
    }
    else {
        aux = new int[capacidad]{};
        for (int i = 0; i < numDatos+1; i++) {
            aux[i] = datos[i];
        }
        delete datos;
        datos = aux;
    }
}