#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#include "Categoria.h"

Categoria::Categoria() {
    codigo = "";
    nombre = "";
    descripcion = "";
}

Categoria::~Categoria() {
    codigo = "";
    nombre = "";
    descripcion = "";
}

Categoria::Categoria(const Categoria &org) {
    codigo = "";
    nombre = "";
    descripcion = "";
    *this = org;
}

Categoria & Categoria::operator=(const Categoria &org) {
    if (this != &org) {
        codigo = org.codigo;
        nombre = org.nombre;
        descripcion = org.descripcion;
    }
    return *this;
}

void Categoria::setCodigo(const string &cod) {
    codigo = cod;
}

void Categoria::setNombre(const string &nomb) {
    nombre = nomb;
}

void Categoria::setDescripcion(const string &desc) {
    descripcion = desc;
}

string Categoria::getCodigo() const {
    return codigo;
}

string Categoria::getNombre() const {
    return nombre;
}

string Categoria::getDescripcion() const {
    return descripcion;
}

void Categoria::leer(ifstream &arch) {
    // UM1000,Just Chatting,Casual conversations; reactions; and hangouts without a main game.
    // codigo, nombre, descripcion
    getline(arch, codigo, ',');
    if (arch.eof()) return;
    getline(arch, nombre, ',');
    getline(arch, descripcion);
}

void Categoria::imprimir(ofstream &arch) const{
    arch << "CATEGORIA:" << endl;
    arch << setw(3) << " ";
    arch << left << setw(13) << "CODIGO:" << codigo << endl
         << setw(3) << " "
         << setw(13) << "NOMBRE:" << nombre << endl
         << setw(3) << " "
         << setw(13) << "DESCRIPCION:" << descripcion << endl;
}

bool Categoria::operator<(const Categoria &cat) const {
    return codigo < cat.codigo;
}

bool Categoria::operator==(const Categoria &cat) const {
    return (codigo == cat.codigo and nombre == cat.nombre and descripcion == cat.descripcion);
}

ifstream & operator>>(ifstream &arch, Categoria &categoria) {
    categoria.leer(arch);
    return arch;
}

ofstream & operator<<(ofstream &arch, const Categoria &categoria) {
    categoria.imprimir(arch);
    return arch;
}
