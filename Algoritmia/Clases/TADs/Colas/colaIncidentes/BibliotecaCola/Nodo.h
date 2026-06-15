//
// Created by carlo on 5/4/2026.
//

#ifndef COLAS_NODO_H
#define COLAS_NODO_H
#include "Elemento.h"
struct NodoCola {
    struct ElementoCola elemento;
    struct NodoCola* sgte;
};

#endif //COLAS_NODO_H
