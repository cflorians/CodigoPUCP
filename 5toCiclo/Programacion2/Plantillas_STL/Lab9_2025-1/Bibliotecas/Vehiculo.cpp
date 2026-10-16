#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
using namespace std;

#include "Vehiculo.h"

void Vehiculo::setPlaca(const string &plac) {
    placa = plac;
}

void Vehiculo::setMarca(const string &marc) {
    marca = marc;
}

void Vehiculo::setModelo(const string &mod) {
    modelo = mod;
}

string Vehiculo::getPlaca() const {
    return placa;
}

string Vehiculo::getMarca() const {
    return marca;
}

string Vehiculo::getModelo() const {
    return modelo;
}

ifstream & operator>>(ifstream &arch, Vehiculo &vehiculo) {
    // M421-807,Honda,Fit
    // placa, marca, modelo
    string placa, marca, modelo;

    getline(arch, placa, ',');
    if (arch.eof()) return arch;
    getline(arch, marca, ',');
    getline(arch, modelo);

    vehiculo.setPlaca(placa);
    vehiculo.setMarca(marca);
    vehiculo.setModelo(modelo);
    return arch;
}
