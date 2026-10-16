//
// Created by Carlos on 4/06/2026.
//
#include <cstring>
#include <iostream>
#include <iomanip>
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

Alumno::Alumno(const Alumno& org) {
    nombre = nullptr;
    codigo = 0;
    escala = 0;
    total = 0;
    *this = org;
}

void Alumno::operator=(const Alumno& org) {
    setNombre(org.nombre);
    setCodigo(org.codigo);
    setEscala(org.escala);
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

void Alumno::setTotal(double tot) {
    total = tot;
}

int Alumno::getCodigo() const {
    return codigo;
}

void Alumno::getNombre(char *nomb) {
    if (nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb, nombre);
}

int Alumno::getEscala() const {
    return escala;
}

double Alumno::getTotal() const {
    return total;
}

void Alumno::leer(ifstream &arch) {
    // 202123703,GAMARRA/TABORI/PAUL-RONAL,
    char nomb[100];

    arch >> codigo;
    if (arch.eof()) return;
    arch.get();
    arch.getline(nomb, 100, ',');
    setNombre(nomb);
}

void Alumno::mostrar(ofstream &arch) {
    arch << right << codigo << setw(11) << " ";
    arch << setw(43) << left << nombre << right << escala;
}
