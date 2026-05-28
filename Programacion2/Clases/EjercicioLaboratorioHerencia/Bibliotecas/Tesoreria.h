//
// Created by Carlos on 28/05/2026.
//

#ifndef EJERCICIOLABORATORIOHERENCIA_TESORERIA_H
#define EJERCICIOLABORATORIOHERENCIA_TESORERIA_H
#include "Escala.h"
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"

class Tesoreria {
private:
    Presencial* lpresencial;
    Semipresencial lsemipresencial[100];
    Virtual lvirtual[100];
    Escala lescala[10];
public:
    Tesoreria();
    ~Tesoreria();

    void cargaescalas(const char* nombArch);
    void cargaalumnos(const char* nombArch);
    void actualiza(int creditos);
    void imprime(const char* nombArch);
};

#endif //EJERCICIOLABORATORIOHERENCIA_TESORERIA_H
