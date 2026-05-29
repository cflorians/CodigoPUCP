//
// Created by Carlos on 28/05/2026.
//

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

#include "Tesoreria.h"

Tesoreria::Tesoreria() {
    lpresencial = nullptr; // esto es una variacion del lab 8 2023-1, deberia ser estatico
    lvirtual = nullptr; // memoria por incrementos
}

Tesoreria::~Tesoreria() {
    if (lpresencial) delete[] lpresencial;
    if (lvirtual) delete[] lvirtual;
}

void Tesoreria::incrementarLosEspacios(Virtual*& datos, int &numDatos, int &capacidad) {
    Virtual* temp = nullptr;
    capacidad += 5;
    if (datos == nullptr) {
        datos = new Virtual[capacidad]{};
        numDatos = 1;
    }
    else {
        temp = new Virtual[capacidad]{};
        for (int i = 0; i < numDatos; i++) temp[i] = datos[i];
        delete[] datos;
        datos = temp;
    }
}

void Tesoreria::cargaescalas(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    int cantDatos = 0;
    while (true) {
        arch >> lescala[cantDatos];
        if (arch.eof()) break;
        cantDatos++;
    }
}

void Tesoreria::cargaalumnos(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    char tipo;
    class Presencial buffer[100]{};
    int cantPres = 0, cantSemi = 0;
    // Para memoria con incrementos
    lvirtual = nullptr;
    int numDatos = 0, capacidad = 0;
    while (true) {
        arch >> tipo;
        if (arch.eof()) break;
        arch.get();
        switch (tipo) {
            case 'P': // Memoria exacta
                buffer[cantPres].leer(arch);
                cantPres++;
                break;
            case 'S': // Arreglo estatico
                lsemipresencial[cantSemi].leer(arch);
                cantSemi++;
                break;
            case 'V': // Memoria por incrementos
                if (numDatos == capacidad) {
                    incrementarLosEspacios(lvirtual, numDatos, capacidad);
                }
                lvirtual[numDatos-1].leer(arch);
                numDatos++;
                break;
        }
    }
    lpresencial = new Presencial[cantPres + 1]{}; // ese 1 va porque no guardamos cantidad de datos
    for (int i = 0; i < cantPres; i++) {
        lpresencial[i] = buffer[i];
    }
}

void Tesoreria::actualiza(double creditos) {
}

void Tesoreria::imprime(const char *nombArch) {
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    for (int i = 0; lescala[i].getCodigo(); i++) {
        arch << lescala[i];
    }

    for (int i=0; lpresencial[i].getCodigo(); i++) {
        //arch << lpresencial[i];
    }
}
