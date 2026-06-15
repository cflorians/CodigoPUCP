//
// Created by Carlos on 8/06/2026.
//

#ifndef AB_NODO_H
#define AB_NODO_H
#include "Elemento.h"

struct Nodo {
    Elemento elemento;
    Nodo* izq; // Puntero a hijo 1
    Nodo* der; // Puntero a hijo 2
};

#endif //AB_NODO_H
