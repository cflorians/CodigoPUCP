//
// Created by Carlos on 10/06/2026.
//

#ifndef LISTACLASE_LISTA_H
#define LISTACLASE_LISTA_H
#include "Nodo.h"

class Lista {
private:
    class Nodo* lista;
    // Como le estamos dando el nodo, para protegerla:
    void imprimirRecursivo(ofstream& arch, Nodo* actual);
public:
    Lista(); // funcion construir
    ~Lista(); // funcion destruir

    void construir();
    void crear(const char* nombArch); // para llenar de archivo
    void insertar(Persona& dat);
    bool esListaVacia();
    void imprimir(const char* nombArch); // para mostrar la lista
};

#endif //LISTACLASE_LISTA_H
