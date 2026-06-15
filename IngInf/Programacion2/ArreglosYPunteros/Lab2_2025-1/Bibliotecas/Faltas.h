//
// Created by carlo on 4/16/2026.
//

#ifndef LAB2_2025_1_FALTAS_H
#define LAB2_2025_1_FALTAS_H
#include "Conductores.h"
#include "Infracciones.h"
struct Faltas {
    // Asignacion por incrementos de a 2
    Conductores conductores;
    Infracciones infracciones;

    char ***placas;
    int *capacidades;
};

#endif //LAB2_2025_1_FALTAS_H
