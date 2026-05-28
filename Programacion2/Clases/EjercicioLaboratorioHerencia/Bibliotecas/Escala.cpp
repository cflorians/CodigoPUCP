//
// Created by Carlos on 28/05/2026.
//
#include <fstream>
#include <iomanip>
using namespace std;
#include "Escala.h"

Escala::Escala() {
    codigo = 0;
    precio = 0;
}

void Escala::setCodigo(int cod) {
    codigo = cod;
}

int Escala::getCodigo() const {
    return codigo;
}

void Escala::setPrecio(double pre) {
    precio = pre;
}

double Escala::getPrecio() const {
    return precio;
}

void operator >> (ifstream& arch, Escala& escala) {
    int codigo;
    double precio;
    arch >> codigo;
    arch.get();
    arch >> precio;
    arch.get();
    if (arch.eof()) return;

    escala.setCodigo(codigo);
    escala.setPrecio(precio);
}

void operator<<(ofstream &arch, Escala &escala) {
    arch << escala.getCodigo() << "  " << fixed << setprecision(1) << escala.getPrecio() << endl;
}
