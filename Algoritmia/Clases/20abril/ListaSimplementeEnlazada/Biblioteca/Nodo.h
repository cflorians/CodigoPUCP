//
// Created by carlo on 4/20/2026.
//

#ifndef LISTASIMPLEMENTEENLAZADA_NODO_H
#define LISTASIMPLEMENTEENLAZADA_NODO_H
#include "Elemento.h"

struct NodoLista {
    struct ElementoLista elemento;
    struct NodoLista *sgte;
};

#endif //LISTASIMPLEMENTEENLAZADA_NODO_H
