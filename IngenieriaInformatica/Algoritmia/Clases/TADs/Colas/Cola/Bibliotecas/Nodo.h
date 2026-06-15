//
// Created by carlo on 5/4/2026.
//

#ifndef COLAS_NODO_H
#define COLAS_NODO_H
#include "Elemento.h"
struct Nodo {
    struct Elemento elemento;
    struct Nodo* sgte;
};

#endif //COLAS_NODO_H
