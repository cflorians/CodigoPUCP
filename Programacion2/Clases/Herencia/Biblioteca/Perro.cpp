//
// Created by Carlos on 5/27/2026.
//
#include <iostream>
using namespace std;
#include "Perro.h"

Perro::Perro() {
    esDomestico = true;
}

Perro::~Perro() {
    cout << "Destruyendo perro" << endl;
}

void Perro::setDomestico(bool domestico) {
    esDomestico = domestico;
}

bool Perro::getDomestico() const {
    return esDomestico;
}

void Perro::mostrar() {
    cout << "=====PERRO=====" << endl;
    Animal::mostrar();
    cout << "Es domestico? " << (esDomestico ? "Si" : "No") << endl;
    cout << "Hace guau guau" << endl;
    cout << endl;
}
