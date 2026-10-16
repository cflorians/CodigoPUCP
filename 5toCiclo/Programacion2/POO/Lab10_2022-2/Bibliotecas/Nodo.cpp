#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#include "Nodo.h"

Nodo::Nodo() {
    medicamento = nullptr;
    izq = nullptr;
    der = nullptr;
}

Nodo::~Nodo() {
    if (medicamento) delete medicamento;
    if (izq) delete izq;
    if (der) delete der;
}

void Nodo::setMedicamento(Medicamento *m) {
    medicamento = m;
}

Medicamento* Nodo::getMedicamento() const {
    return medicamento;
}

void Nodo::setIzq(Nodo *n) {
    izq = n;
}

Nodo * Nodo::getIzq() const {
    return izq;
}

void Nodo::setDer(Nodo *n) {
    der = n;
}

Nodo * Nodo::getDer() const {
    return der;
}
