//
// Created by Carlos on 4/06/2026.
//
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Presencial.h"

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

void Presencial::calcularTotal(int cantCreditos, double escala) {
    double tot = (cantCreditos*escala)*((100+recargo)/100);
    setTotal(tot);
    Alumno::setTotal(tot);
}

void operator>>(ifstream &arch, Presencial &p) {
    p.leer(arch);
    // 10,4
    // recargo, escala
    int recargo, escala;
    arch >> recargo;
    arch.get();
    arch >> escala;

    p.setRecargo(recargo);
    p.setEscala(escala);
}

void operator<<(ofstream &arch, Presencial &p) {
    p.mostrar(arch);
    arch << setw(33) << right << fixed << setprecision(2) << p.getTotal() << endl;
}
