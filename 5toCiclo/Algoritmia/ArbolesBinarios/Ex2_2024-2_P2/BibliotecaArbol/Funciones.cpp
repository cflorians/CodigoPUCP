#include <iostream>
using namespace std;

#include "Arbol.h"

#include "Funciones.h"

void construir(Arbol& arbol) {
    arbol.raiz = nullptr;
}

void plantar(Arbol& arbol, Nodo* izq ,const Elemento& elemento, Nodo* der) {
    Nodo* nuevo = new Nodo;
    nuevo->elemento = elemento;
    nuevo->izq = izq;
    nuevo->der = der;
    arbol.raiz = nuevo;
}

void recorrePreOrden(const Arbol& arbol) {
    recorrePreOrden(arbol.raiz);
}

void recorrePreOrden(Nodo* nodo) {
    if (nodo != nullptr) {
        // cout << nodo->elemento.digito << " ";
        recorrePreOrden(nodo->izq);
        recorrePreOrden(nodo->der);
    }
}

void insertar(Arbol& arbol, const Elemento& elemento) {
    insertar(arbol.raiz, elemento);
}

void insertar(Nodo*& nodo, const Elemento& elemento) {
    if (nodo == nullptr) {
        Nodo* nuevo = new Nodo;
        nuevo->elemento = elemento;
        nuevo->izq = nullptr;
        nuevo->der = nullptr;
        nodo = nuevo;
        return;
    }

    if (elemento.posicion < nodo->elemento.posicion) insertar(nodo->izq, elemento);
    else insertar(nodo->der, elemento);
}

int maximo(const Arbol& arbol) {
    return maximo(arbol.raiz);
}
int maximo(Nodo* nodo) {
    if (nodo->der != nullptr) {
        return maximo(nodo->der);
    }
    return nodo->elemento.posicion;
}