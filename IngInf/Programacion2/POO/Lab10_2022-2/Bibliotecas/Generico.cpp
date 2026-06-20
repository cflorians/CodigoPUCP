#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#include "Generico.h"

Generico::Generico() {
    pais = "";
}

Generico::Generico(const Generico &org) {
    pais = "";
    *this = org;
}

void Generico::operator=(const Generico &org) {
    Medicamento::operator=(org);
    setPais(org.pais);
}

void Generico::setPais(const string &p) {
    pais = p;
}

string Generico::getPais() const {
    return pais;
}

void Generico::lee(ifstream &arch) {
    Medicamento::lee(arch);
    if (arch.eof()) return;
    // USA
    getline(arch, pais, '\n');
}

void Generico::imprime(ofstream &arch) const {
    Medicamento::imprime(arch);
    arch << pais << endl;
}
