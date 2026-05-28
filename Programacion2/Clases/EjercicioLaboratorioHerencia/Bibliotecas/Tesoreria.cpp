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
}

Tesoreria::~Tesoreria() {
    if (lpresencial) delete[] lpresencial;
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
    class Presencial buffer[100];
    int cantPres = 0, cantSemi = 0, cantVir = 0;
    while (true) {
        arch >> tipo;
        if (arch.eof()) break;
        arch.get();
        switch (tipo) {
            case 'P':
                buffer[cantPres].leer(arch);
                cantPres++;
                break;
            case 'S':
                lsemipresencial[cantSemi].leer(arch);
                cantSemi++;
                break;
            case 'V':
                lvirtual[cantVir].leer(arch);
                cantVir++;
                break;
        }
    }
    lpresencial = new Presencial[cantPres + 1]; // ese 1 va porque no guardamos cantidad de datos
    for (int i = 0; i < cantPres; i++) {
        lpresencial[i] = buffer[i];
    }
}

void Tesoreria::actualiza(int creditos) {
}

void Tesoreria::imprime(const char *nombArch) {
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    for (int i = 0; lescala[i].getCodigo() != 0; i++) {
        arch << lescala[i];
    }
}
