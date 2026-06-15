//
// Created by carlo on 5/13/2026.
//
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include "Infraccion.h"

Infraccion::Infraccion() {
    codigo = 0;
    descripcion = nullptr;
    gravedad = nullptr;
    multa = 0.0;
}
Infraccion::~Infraccion() {
    if (descripcion != nullptr) delete[] descripcion;
    if (gravedad != nullptr) delete[] gravedad;
    multa = 0;
    codigo = 0;
}
Infraccion::Infraccion(const Infraccion& orig) {
    codigo = 0;
    descripcion = nullptr;
    gravedad = nullptr;
    multa = 0.0;
    *this = orig;
}
void Infraccion::operator=(const Infraccion& orig) {
    codigo = orig.codigo;
    multa = orig.multa;
    setGravedad(orig.gravedad);
    setDescripcion(orig.descripcion);
}
void Infraccion::setCodigo(int cod) {
    codigo = cod;
}
int Infraccion::getCodigo() const {
    return codigo;
}
void Infraccion::setDescripcion(const char* desc) {
    if (descripcion != nullptr) delete[] descripcion;
    descripcion = new char[strlen(desc) + 1];
    strcpy(descripcion, desc);
}
void Infraccion::getDescripcion(char* desc) {
    if (descripcion == nullptr) desc[0] = 0;
    else strcpy(desc, descripcion);
}
void Infraccion::setGravedad(const char* grav) {
    if (gravedad != nullptr) delete[] gravedad;
    gravedad = new char[strlen(grav) + 1];
    strcpy(gravedad, grav);
}
void Infraccion::getGravedad(char* grav) {
    if (gravedad == nullptr) grav[0] = 0;
    else strcpy(grav, gravedad);
}
void Infraccion::setMulta(double mul) {
    multa = mul;
}
double Infraccion::getMulta() const {
    return multa;
}

void operator >> (ifstream& arch, Infraccion& infraccion) {
    // 3001,214.55,Leve,Dejar mal estacionado el vehiculo en lugares permitidos.
    // codigo, multa, gravedad  , descripcion
    int codigo;
    double multa;
    char gravedad[30], descripcion[150];

    arch >> codigo;
    arch.get();
    arch >> multa;
    arch.get();
    arch.getline(gravedad, 30, ',');
    arch.getline(descripcion, 150, '\n');

    infraccion.setCodigo(codigo);
    infraccion.setMulta(multa);
    infraccion.setGravedad(gravedad);
    infraccion.setDescripcion(descripcion);
}

void operator<<(ofstream& arch, Infraccion& infraccion) {
    char gravedad[30], descripcion[150];
    infraccion.getGravedad(gravedad);
    infraccion.getDescripcion(descripcion);
    arch << infraccion.getCodigo()
         << setw(7) << right << fixed << setprecision(2) << infraccion.getMulta()
         << setw(3) << " " << setw(15) << left << gravedad
         << descripcion << endl;
}
