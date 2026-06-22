//
// Created by Carlos on 8/06/2026.
//
#include <iostream>
#include <iomanip>
using namespace std;
#include "ArbolBinario.h"
#include "FuncionesAB.h"

void insertar(ArbolBinario& arbol, const Elemento& elemento) {
    insertarRecursivo(arbol.raiz, elemento);
}

void insertarRecursivo(Nodo*& raiz, const Elemento& elemento) {
    if (raiz == nullptr) { // Si esta vacio, es porque no tiene datos
        raiz = new Nodo;
        raiz->elemento = elemento;
        raiz->izq = nullptr;
        raiz->der = nullptr;
        return;
    }
    // Si es que no esta vacio, debemos buscar hacia donde tenemos que ir para colocarlo
    if (raiz->elemento.numero > elemento.numero) { // si es menor nos vamos a la izquierda
        insertarRecursivo(raiz->izq, elemento);
    }
    else if (raiz->elemento.numero < elemento.numero) { // si es mayor igual nos vamos a la derecha
        insertarRecursivo(raiz->der, elemento);
    }
    else {
        cout << "El elemento " << elemento.numero << " ya se encuentra en el arbol" << endl;
    }
}

bool buscar(ArbolBinario& arbol, const Elemento& elemento) {
    return buscarRecursivo(arbol.raiz, elemento);
}

bool buscarRecursivo(Nodo* nodo, const Elemento& elemento) {
    if (esNodoVacio(nodo)) {
        return false;
    }
    if (comparaElementos(nodo->elemento.numero, elemento.numero) == 0) {
        return true;
    }
    if (comparaElementos(nodo->elemento.numero, elemento.numero) == 1) {
        return buscarRecursivo(nodo->izq, elemento);
    }
    else {
        if (comparaElementos(nodo->elemento.numero, elemento.numero) == -1)
            return buscarRecursivo(nodo->der, elemento);
    }
}

int comparaElementos(int a, int b) {
    if (a > b) return 1;
    if (a < b) return -1;
    else return 0;
}

Nodo* eliminar(Nodo*& raiz, int valor) {
    if (raiz == nullptr) return nullptr;

    if (valor < raiz->elemento.numero) {
        // buscamos a su izq
        raiz->izq = eliminar(raiz->izq, valor);
    }
    else if (valor > raiz->elemento.numero) {
        // buscamos a su der
        raiz->der = eliminar(raiz->der, valor);
    }
    else {
        // Si es que encontramos el nodo
        // CASO 1, sin hijo izq
        if (raiz->izq == nullptr) {
            Nodo* temp = raiz->der;
            delete raiz;
            return temp;
        }
        // CASO 2, sin hijo der
        if (raiz->der == nullptr) {
            Nodo* temp = raiz->izq;
            delete raiz;
            return temp;
        }
        // CASO 3, tenemos 2 hijos
        // reemplazamos por el minimo del subArbol derecho
        Nodo* sucesor = encuentraMinimo(raiz->der);

        raiz->elemento = sucesor->elemento;
        // eliminamos el sucesor del arbol derecho
        Elemento elementoSucesor = sucesor->elemento;
        raiz->der = eliminar(raiz->der, elementoSucesor.numero);
    }
    return raiz;
}

Nodo* encuentraMinimo(Nodo* nodo) {
    while (nodo->izq) {
        nodo = nodo->izq;
    }
    return nodo;
}

// FUNCIONES TRAIDAS DEL ARBOL BINARIO

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


void imprimeNodo(const Nodo *nodo) {
    cout << setw(10) << nodo->elemento.numero << "-" << nodo->elemento.cantidad << "  ";
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