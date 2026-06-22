#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Semipresencial.h"

Semipresencial::Semipresencial() {
    descuento = 0;
    total = 0;
}

void Semipresencial::setDescuento(double desc) {
    descuento = desc;
}

void Semipresencial::setTotal(double tot) {
    total = tot;
}

double Semipresencial::getDescuento() const {
    return descuento;
}

double Semipresencial::getTotal() const {
    return total;
}

void Semipresencial::lee(ifstream &arch) {
    // 202123703,GAMARRA/TABORI/PAUL-RONAL,5,20,30
    Alumno::leer(arch);
    // 30
    if (arch.eof()) return;
    arch >> descuento;
    arch.get();
}

void Semipresencial::imprime(ofstream &arch) {
    imprimir(arch);
    arch << right << setw(20) << fixed << setprecision(2) << Alumno::getTotal() << endl;
}

void Semipresencial::actualizaTotal() {
}
