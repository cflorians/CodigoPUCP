//
// Created by Carlos on 26/06/2026.
//

#ifndef LAB5_2024_2_NODO_H
#define LAB5_2024_2_NODO_H

#include "Elemento.h"
struct Nodo {
    Elemento dato;
    Nodo* izq;
    Nodo* der;
};

#endif //LAB5_2024_2_NODO_H
