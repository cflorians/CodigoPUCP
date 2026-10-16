//
// Created by Carlos on 5/21/2026.
//

#ifndef P1_NODO_H
#define P1_NODO_H
#include "Elemento.h"

struct Nodo {
    Elemento elemento;
    Nodo* sgte;
};

#endif //P1_NODO_H
