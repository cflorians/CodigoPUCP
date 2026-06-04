//
// Created by Carlos on 4/06/2026.
//

#ifndef LAB9_2023_1_TESORERIA_H
#define LAB9_2023_1_TESORERIA_H
#include "Boleta.h"
#include "Escala.h"

class Tesoreria {
private:
    Boleta lboleta[100];
    Escala lescala[20];
public:
    void cargaEscalas();
    void cargaAlumnos();
    void actualizaBoleta();
    void imprimeBoleta();
};

#endif //LAB9_2023_1_TESORERIA_H
