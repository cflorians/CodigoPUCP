#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Tesoreria.h"

void Tesoreria::cargaEscalas() {
    ifstream arch("Archivos/escalas.csv", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir Archivos/escalas.csv" << endl;
        exit(1);
    }

    int cant = 0;
    while (true) {
        arch >> lEscala[cant];
        if (arch.eof()) break;
        cant++;
    }
}

void Tesoreria::cargaAlumnos() {
    ifstream arch("Archivos/Alumnos.csv", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir Archivos/Alumnos.csv" << endl;
        exit(1);
    }

    // S,202123703,GAMARRA/TABORI/PAUL-RONAL,5,20,30
    int cant = 0;
    char tipo;
    while (true) {
        arch >> tipo;
        if (arch.eof()) break;
        arch.get();
        lBoleta[cant].inicializar(tipo);
        lBoleta[cant].leer(arch);
        cant++;
    }
}

void Tesoreria::actualizaBoleta() {
    for (int i=0; lBoleta[i].existe() ; i++) {
        lBoleta[i].actualizar();
    }
}

void Tesoreria::imprimeBoleta() {
    ofstream arch("Reportes/reporte.txt", ios::out);
    if (not arch.is_open()) {
        cout << "Error al abrir Reportes/reporte.txt" << endl;
        exit(1);
    }

    // Codigo        Nombre                        Escala     Cred.    Licencia   Total
    // --------------------------------------------------------------------------------
    arch << left << setw(17) << "Codigo"
         << left << setw(37) << "Nombre"
         << left << setw(10) << "Escala"
         << left << setw(11) << "Cred."
         << left << setw(14) << "Licencia"
         << left << "Total" << endl;
    arch << setfill('-') << setw(95) << "-" << setfill(' ') << endl;
    for (int i = 0; lBoleta[i].existe() ; i++) {
        lBoleta[i].mostrar(arch);
    }
}
