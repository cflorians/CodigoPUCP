#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#include "Generico.h"
#include "Marca.h"
#include "Almacen.h"

void Almacen::carga() {
    ifstream arch("Archivos/medicamentos.csv");
    if (not arch.is_open()) {
        cout << "Error al abrir medicamentos.csv" << endl;
        exit(1);
    }

    Medicamento* aux = nullptr;
    int tipo;
    while (true) {
        arch >> tipo;
        if (arch.eof()) break;
        arch.get();
        if (tipo == 0) aux = new Generico;
        else aux = new Marca;
        aux->lee(arch);
        arbolAlma.insertar(aux);
    }
}

void Almacen::actualiza() {
}

void Almacen::imprime() {
    ofstream arch("Reportes/reporte.txt", ios::out);
    if (not arch.is_open()) {
        cout << "Error al abrir reporte.txt" << endl;
        exit(1);
    }

    arch << arbolAlma;
}
