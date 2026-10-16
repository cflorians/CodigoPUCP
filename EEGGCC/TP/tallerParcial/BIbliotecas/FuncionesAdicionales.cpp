#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "FuncionesAdicionales.h"

void abrirArchivos(ifstream& arch, const char* nombreArch) {
    arch.open(nombreArch, ios::in);
    if (!arch.is_open()) {
        cout << "Error al abrir " << nombreArch << endl;
        exit(1);
    }
}
void abrirArchivos(ofstream& arch, const char* nombreArch) {
    arch.open(nombreArch, ios::out);
    if (!arch.is_open()) {
        cout << "Error al abrir " << nombreArch << endl;
        exit(1);
    }
}

void cargarDatosLibros(ifstream& arch, int* codigoLibro, double* precioLibro, int& cantLibros) {
    //9155175	[Diamantes y pedernales]	*Jose Maria Arguedas*	69.02
    int codigo, pos;
    double precio;
    arch >> codigoLibro[0];
    saltarTextoHasta(arch, ']');
    saltarTextoHasta(arch, '*');
    arch >> precioLibro[0];

    cantLibros = 1;
    while (arch >> codigo) {
        saltarTextoHasta(arch, ']');
        saltarTextoHasta(arch, '*');
        arch >> precio;
        pos = buscarPosicion(precioLibro, cantLibros, precio);
        generarEspacioParaNuevoDato(codigoLibro, precioLibro, cantLibros, pos);
        codigoLibro[pos] = codigo;
        precioLibro[pos] = precio;
        cantLibros++;
    }
}
void generarReporteSimple(ofstream& arch, int* codigoLibro, double* precioLibro, int cantLibros) {
    int i=0;
    arch << "CODIGO LIBRO" << setw(8) << "PRECIO" << endl;
    for (i=0; i<cantLibros; i++) {
        arch << codigoLibro[i] << setw(12) << fixed << setprecision(2) << precioLibro[i] << endl;
    }
}

void cargarDatosVenta(istream &arch, )

void generarEspacioParaNuevoDato(int* codigoLibro, double* precioLibro, int cantLibros, int pos) {
    int i=0;
    for (i=cantLibros; i > pos; i--) {
        codigoLibro[i] = codigoLibro[i-1];
        precioLibro[i] = precioLibro[i-1];
    }
}
int buscarPosicion(double* precioLibro, int cantLibros, double precio) {
    int i=0;
    for (i=0; i<cantLibros; i++) {
        if (precio < precioLibro[i]) {
            return i;
        }
    }
    return cantLibros;
}
void saltarTextoHasta(ifstream& arch, char limitador) {
    arch >> ws;
    arch.get();
    while (arch.get() != limitador);
}