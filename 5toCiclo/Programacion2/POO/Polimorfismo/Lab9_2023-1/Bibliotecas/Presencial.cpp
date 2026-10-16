#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Presencial.h"

Presencial::Presencial() {
    recargo = 0;
    total = 0;
}

void Presencial::setRecargo(double rec) {
    recargo = rec;
}

void Presencial::setTotal(double tot) {
    total = tot;
}

double Presencial::getRecargo() const {
    return recargo;
}

double Presencial::getTotal() const {
    return total;
}

void Presencial::lee(ifstream &arch) {
    // 202119153,MENDOZA/ARIAS/HENRY,4,19.5,10
    Alumno::leer(arch);
    // 10
    if (arch.eof()) return;
    arch >> recargo;
    arch.get();
}

void Presencial::imprime(ofstream &arch) {
    imprimir(arch);
    arch << right << setw(20) << fixed << setprecision(2) << Alumno::getTotal() << endl;
}

void Presencial::actualizaTotal() {

}
