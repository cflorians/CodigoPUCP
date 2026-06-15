//
// Created by carlo on 5/14/2026.
//

#ifndef P1_EXA_2022_2_NODO_H
#define P1_EXA_2022_2_NODO_H
#include "Elemento.h"

struct Nodo {
    struct Elemento elemento;
    struct Nodo* sgte;
};

#endif //P1_EXA_2022_2_NODO_H
