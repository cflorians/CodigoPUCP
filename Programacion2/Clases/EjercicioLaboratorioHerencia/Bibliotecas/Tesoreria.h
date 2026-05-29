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
    Presencial* lpresencial; // memoria exacta
    Semipresencial lsemipresencial[100]; // uso de arreglos
    Virtual* lvirtual; // memoria por incrementos
    Escala lescala[10];
public:
    Tesoreria();
    ~Tesoreria();

    void incrementarLosEspacios(Virtual*& lvirtual, int& numDatos, int& capacidad);

    void cargaescalas(const char* nombArch);
    void cargaalumnos(const char* nombArch);
    void actualiza(double creditos);
    void imprime(const char* nombArch);
};

#endif //EJERCICIOLABORATORIOHERENCIA_TESORERIA_H
