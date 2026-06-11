//
// Created by Carlos on 11/06/2026.
//

#ifndef LAB9_2023_1_TESORERIA_H
#define LAB9_2023_1_TESORERIA_H
#include "Boleta.h"
#include "Escala.h"

class Tesoreria {
private:
    Boleta lBoleta[100];
    Escala lEscala[10];
public:
    void cargaEscalas();
    void cargaAlumnos();
    void actualizaBoleta();
    void imprimeBoleta();
};

#endif //LAB9_2023_1_TESORERIA_H
