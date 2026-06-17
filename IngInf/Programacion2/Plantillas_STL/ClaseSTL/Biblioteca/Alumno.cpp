#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
#include "Alumno.h"

Alumno::Alumno(const string& nomb, int nta) {
    nombre = nomb;
    nota = nta;
}

void Alumno::mostrar() {
    cout << left << setw(12) << nombre
         << right << setw(2) << nota << " - "
         << (aprobo() ? "Aprobo" : "Desaprobo") << endl;
}

bool Alumno::aprobo() {
    return nota >= 11;
}

int Alumno::getNota() {
    return nota;
}

string Alumno::getNombre() {
    return nombre;
}
