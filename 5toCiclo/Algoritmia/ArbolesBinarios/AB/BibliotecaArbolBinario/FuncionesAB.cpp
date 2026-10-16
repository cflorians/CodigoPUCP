//
// Created by Carlos on 8/06/2026.
//
#include <iostream>
using namespace std;
#include "ArbolBinario.h"
#include "FuncionesAB.h"


void construir(ArbolBinario& arbol) {
    arbol.raiz = nullptr;
}

bool esArbolVacio(const ArbolBinario& arbol) {
    return (arbol.raiz == nullptr);
}

bool esNodoVacio(const Nodo *nodo) {
    return nodo == nullptr;
}

void plantarArbolBinario(ArbolBinario& arbol, const ArbolBinario& izq,
                         const Elemento& elem, const ArbolBinario& der) {
    plantarNodoArbolBinario(arbol.raiz, izq.raiz, elem, der.raiz);
};

void plantarNodoArbolBinario(Nodo*& nodo, Nodo* izq, const Elemento& elem, Nodo* der) {
    Nodo* nuevo = new Nodo;
    nuevo->izq = izq;
    nuevo->der = der;
    nuevo->elemento = elem;
    nodo = nuevo;
}

void imprimir(const ArbolBinario& arbol) {

}

void imprimeNodo(const Nodo *nodo) {
    cout << nodo->elemento.numero << "  ";
}

void recorrePreOrden(const ArbolBinario& arbol) {
    recorrePreOrdenRecursivo(arbol.raiz);
    cout << endl;
}

void recorrePreOrdenRecursivo(const Nodo* nodo) {
    if (not esNodoVacio(nodo)) {
        imprimeNodo(nodo);
        recorrePreOrdenRecursivo(nodo->izq);
        recorrePreOrdenRecursivo(nodo->der);
    }
}

void recorreEnOrden(const ArbolBinario& arbol) {
    recorreEnOrdenRecursivo(arbol.raiz);
    cout << endl;
}

void recorreEnOrdenRecursivo(const Nodo* nodo) {
    if (not esNodoVacio(nodo)) {
        recorreEnOrdenRecursivo(nodo->izq);
        imprimeNodo(nodo);
        recorreEnOrdenRecursivo(nodo->der);
    }
}

void recorrePostOrden(const ArbolBinario& arbol) {
    recorrePostOrdenRecursivo(arbol.raiz);
    cout << endl;
}

void recorrePostOrdenRecursivo(const Nodo* nodo) {
    if (not esNodoVacio(nodo)) {
        recorrePostOrdenRecursivo(nodo->izq);
        recorrePostOrdenRecursivo(nodo->der);
        imprimeNodo(nodo);
    }
}

int numeroHojas(const ArbolBinario& arbol) {
    return numeroHojasRecursivo(arbol.raiz);
}

int numeroHojasRecursivo(Nodo *nodo) {
    // CASOS BASE
    if (esNodoVacio(nodo)) {
        return 0;
    }
    if (esNodoVacio(nodo->izq) and esNodoVacio(nodo->der)) {
        return 1;
    }
    // PARTE RECURSIVA
    else {
        // cuenta cuantas hojas tiene su izq y las que tiene a la derecha
        return numeroHojasRecursivo(nodo->izq) + numeroHojasRecursivo(nodo->der);
    }
}

int numeroNodos(const ArbolBinario& arbol) {
    return numeroNodosRecursivo(arbol.raiz);
}

int numeroNodosRecursivo(Nodo *nodo) {
    // CASO BASE
    if (esNodoVacio(nodo)) {
        return 0;
    }
    // PARTE RECURSIVA
    else {
        // se cuenta a si mismo, y los nodos que hayan a su izq y a su der
        return 1 + numeroNodosRecursivo(nodo->izq) + numeroNodosRecursivo(nodo->der);
    }
}

int altura(const ArbolBinario& arbol) {
    return alturaRecursivo(arbol.raiz);
}

int alturaRecursivo(Nodo *nodo) {
    // CASO BASE
    if (esNodoVacio(nodo)) {
        return 0;
    }
    if (esNodoVacio(nodo->izq) and esNodoVacio(nodo->der)) {
        return 1;
    }
    // PARTE RECURSIVA
    else {
        // se suma a si mismo y el maximo de altura que tenga debajo de el
        return 1 + maximo(alturaRecursivo(nodo->izq), alturaRecursivo(nodo->der));
    }
}

int maximo(int a, int b) {
    return a >= b ? a : b;
}

bool esEquilibrado(const ArbolBinario& arbol) {
    return esEquilibradoRecursivo(arbol.raiz);
}

bool esEquilibradoRecursivo(Nodo *nodo) {
    if (esNodoVacio(nodo)) {
        return true;
    }
    else {
        // hallamos alturas izq y derecha
        int alturaHijoIzquierdo = alturaRecursivo(nodo->izq);
        int alturaHijoDerecho = alturaRecursivo(nodo->der);
        // Calculamos su diferencia y usamos abs() para que sea positiva
        int diferencia = abs(alturaHijoIzquierdo - alturaHijoDerecho);
        return diferencia <= 1 and
               esEquilibradoRecursivo(nodo->izq) and esEquilibradoRecursivo(nodo->der);
    }
}

void destruir(ArbolBinario& arbol) {
    destruirRecursivo(arbol.raiz);
    arbol.raiz = nullptr;
}

void destruirRecursivo(Nodo*& nodo) {
    if (not esNodoVacio(nodo)) {
        destruirRecursivo(nodo->izq);
        destruirRecursivo(nodo->der);
        nodo = nullptr;
    }
}