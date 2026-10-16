#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#include "Medicamento.h"

Medicamento::Medicamento() {
    codigo = 0;
    nombre = "";
    precio = 0;
    stock = 0;
}

Medicamento::Medicamento(const Medicamento &org) {
    codigo = 0;
    nombre = "";
    precio = 0;
    stock = 0;
    *this = org;
}

void Medicamento::operator=(const Medicamento &org) {
    setCodigo(org.codigo);
    setNombre(org.nombre);
    setStock(org.stock);
    setPrecio(org.precio);
}

void Medicamento::setCodigo(int cod) {
    codigo = cod;
}

void Medicamento::setNombre(const string &nomb) {
    nombre = nomb;
}

void Medicamento::setStock(int stk) {
    stock = stk;
}

void Medicamento::setPrecio(double prec) {
    precio = prec;
}

int Medicamento::getCodigo() const {
    return codigo;
}

string Medicamento::getNombre() const {
    return nombre;
}

int Medicamento::getStock() const {
    return stock;
}

double Medicamento::getPrecio() const {
    return precio;
}

void Medicamento::lee(ifstream &arch) {
    // 30007,DICLOFENACO SODICO 1MG GTS 5 ML,500,0.85,USA
    // codigo, nombre, stock, precio
    arch >> codigo;
    if (arch.eof()) return;
    arch.get();
    getline(arch, nombre, ',');
    arch >> stock;
    arch.get();
    arch >> precio;
    arch.get();
    // USA
}

void Medicamento::imprime(ofstream &arch) const {
    arch << codigo << "   "
         << left << setw(25) << nombre
         << right << stock
         << right << setw(5) << fixed << setprecision(2) << precio << "   ";
}

bool Medicamento::operator<(const Medicamento &m) const {
    return codigo < m.codigo;
}
