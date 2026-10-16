//
// Created by Carlos on 4/06/2026.
//
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "Virtual.h"

Virtual::Virtual() {
    licencia = nullptr;
    total = 100;
}

Virtual::~Virtual() {
    if (licencia) delete[] licencia;
}

Virtual::Virtual(const Virtual &org) {
    licencia = nullptr;
    total = 100;
    *this = org;
}

void Virtual::operator=(const Virtual &org) {
    setLicencia(org.licencia);
    setTotal(org.total);
}

void Virtual::setLicencia(const char *lic) {
    if (licencia) delete[] licencia;
    licencia = new char[strlen(lic)+1];
    strcpy(licencia,lic);
}

void Virtual::setTotal(double tot) {
    total = tot;
}

void Virtual::getLicencia(char *lic) {
    if (licencia == nullptr) lic[0] = 0;
    else strcpy(lic,licencia);
}

double Virtual::getTotal() const {
    return total;
}

void Virtual::calcularTotal(int cantCreditos, double escala) {
    double tot = (cantCreditos*escala);
    setTotal(total + tot);
    Alumno::setTotal(total + tot);
}

void operator>>(ifstream &arch, Virtual &v) {
    v.leer(arch);
    // 323R33-2,3
    // licencia, escala
    char lic[20];
    int escala;
    arch.getline(lic, 20, ',');
    arch >> escala;

    v.setLicencia(lic);
    v.setEscala(escala);
}

void operator<<(ofstream &arch, Virtual &v) {
    v.mostrar(arch);
    char lic[20];
    v.getLicencia(lic);
    arch << setw(7) << " "
         << lic << setw(26-strlen(lic)) << fixed << right << setprecision(2) << v.getTotal() << endl;
}
