//
// Created by Carlos on 5/21/2026.
//

#ifndef P2_ESTRUCTURAS_H
#define P2_ESTRUCTURAS_H

struct NodoA {
    char codigoISI[10];
    int prioridad;
    NodoA* sig;
};

struct ColaA {
    NodoA* inicio;
    NodoA* final;
};

struct NodoB {
    int detecto;
    int id;
    NodoB* sig;
};

struct ColaB {
    NodoB* inicio;
    NodoB* final;
};

struct PilaB {
    NodoB* inicio;
};

#endif //P2_ESTRUCTURAS_H
