#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Medico.h"

Medico::Medico() {
    especialidad = nullptr;
    nombre = nullptr;
    codigo = 0;
}

Medico::~Medico() {
    if (especialidad) delete[] especialidad;
    if (nombre) delete[] nombre;
    codigo = 0;
}

Medico::Medico(const Medico &org) {
    especialidad = nullptr;
    nombre = nullptr;
    codigo = 0;
    *this = org;
}

void Medico::operator=(const Medico &org) {
    setNombre(org.nombre);
    setEspecialidad(org.especialidad);
    setCodigo(org.codigo);
}

void Medico::setCodigo(int cod) {
    codigo = cod;
}

void Medico::setNombre(const char *nomb) {
    if (nombre) delete[] nombre;
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre, nomb);
}

void Medico::setEspecialidad(const char *esp) {
    if (especialidad) delete[] especialidad;
    especialidad = new char[strlen(esp)+1];
    strcpy(especialidad, esp);
}

int Medico::getCodigo() const {
    return codigo;
}

void Medico::getNombre(char *nomb) {
    if (nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb, nombre);
}

void Medico::getEspecialidad(char *espec) {
    if (nombre == nullptr) espec[0] = 0;
    else strcpy(espec, nombre);
}

void operator>>(ifstream &arch, Medico &medico) {
    // 50611,EDGAR  MUNOZ VERGEL,Urologia
    // codigo, nombre, especialidad
    int codigo;
    char nombre[100], especialidad[100];

    arch >> codigo;
    if (arch.eof()) return;
    arch.get();
    arch.getline(nombre, 100, ',');
    arch.getline(especialidad, 100, '\n');

    medico.setNombre(nombre);
    medico.setEspecialidad(especialidad);
    medico.setCodigo(codigo);
}
