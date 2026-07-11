//
// Created by carlo on 5/4/2026.
//

#ifndef COLAS_NODO_H
#define COLAS_NODO_H
#include "../Biblioteca/Elemento.h"
struct NodoCola {
    Elemento elemento;
    NodoCola* sgte;
};

#endif //COLAS_NODO_H
