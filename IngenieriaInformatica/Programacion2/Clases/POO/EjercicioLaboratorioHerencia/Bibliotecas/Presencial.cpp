//
// Created by Carlos on 28/05/2026.
//
#include <fstream>
using namespace std;
#include "Presencial.h"

Presencial::Presencial() {
    total = 0;
    recargo = 0;
}

void Presencial::operator=(const Presencial &org) {
    Alumno::operator=(org);
    this->total = org.total;
    this->recargo = org.recargo;
}

void Presencial::setRecargo(double recargo) {
    this->recargo = recargo;
}

double Presencial::getRecargo() const {
    return recargo;
}

void Presencial::setTotal(double total) {
    this->total = total;
}

double Presencial::getTotal() const {
    return total;
}

void Presencial::leer(ifstream &arch) {
    Alumno::leer(arch);
    if (arch.eof()) return;
    arch >> recargo;
    arch.get();
}

void operator<<(ifstream &arch, const Presencial &org) {
    
}
