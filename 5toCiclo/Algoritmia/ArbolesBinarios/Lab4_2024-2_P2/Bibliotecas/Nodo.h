//
// Created by Carlos on 1/07/2026.
//

#ifndef LAB4_2024_2_P2_NODO_H
#define LAB4_2024_2_P2_NODO_H
#include "Elemento.h"

struct Nodo {
    Elemento elemento;
    Nodo* der;
    Nodo* izq;
    Nodo* sig;
};

#endif //LAB4_2024_2_P2_NODO_H
