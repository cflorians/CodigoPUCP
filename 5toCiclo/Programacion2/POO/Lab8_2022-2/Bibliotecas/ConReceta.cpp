#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "ConReceta.h"

ConReceta::ConReceta() {
    especialidad = nullptr;
    codMed = 0;
}

ConReceta::~ConReceta() {
    if (especialidad) delete[] especialidad;
    codMed = 0;
}

ConReceta::ConReceta(const ConReceta &org) {
    especialidad = nullptr;
    codMed = 0;
    *this = org;
}

void ConReceta::operator=(const ConReceta &org) {
    Medicamentos::operator=(org);
    setEspecialidad(org.especialidad);
    setCodMed(org.codMed);
}

void ConReceta::setCodMed(int cod) {
    codMed = cod;
}

void ConReceta::setEspecialidad(const char *esp) {
    if (especialidad) delete[] especialidad;
    especialidad = new char[strlen(esp)+1];
    strcpy(especialidad, esp);
}

int ConReceta::getCodMed() const {
    return codMed;
}

void ConReceta::getEspecialidad(char *esp) {
    if (especialidad == nullptr) esp[0] = 0;
    else strcpy(esp, especialidad);
}
