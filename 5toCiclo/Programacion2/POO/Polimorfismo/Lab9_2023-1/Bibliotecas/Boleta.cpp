#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"
#include "Boleta.h"

Boleta::Boleta() {
    pAlumno = nullptr;
}

Boleta::~Boleta() {
    if (pAlumno) delete pAlumno;
}

void Boleta::inicializar(char tipo) {
    switch (tipo) {
        case 'P':
            pAlumno = new Presencial;
            break;
        case 'S':
            pAlumno = new Semipresencial;
            break;
        case 'V':
            pAlumno = new Virtual;
            break;
    }
}

void Boleta::leer(ifstream &arch) {
    pAlumno->lee(arch);
}

bool Boleta::existe() {
    return pAlumno != nullptr;
}

void Boleta::mostrar(ofstream &arch) const{
    pAlumno->imprime(arch);
}

void Boleta::actualizar() {
    pAlumno->actualizaTotal();
}
