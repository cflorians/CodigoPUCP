#include <iostream>
using namespace std;
#include "Gato.h"


Gato::Gato() {
    dentroCasa = false;
}

Gato::~Gato() {
    cout << "Destruyendo a gato" << endl;
}

void Gato::setDentroCasa(bool dentro) {
    dentroCasa = dentro;
}

bool Gato::getDentroCasa() const {
    return dentroCasa;
}

void Gato::mostrar() {
    cout << "=====GATO=====" << endl;
    Animal::mostrar();
    cout << "Vive dentro de casa?: " << (dentroCasa ? "Si" : "No") << endl;
    cout << "Hace: miau" << endl;
    cout << endl;
}
