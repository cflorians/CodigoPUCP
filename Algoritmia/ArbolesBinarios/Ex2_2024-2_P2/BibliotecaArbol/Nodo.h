//
// Created by Carlos on 9/07/2026.
//

#ifndef EX2_2024_2_P2_NODO_H
#define EX2_2024_2_P2_NODO_H
#include "Elemento.h"

struct Nodo {
    Elemento elemento;
    Nodo* izq;
    Nodo* der;
};

#endif //EX2_2024_2_P2_NODO_H
