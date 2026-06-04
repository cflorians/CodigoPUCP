//
// Created by Carlos on 28/05/2026.
//

#include <cstring>
#include <fstream>
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

Virtual::Virtual(const Virtual &orig) {
    licencia = nullptr;
    total = 0;
    *this = orig;
}

void Virtual::operator=(const Virtual &orig) {
    Alumno::operator=(orig);
    total = orig.total;
    setLicencia(orig.licencia);
}

void Virtual::setLicencia(const char *lic) {
    if (licencia) delete[] licencia; licencia = nullptr;
    if (lic != nullptr) {
        licencia = new char[strlen(lic)+1];
        strcpy(licencia,lic);
    }
}

void Virtual::getLicencia(char *lic) {
    if (licencia == nullptr) lic[0] = 0;
    else strcpy(lic,licencia);
}

void Virtual::setTotal(double total) {
    this->total = total;
}

double Virtual::getTotal() const {
    return total;
}

void Virtual::leer(ifstream &arch) {
    char lic[20];
    Alumno::leer(arch);
    if (arch.eof()) return;
    arch.getline(lic, 20, '\n');
    setLicencia(lic);
}
