//
// Created by Carlos on 4/06/2026.
//
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Escala.h"


Escala::Escala() {
    codigo = 0;
    precio = 0;
}

Escala::~Escala() {
    codigo = 0;
    precio = 0;
}

void Escala::setCodigo(int cod) {
    codigo = cod;
}

void Escala::setPrecio(double pre) {
    precio = pre;
}

int Escala::getCodigo() const {
    return codigo;
}

double Escala::getPrecio() const {
    return precio;
}

void operator>>(ifstream &arch, Escala &escala) {
    // 5,666.90
    int codigo;
    double precio;

    arch >> codigo;
    if (arch.eof()) return;
    arch.get();
    arch >> precio;

    escala.setCodigo(codigo);
    escala.setPrecio(precio);
}
