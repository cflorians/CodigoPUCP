#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Virtual.h"

Virtual::Virtual() {
    licencia = nullptr;
    total = 0;
}

Virtual::~Virtual() {
    if (licencia) delete[] licencia;
    total = 0;
}

Virtual::Virtual(const Virtual &org){
    licencia = nullptr;
    total = 0;
    *this = org;
}

void Virtual::operator=(const Virtual &org) {
    Alumno::operator=(org);
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

void Virtual::lee(ifstream &arch) {
    // 202318072,RIVERA/MONTERO/GLORIA-OFELIA,3,20,323R33-2
    Alumno::leer(arch);
    // 323R33-2
    if (arch.eof()) return;;
    char lic[10];
    arch.getline(lic,10,'\n');
    setLicencia(lic);
}

void Virtual::imprime(ofstream &arch) {
    imprimir(arch);
    char lic[10];
    getLicencia(lic);
    arch << left << setw(10) << lic
         << right << setw(10) << fixed << setprecision(2) << Alumno::getTotal() << endl;
}

void Virtual::actualizaTotal() {
}
