//
// Created by Carlos on 5/26/2026.
//

#ifndef P3_NODO_H
#define P3_NODO_H
#include "Elemento.h"

struct Nodo {
    Elemento dato;
    Nodo* next;
    Nodo* skip_next;
};

#endif //P3_NODO_H
