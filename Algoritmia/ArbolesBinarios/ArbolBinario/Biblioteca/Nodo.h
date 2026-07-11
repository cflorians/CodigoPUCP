//
// Created by Carlos on 10/07/2026.
//

#ifndef ARBOLBINARIO_NODO_H
#define ARBOLBINARIO_NODO_H
#include "Elemento.h"
struct Nodo {
    Elemento elemento;
    Nodo* izq;
    Nodo* der;
};
#endif //ARBOLBINARIO_NODO_H
