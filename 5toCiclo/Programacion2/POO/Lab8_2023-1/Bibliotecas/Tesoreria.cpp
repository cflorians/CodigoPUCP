//
// Created by Carlos on 4/06/2026.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Tesoreria.h"

void Tesoreria::cargaEscala(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    int cant = 0;
    while (true) {
        // 5,666.90
        arch >> lEscala[cant];
        if (arch.eof()) break;
        cant++;
    }
}

void Tesoreria::cargaAlumnos(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    int cantPresencial = 0;
    int cantSemi = 0;
    int cantVirtual = 0;
    char tipo;
    while (true) {
        arch >> tipo;
        arch.get();
        if (arch.eof()) break;
        switch (tipo) {
            case 'P':
                arch >> lPresencial[cantPresencial];
                if (arch.eof()) break;
                cantPresencial++;
                break;
            case 'S':
                arch >> lSemipresencial[cantSemi];
                if (arch.eof()) break;
                cantSemi++;
                break;
            case 'V':
                arch >> lVirtual[cantVirtual];
                if (arch.eof()) break;
                cantVirtual++;
                break;
        }
    }
}

void Tesoreria::actualiza(int cantCreditos) {
    int indice = 0;
    // Actualizamos todos los presenciales
    for (int i=0; lPresencial[i].getCodigo() ; i++) {
        for (int j=0; lEscala[j].getCodigo(); j++) {
            if (lPresencial[i].getEscala() == lEscala[j].getCodigo()) {
                indice = j;
                break;
            }
        }
        lPresencial[i].calcularTotal(cantCreditos, lEscala[indice].getPrecio());
    }
    // Actualizamos todos los semipresenciales
    for (int i=0; lSemipresencial[i].getCodigo() ; i++) {
        for (int j=0; lEscala[j].getCodigo(); j++) {
            if (lSemipresencial[i].getEscala() == lEscala[j].getCodigo()) {
                indice = j;
                break;
            }
        }
        lSemipresencial[i].calcularTotal(cantCreditos, lEscala[indice].getPrecio());
    }
    // Actualizamos todos los virtuales
    for (int i=0; lVirtual[i].getCodigo() ; i++) {
        for (int j=0; lEscala[j].getCodigo(); j++) {
            if (lVirtual[i].getEscala() == lEscala[j].getCodigo()) {
                indice = j;
                break;
            }
        }
        lVirtual[i].calcularTotal(cantCreditos, lEscala[indice].getPrecio());
    }
}

void Tesoreria::imprime(const char *nombArch) {
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    arch << setw(20) << left << "Codigo"
         << setw(40) << left << "Nombre"
         << setw(11) << left << "Escala"
         << setw(20) << left << "Licencia"
         << left << "Total" << endl;
    arch << setfill('=') << setw(100) << '=' << setfill(' ') << endl;
    // Imprimimos los virtuales
    for (int i=0; lVirtual[i].getCodigo() ; i++) {
        arch << lVirtual[i];
    }
    // Imprimimos los presenciales
    for (int i=0; lPresencial[i].getCodigo() ; i++) {
        arch << lPresencial[i];
    }
    // Imprimimos los semipresenciales
    for (int i=0; lSemipresencial[i].getCodigo() ; i++) {
        arch << lSemipresencial[i];
    }
}
