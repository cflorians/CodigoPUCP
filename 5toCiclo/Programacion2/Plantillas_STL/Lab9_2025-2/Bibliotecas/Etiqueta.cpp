#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#include "Etiqueta.h"

Etiqueta::Etiqueta() {
    codigo = "";
    nombre = "";
}

Etiqueta::~Etiqueta() {
    codigo = "";
    nombre = "";
}

Etiqueta::Etiqueta(const Etiqueta &org) {
    codigo = "";
    nombre = "";
    *this = org;
}

Etiqueta & Etiqueta::operator=(const Etiqueta &org) {
    if (this != &org) {
        codigo = org.codigo;
        nombre = org.nombre;
    }
    return *this;
}

void Etiqueta::setCodigo(const string &cod) {
    codigo = cod;
}

void Etiqueta::setNombre(const string &nomb) {
    nombre = nomb;
}

string Etiqueta::getCodigo() const {
    return codigo;
}

string Etiqueta::getNombre() const {
    return nombre;
}

void Etiqueta::leer(ifstream &arch) {
    // AAM100,dropsenabled
    // codigo, nombre
    getline(arch, codigo, ',');
    if (arch.eof()) return;
    getline(arch, nombre);
}

void Etiqueta::imprimir(ofstream &arch) const{
    arch << "CODIGO: " << left << setw(8) << codigo
         << "NOMBRE: " << nombre << endl;
}

ifstream & operator>>(ifstream &arch, Etiqueta &etiqueta) {
    etiqueta.leer(arch);
    return arch;
}

ofstream & operator<<(ofstream &arch, const Etiqueta &etiqueta) {
    etiqueta.imprimir(arch);
    return arch;
}
