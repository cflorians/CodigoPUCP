#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#include "Marca.h"


Marca::Marca() {
    laboratorio = "";
    lote = 0;
}

Marca::Marca(const Marca &org) {
    laboratorio = "";
    lote = 0;
    *this = org;
}

void Marca::operator=(const Marca &org) {
    Medicamento::operator=(org);
    setLaboratorio(org.laboratorio);
    setLote(org.lote);
}

void Marca::setLote(int lot) {
    lote = lot;
}

int Marca::getLote() const {
    return lote;
}

void Marca::setLaboratorio(const string &lab) {
    laboratorio = lab;
}

string Marca::getLaboratorio() const {
    return laboratorio;
}

void Marca::lee(ifstream &arch) {
    Medicamento::lee(arch);
    if (arch.eof()) return;
    // LABORATORIO ASTRAZENECA,1630
    getline(arch, laboratorio, ',');
    arch >> lote;
    arch.get();
}

void Marca::imprime(ofstream &arch) const {
    Medicamento::imprime(arch);
    arch << left << setw(20) << laboratorio << lote << endl;
}
