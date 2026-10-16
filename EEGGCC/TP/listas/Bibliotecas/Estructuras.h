
#ifndef LISTAS_ESTRUCTURAS_H
#define LISTAS_ESTRUCTURAS_H

struct Datos {
    int dni;
    char* nombre;
    double sueldo;
};

struct Nodo {
    struct Datos datos;
    struct Nodo* next;
};

#endif //LISTAS_ESTRUCTURAS_H