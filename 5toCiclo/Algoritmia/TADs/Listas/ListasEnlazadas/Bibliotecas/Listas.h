//
// Created by carlo on 4/30/2026.
//

#ifndef LISTASENLAZADAS_LISTAS_H
#define LISTASENLAZADAS_LISTAS_H

struct Dato {
    int numero;
};

struct Nodo {
    struct Dato dato;
    struct Nodo* sgte;
};

struct Lista {
    struct Nodo* inicio;
    int longitud;
};

#endif //LISTASENLAZADAS_LISTAS_H
