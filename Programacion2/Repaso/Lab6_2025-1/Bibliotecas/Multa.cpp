//
// Created by carlo on 5/13/2026.
//
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Multa.h"

Multa::Multa() {
    placa = nullptr;
    codigoInfraccion = 0;
    fechaInfraccion = 0;
    fechaPago = 0;
    multa = 0;
}

Multa::~Multa() {
    if (placa != nullptr) delete[] placa;
    codigoInfraccion = 0;
    fechaInfraccion = 0;
    fechaPago = 0;
    multa = 0;
}

Multa::Multa(const Multa& org) {
    placa = nullptr;
    codigoInfraccion = 0;
    fechaInfraccion = 0;
    fechaPago = 0;
    multa = 0;
    *this = org;
}

void Multa::operator=(const Multa& org) {
    codigoInfraccion = org.codigoInfraccion;
    fechaInfraccion = org.fechaInfraccion;
    fechaPago = org.fechaPago;
    multa = org.multa;
    setPlaca(org.placa);
}

void Multa::setPlaca(const char* plac) {
    if (placa != nullptr) delete[] placa;
    placa = new char[strlen(plac) + 1];
    strcpy(placa, plac);
}

void Multa::getPlaca(char* plac) const {
    if (placa == nullptr) plac[0] = 0;
    else strcpy(plac, placa);
}

void Multa::setFechaInfraccion(int fecha) {
    fechaInfraccion = fecha;
}

int Multa::getFechaInfraccion() const {
    return fechaInfraccion;
}

void Multa::setFechaPago(int fecha) {
    fechaPago = fecha;
}

int Multa::getFechaPago() const {
    return fechaPago;
}

void Multa::setCodigoInfraccion(int codigo) {
    codigoInfraccion = codigo;
}

int Multa::getCodigoInfraccion() const {
    return codigoInfraccion;
}

void Multa::setMulta(double mul) {
    multa = mul;
}

double Multa::getMulta() const {
    return multa;
}

void operator >> (ifstream& arch, Multa& multa) {
    // 23/7/2023,P474-593,2060,P,22/8/2023
    // 1/12/2020,G760-721,2022
    int fechaInfraccion, codigoInfraccion, fechaPago;
    char placa[15], estaPagado[3];

    fechaInfraccion = leerFecha(arch);
    arch.get();
    arch.getline(placa, 15, ',');
    arch >> codigoInfraccion;

    multa.setFechaInfraccion(fechaInfraccion);
    multa.setPlaca(placa);
    multa.setCodigoInfraccion(codigoInfraccion);

    if (arch.get() != '\n' or arch.eof()) {
        arch.getline(estaPagado, 3, ',');
        fechaPago = leerFecha(arch);
        multa.setFechaPago(fechaPago);
    }
}

int leerFecha(ifstream& arch) {
    int dd, mm, aa;
    char c;
    arch >> dd >> c >> mm >> c >> aa;
    return aa*10000 + mm*100 + dd;
}

void operator<<(ofstream& arch, Multa& multa) {
    char placa[15];
    multa.getPlaca(placa);

    arch << setw(15) << left << placa
         << right << multa.getFechaInfraccion()
         << setw(10) << multa.getCodigoInfraccion()
         << setw(10) << fixed << setprecision(2) << multa.getMulta();
    if (multa.getFechaPago() != 0) {
        arch << setw(10) << multa.getFechaPago();
    }
    arch << endl;
}
