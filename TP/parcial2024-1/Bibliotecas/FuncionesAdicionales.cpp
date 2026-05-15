#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "FuncionesAdicionales.h"

void abrirArchivo(ifstream& arch, const char* nombre) {
    arch.open(nombre, ios::in);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << nombre << endl;
        exit(1);
    }
}
void abrirArchivo(ofstream& arch, const char* nombre) {
    arch.open(nombre, ios::out);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << nombre << endl;
        exit(1);
    }
}

void cargarDatosPacientes(ifstream& arch, int* dni, int* distrito, int* nacimiento, double* descuento, int& cantPacientes) {
    //61061535   [ROCIO YOLANDA ACUNA YINO]   15055   2015   2.60
    //dni              nombre              distrito nacimiento descuento
    cantPacientes = 0;
    while (arch >> dni[cantPacientes]) {
        saltarTextoHasta(arch, ']');
        arch >> distrito[cantPacientes] >> nacimiento[cantPacientes] >> descuento[cantPacientes];
        cantPacientes++;
    }
}
void cargarDatosMedicinas(ifstream& arch, int* medicina, double* precio, int& cantMedicinas) {
    cantMedicinas = 0;
    while (arch >> medicina[cantMedicinas]) {
        saltarTextoHasta(arch, ' ');
        arch >> precio[cantMedicinas];
        cantMedicinas++;
    }
}

void emitirReporteSimple(ofstream& arch, int* dni, int* distrito, int* nacimiento, double* descuento, int cantPacientes, int* medicina, double* precio, int cantMedicinas) {
    int i=0;
    arch << "DNI" << setw(16) << "distrito" << setw(13) << "nacimiento" << setw(10) << "descuento" << endl;
    for (i=0; i < cantPacientes; i++) {
        arch << dni[i] << setw(10) << distrito[i] << setw(10) << nacimiento[i] << setw(10) << descuento[i] << endl;
    }
    arch << "MEDICINA" << setw(10) << "PRECIO" << endl;
    for (i=0; i < cantMedicinas; i++) {
        arch << medicina[i] << setw(10) << precio[i] << endl;
    }
}

void saltarTextoHasta(ifstream& arch, char limitador) {
    arch >> ws;
    arch.get();
    while (arch.get() != limitador);
}