//
// Created by Carlos on 10/06/2026.
//

#ifndef LISTACLASE_NODO_H
#define LISTACLASE_NODO_H
#include "Persona.h"

class Nodo {
    // dato o elemento de la lista
private:
    // int dato;
    class Persona dato;
    class Nodo* sig;
public:
    Nodo();

    friend class Lista;
};

#endif //LISTACLASE_NODO_H
