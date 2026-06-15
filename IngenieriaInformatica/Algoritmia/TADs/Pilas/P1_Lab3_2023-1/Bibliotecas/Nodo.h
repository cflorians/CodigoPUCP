//
// Created by carlo on 5/14/2026.
//

#ifndef P1_LAB3_2023_1_NODO_H
#define P1_LAB3_2023_1_NODO_H
#include "Elemento.h"

struct Nodo {
    struct Elemento dato;
    struct Nodo *siguiente;
};

#endif //P1_LAB3_2023_1_NODO_H
