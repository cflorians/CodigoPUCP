#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "SinReceta.h"

SinReceta::SinReceta() {
    nombre = nullptr;
    dni = 0;
}

SinReceta::~SinReceta() {
    if (nombre) delete[] nombre;
    dni = 0;
}

SinReceta::SinReceta(const SinReceta &org) {
    nombre = nullptr;
    dni = 0;
    *this = org;
}

void SinReceta::operator=(const SinReceta &org) {
    Medicamentos::operator=(org);
    setDni(org.dni);
    setNombre(org.nombre);
}

void SinReceta::setDni(int num) {
    dni = num;
}

void SinReceta::setNombre(const char *nomb) {
    if (nombre) delete[] nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

int SinReceta::getDni() const {
    return dni;
}

void SinReceta::getNombre(char *nomb) {
    if (nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb, nombre);
}
