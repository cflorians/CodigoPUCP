#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Alumno.h"

Alumno::Alumno() {
    nombre = nullptr;
    codigo = 0;
    escala = 0;
    creditos = 0;
    total = 0;
}

Alumno::~Alumno() {
    if (nombre) delete[] nombre;
    codigo = 0;
    escala = 0;
    creditos = 0;
    total = 0;
}

Alumno::Alumno(const Alumno &org) {
    nombre = nullptr;
    codigo = 0;
    escala = 0;
    creditos = 0;
    total = 0;
    *this = org;
}

void Alumno::operator=(const Alumno &org) {
    setNombre(org.nombre);
    setCodigo(org.codigo);
    setEscala(org.escala);
    setCreditos(org.creditos);
    setTotal(org.total);
}

void Alumno::setCodigo(int cod) {
    codigo = cod;
}

void Alumno::setNombre(const char *nomb) {
    if (nombre) delete[] nombre;
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre, nomb);
}

void Alumno::setEscala(int esc) {
    escala = esc;
}

void Alumno::setCreditos(double cred) {
    creditos = cred;
}

void Alumno::setTotal(double tot) {
    total = tot;
}

int Alumno::getCodigo() const {
    return codigo;
}

void Alumno::getNombre(char *nomb) const {
    if (nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb, nombre);
}

int Alumno::getEscala() const {
    return escala;
}

double Alumno::getCreditos() const {
    return creditos;
}

double Alumno::getTotal() const {
    return total;
}

void Alumno::leer(ifstream &arch) {
    // 202123703,GAMARRA/TABORI/PAUL-RONAL,5,20,30
    char nomb[100];
    arch >> codigo;
    if (arch.eof()) return;
    arch.get();
    arch.getline(nomb,100,',');
    arch >> escala;
    arch.get();
    arch >> creditos;
    arch.get();
    // 30
    setNombre(nomb);
}

void Alumno::imprimir(ofstream &arch) {
    arch << codigo << setw(8) << " "
         << left << setw(40) << nombre
         << right << escala << setw(6) << " "
         << right << fixed << setprecision(2) << creditos << setw(6) << " ";
}
