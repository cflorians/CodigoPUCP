#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
using namespace std;

#include "Infraccion.h"

void Infraccion::setCodigo(const string &cod) {
    codigo = cod;
}

void Infraccion::setMulta(const double &mult) {
    multa = mult;
}

void Infraccion::setGravedad(const string &grav) {
    gravedad = grav;
}

void Infraccion::setDescripcion(const string &desc) {
    descripcion = desc;
}

string Infraccion::getCodigo() const {
    return codigo;
}

double Infraccion::getMulta() const {
    return multa;
}

string Infraccion::getGrav() const {
    return gravedad;
}

string Infraccion::getDescripcion() const {
    return descripcion;
}

bool Infraccion::operator<(const Infraccion &infraccion) const {
    return codigo < infraccion.codigo;
}

ifstream & operator>>(ifstream &arch, Infraccion &infraccion) {
    // L3001,214.55,LEVE,Dejar mal estacionado el vehiculo en lugares permitidos.
    // codigo, multa, gravedad, descripcion
    string codigo, gravedad, descripcion;
    double multa;

    getline(arch, codigo, ',');
    if (arch.eof()) return arch;
    arch >> multa;
    arch.get(); // consume la coma
    getline(arch, gravedad, ',');
    getline(arch, descripcion);

    infraccion.setCodigo(codigo);
    infraccion.setMulta(multa);
    infraccion.setGravedad(gravedad);
    infraccion.setDescripcion(descripcion);

    return arch;
}

ofstream & operator<<(ofstream &arch, const Infraccion &infraccion) {

    return arch;
}
