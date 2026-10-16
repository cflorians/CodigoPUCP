#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include "Empresa.h"


Empresa::Empresa() {
    nombre = nullptr;
    dni = 0;
    for (int i=0; i<10; i++) placas[i] = nullptr;
    numPlacas = 0;
    numMultas = 0;
}
Empresa::~Empresa() {
    if (nombre) delete [] nombre;
    for (int i=0; i<10; i++) if (placas[i]) delete[] placas[i];
}
void Empresa::setDni(int dni) {
    this->dni = dni;
}
int Empresa::getDni() const {
    return dni;
}
void Empresa::setNombre(const char* nomb) {
    if (nombre) delete[] nombre;
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre, nomb);
}
void Empresa::getNombre(char* nomb) const {
    if (nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb, nombre);
}
void Empresa::setPlacaI(const char* plac, int i) {
    if (placas[i]) delete[] placas[i];
    placas[i] = new char[strlen(plac)+1];
    strcpy(placas[i], plac);
    if (i >= numPlacas) numPlacas = i+1;
}
void Empresa::getPlacaI(char* plac, int i) const {
    if (placas[i] == nullptr) plac[0] = 0;
    else strcpy(plac, placas[i]);
}

int Empresa::getNumPlacas() const {
    return numPlacas;
}
void Empresa::setNumPlacas(int numPlacas) {
    this->numPlacas = numPlacas;
}

int Empresa::getNumMultas() const {
    return numMultas;
}
void Empresa::setNumMultas(int numMultas) {
    this->numMultas = numMultas;
}

Multa Empresa::getMulta(int i) const {
    if (i < numMultas) return multas[i];
}

void Empresa::operator+=(const Multa& infraccion) {
    multas[numMultas] = infraccion;
    numMultas++;
}


void operator >> (ifstream& arch, Empresa& empresa) {
    // 13219606,Rodriguez Moreno Blanca Ofelia,P201-291,M312-270,M312-270
    // DNI     , Nombre dueño                 , placas de sus vehiculos
    int dni;
    char nomb[100];
    char placa[9];

    arch >> dni;
    arch.get();
    arch.getline(nomb,100,',');
    empresa.setDni(dni);
    empresa.setNombre(nomb);

    int i=0;
    while (true) {
        arch.get(placa, 9);
        empresa.setPlacaI(placa,i);
        i++;
        if (arch.get() == '\n' or arch.eof()) break;
    }
    empresa.setNumPlacas(i);
}

void operator<<(ofstream& arch, const Empresa& empresa) {
    char nombre[100];
    empresa.getNombre(nombre);
    arch << right << empresa.getDni()
         << left << setw(30) << nombre;
    int cantPlacas = empresa.getNumPlacas();
    for (int i=0; i<cantPlacas; i++) {
        char placa[15];
        empresa.getPlacaI(placa, i);
        arch << left << setw(10) << placa;
    }
    int cantMultas = empresa.getNumMultas();
    for (int i=0; i<cantMultas; i++) {
        Multa multa = empresa.getMulta(i);
        arch << multa;
    }
}
