//
// Created by Carlos on 11/06/2026.
//

#ifndef ARBOLABB_NODO_H
#define ARBOLABB_NODO_H
#include "Persona.h"
class Nodo {
private:
    //int dato;
    Persona dato;
    class Nodo* izq;
    class Nodo* der;
public:
    Nodo();
    friend class Arbol;
};

#endif //ARBOLABB_NODO_H
