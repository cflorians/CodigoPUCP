//
// Created by carlo on 4/27/2026.
//

#ifndef EJERCICIOPILA_NODO_H
#define EJERCICIOPILA_NODO_H
#include "Elemento.h"
struct NodoPila {
    struct ElementoPila elemento;
    struct NodoPila* sgte;
};

#endif //EJERCICIOPILA_NODO_H
