//
// Created by Carlos on 28/05/2026.
//
#include <cstring>
#include <fstream>
using namespace std;
#include "Alumno.h"


Alumno::Alumno() {
    nombre = nullptr;
    codigo = 0;
    escala = 0;
    total = 0;
}

Alumno::~Alumno() {
    if (nombre) delete[] nombre;
    codigo = 0;
    escala = 0;
    total = 0;
}

Alumno::Alumno(const Alumno &orig) {
    nombre = nullptr;
    codigo = 0;
    escala = 0;
    total = 0;
    *this = orig;
}

void Alumno::operator=(const Alumno &orig) {
    setNombre(orig.nombre);
    setCodigo(orig.codigo);
    setEscala(orig.escala);
    setTotal(orig.total);
}

void Alumno::setCodigo(int cod) {
    codigo = cod;
}

int Alumno::getCodigo() const {
    return codigo;
}

void Alumno::setNombre(const char *nomb) {
    if (nombre) delete[] nombre;
    if (nomb) {
        nombre = new char[strlen(nomb)+1];
        strcpy(nombre, nomb);
    }
}

void Alumno::getNombre(char *nomb) {
    if (nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb, nombre);
}

void Alumno::setEscala(int esc) {
    escala = esc;
}

int Alumno::getEscala() const {
    return escala;
}

void Alumno::setTotal(double tot) {
    total = tot;
}

double Alumno::getTotal() const {
    return total;
}

void Alumno::leer(ifstream &arch) {
    // 202123703,GAMARRA/TABORI/PAUL-RONAL,5, 30
    char nomb[100];
    arch >> codigo;
    arch.get();
    if (arch.eof()) return;
    arch.getline(nomb,100,',');
    setNombre(nomb);
    arch >> escala;
    arch.get();
}

