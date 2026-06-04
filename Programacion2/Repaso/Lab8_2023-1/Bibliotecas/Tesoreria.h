//
// Created by Carlos on 4/06/2026.
//

#ifndef LAB8_2023_1_TESORERIA_H
#define LAB8_2023_1_TESORERIA_H
#include "Escala.h"
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"

class Tesoreria {
private:
    Presencial lPresencial[100];
    Semipresencial lSemipresencial[100];
    Virtual lVirtual[100];
    Escala lEscala[20];
public:
    void cargaEscala(const char* nombArch);
    void cargaAlumnos(const char* nombArch);
    void actualiza(int num);
    void imprime(const char* nombArch);
};

#endif //LAB8_2023_1_TESORERIA_H
