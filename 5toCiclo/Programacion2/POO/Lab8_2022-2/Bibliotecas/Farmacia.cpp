#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Farmacia.h"

void Farmacia::cargaMedico(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    int cant = 0;
    while (true) {
        arch >> lMedico[cant];
        if (arch.eof()) break;
        cant++;
    }

    for (int i = 0; lMedico[i].getCodigo(); i++) {
        cout << lMedico[i].getCodigo() << endl;
    }
}

void Farmacia::leeRecetas(const char *nombArch, const char *nombArch2) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    int cantCon = 0, cantSin = 0;
    int fecha, dd, mm, aa;
    int dni, medicamento, codMedico;
    int cantidad;
    int tipoMedicamento;
    char nombre[100];
    char c;
    while (true) {
        // 18/03/2023,54815159,Patino/Delicia,60184,17804,5,75565,26,36711,16,46000,33,12388,17
        arch >> dd >> c >> mm >> c >> aa >> c;
        if (arch.eof()) break;
        fecha = aa*10000 + mm*100 + dd;
        arch >> dni;
        arch.getline(nombre, 100, ',');
        arch >> codMedico;
        arch.get();
        while (true) {
            arch >> medicamento;
            arch.get();
            tipoMedicamento = (medicamento/10000)%2;
            arch >> cantidad;
            if (arch.get() == '\n' or arch.eof()) break;
            if (tipoMedicamento == 0) { // es par entonces necesita receta
                lConReceta[cantCon].setCodMed(codMedico);
                lConReceta[cantCon].setCantidad(cantidad);
                cantCon++;
            }
            else { // entonces no necesita receta

                cantSin++;
            }
        }
    }
}

void Farmacia::imprimeRecetas(const char *nombArch) {
}
