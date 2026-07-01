//
// Created by Carlos on 30/06/2026.
//

#ifndef LAB4_2024_2_NODO_H
#define LAB4_2024_2_NODO_H
#include "Elemento.h"

struct Nodo {
    Elemento elemento;
    Nodo* izq;
    Nodo* der;
};

#endif //LAB4_2024_2_NODO_H
