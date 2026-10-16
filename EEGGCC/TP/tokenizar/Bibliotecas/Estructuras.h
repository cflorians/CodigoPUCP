

#ifndef TOKENIZAR_ESTRUCTURAS_H
#define TOKENIZAR_ESTRUCTURAS_H

struct Comentario {
    char comentario[100];
    int polaridad;
};

struct Nodo {
    struct Comentario comentario;
    struct Nodo* sgte;
};

#endif //TOKENIZAR_ESTRUCTURAS_H