//
// Created by Carlos on 11/06/2026.
//

#ifndef ARBOLABB_ARBOL_H
#define ARBOLABB_ARBOL_H
#include "Nodo.h"

class Arbol {
private:
    class Nodo* raiz;
    // estos metodos van aqui porque tienen el NODO como parametro
    void destruir(Nodo* nodo);
    //void insertarRecursivo(Nodo*& nodo, int dato);
    void insertarRecursivo(Nodo*& nodo, const Persona& dato);
    void recorrerEnOrdenRecursivo(class Nodo* nodo, ofstream& arch);
public:
    Arbol();
    ~Arbol();
    void construir();
    void crearArbol(const char* nombArch);
    //void insertar(int dato);
    void insertar(const Persona& dato);
    void recorrerEnOrden(const char* nombArch);
};

#endif //ARBOLABB_ARBOL_H
