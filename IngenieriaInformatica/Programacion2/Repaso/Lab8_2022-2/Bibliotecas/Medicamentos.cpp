#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Medicamentos.h"

Medicamentos::Medicamentos() {
    nombre = nullptr;
    cantidad = 0;
    codigo = 0;
    fecha = 0;
    precio = 0;
}

Medicamentos::~Medicamentos() {
    if (nombre) delete[] nombre;
    cantidad = 0;
    codigo = 0;
    fecha = 0;
    precio = 0;
}

Medicamentos::Medicamentos(const Medicamentos &org) {
    nombre = nullptr;
    cantidad = 0;
    codigo = 0;
    fecha = 0;
    precio = 0;
    *this = org;
}

void Medicamentos::operator=(const Medicamentos &org) {
    setNombre(org.nombre);
    setCantidad(org.cantidad);
    setCodigo(org.codigo);
    setFecha(org.fecha);
    setPrecio(org.precio);
}

void Medicamentos::setCodigo(int cod) {
    codigo = cod;
}

void Medicamentos::setNombre(char *nomb) {
    if (nombre) delete[] nombre;
    else strcpy(nombre, nomb);
}

void Medicamentos::setCantidad(int cant) {
    cantidad = cant;
}

void Medicamentos::setPrecio(double prec) {
    precio = prec;
}

void Medicamentos::setFecha(int fec) {
    fecha = fec;
}

int Medicamentos::getCodigo() const {
    return codigo;
}

void Medicamentos::getNombre(char *nomb) {
    if (nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb, nombre);
}

int Medicamentos::getCantidad() const {
    return cantidad;
}

double Medicamentos::getPrecio() const {
    return precio;
}

int Medicamentos::getFecha() const {
    return fecha;
}
