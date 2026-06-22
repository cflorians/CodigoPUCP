#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Escala.h"

Escala::Escala() {
    codigo = 0;
    precio = 0;
}

void Escala::setCodigo(int cod) {
    codigo = cod;
}

void Escala::setPrecio(double prec) {
    precio = prec;
}

int Escala::getCodigo() const {
    return codigo;
}

double Escala::getPrecio() const {
    return precio;
}

void operator >> (ifstream &arch, Escala &e) {
    // 5,666.90
    // codigo,costo
    int cod;
    double monto;
    arch >> cod;
    if (arch.eof()) return;
    arch.get();
    arch >> monto;

    e.setCodigo(cod);
    e.setPrecio(monto);
}
