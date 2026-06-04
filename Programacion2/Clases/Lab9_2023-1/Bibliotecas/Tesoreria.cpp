//
// Created by Carlos on 4/06/2026.
//
#include <fstream>
#include <iostream>
using namespace std;
#include "Tesoreria.h"

void Tesoreria::cargaEscalas() {
    ifstream arch("ArchivoDeDatos/escalas.csv", ios::in);
    if (not arch.is_open()) {
        cout << "Error en el archivo de entrada" << endl;
        exit(1);
    }

    int cantDatos = 0;
    while (true) {

        if (arch.eof()) break;
    }
}

void Tesoreria::cargaAlumnos() {
}

void Tesoreria::actualizaBoleta() {
}

void Tesoreria::imprimeBoleta() {
}
