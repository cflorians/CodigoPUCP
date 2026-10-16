#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
using namespace std;

#include "Vehiculo.h"
#include "Multa.h"

#include "Empresa.h"

void Empresa::setDni(int num) {
    dni = num;
}

void Empresa::setNombre(const string &nomb) {
    nombre = nomb;
}

void Empresa::setDistrito(const string &dist) {
    distrito = dist;
}

void Empresa::insertarVehiculo(const class Vehiculo &v) {
    vehiculos[v.getPlaca()] = v;
}

void Empresa::insertarMulta(const class Multa &m) {
    multasRecibidas.push_back(m);
}

int Empresa::getDni() const {
    return dni;
}

string Empresa::getNombre() const {
    return nombre;
}

string Empresa::getDistrito() const {
    return distrito;
}

bool Empresa::operator<(const Empresa &e) const {
    return dni < e.dni;
}

ifstream & operator>>(ifstream &arch, Empresa &e) {
    // 79672079,CONTRERAS CHANG JOHANA CINTHIA,CHORRILLOS
    // dni, nombre, distrito
    int dni;
    string nombre, distrito;

    arch >> dni;
    if (arch.eof()) return arch;
    arch.get(); // consume la coma
    getline(arch, nombre, ',');
    getline(arch, distrito);

    e.setDni(dni);
    e.setNombre(nombre);
    e.setDistrito(distrito);

    return arch;
}

ofstream & operator<<(ofstream &arch, const Empresa &e) {

    return arch;
}