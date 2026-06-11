//
// Created by Carlos on 10/06/2026.
//
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "Persona.h"

Persona::Persona() {
    nombre = nullptr;
    dni = 0;
    sueldo = 0;
}

Persona::~Persona() {
    if (nombre) delete[] nombre;
    dni = 0;
    sueldo = 0;
}

Persona::Persona(const Persona &org) {
    nombre = nullptr;
    dni = 0;
    sueldo = 0;
    *this = org;
}

void Persona::operator=(const Persona &org) {
    setDni(org.dni);
    setSueldo(org.sueldo);
    setNombre(org.nombre);
}

void Persona::setNombre(const char *nomb) {
    if (nombre) delete[] nombre;
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre, nomb);
}

void Persona::getNombre(char *nomb) const {
    if (nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb, nombre);
}

void Persona::setDni(int id) {
    dni = id;
}

int Persona::getDni() const {
    return dni;
}

void Persona::setSueldo(double monto) {
    sueldo = monto;
}

double Persona::getSueldo() const {
    return sueldo;
}

ifstream & operator>>(ifstream &arch, Persona &per) {
    // 48329420,ANTHONY PEREZ,5478.20
    int dni;
    char nombre[100];
    double sueldo;

    arch >> dni;
    if (arch.eof()) return arch;
    arch.get();
    arch.getline(nombre, 100, ',');
    arch >> sueldo;

    per.setDni(dni);
    per.setSueldo(sueldo);
    per.setNombre(nombre);

    return arch;
}

ofstream & operator<<(ofstream &arch, const Persona &per) {
    char nombre[100];
    per.getNombre(nombre);

    arch << setw(20) << left << nombre
         << right << per.getDni() << "   "
         << fixed << setprecision(2) << per.getSueldo() << endl;

    return arch;
}

bool operator>(const Persona &a, const Persona &b) {
    return a.getDni() > b.getDni();
}
