//
// Created by Carlos on 4/06/2026.
//
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Semipresencial.h"

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

void Semipresencial::calcularTotal(int cantCreditos, double escala) {
    double tot = (cantCreditos*escala)*((100-descuento)/100);
    setTotal(tot);
    Alumno::setTotal(tot);
}

void operator>>(ifstream &arch, Semipresencial &s) {
    s.leer(arch);
    // 30,5
    // descuento, escala
    double descuento;
    int escala;
    arch >> descuento;
    arch.get();
    arch >> escala;

    s.setDescuento(descuento);
    s.setEscala(escala);
}

void operator<<(ofstream &arch, Semipresencial &s) {
    s.mostrar(arch);
    arch << setw(33) << right << fixed << setprecision(2) << s.getTotal() << endl;
}
