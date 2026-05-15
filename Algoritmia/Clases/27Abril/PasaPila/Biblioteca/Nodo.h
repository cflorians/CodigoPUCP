//
// Created by carlo on 4/27/2026.
//

#ifndef EJERCICIOPILA_NODO_H
#define EJERCICIOPILA_NODO_H
#include "Elemento.h"

struct Nodo {
    struct Elemento elemento;
    struct Nodo* sgte;
};

#endif //EJERCICIOPILA_NODO_H
