#include <iostream>
using namespace std;

#include "Arbol.h"
#include "Pila.h"

#include "Funciones.h"

void construir(Arbol& arbol) {
    arbol.raiz = nullptr;
}

void ingresaLote(Arbol& arbol, const Elemento& elemento) {
    ingresaRecursivo(arbol.raiz, elemento);
}

void ingresaRecursivo(Nodo*& nodo, const Elemento& elemento) {
    if (nodo == nullptr) {
        // si el nodo esta vacio, entonces insertamos
        Nodo* nuevo = new Nodo;
        nuevo->elemento = elemento;
        nuevo->izq = nullptr;
        nuevo->der = nullptr;
        nodo = nuevo;
        return;
    }

    // si es que el anio del elemento es menor, vamos a la izq, si no, a la derecha
    if (elemento.anio < nodo->elemento.anio) {
        ingresaRecursivo(nodo->izq, elemento);
    }
    else if (elemento.anio > nodo->elemento.anio) {
        ingresaRecursivo(nodo->der, elemento);
    }
    // si es que son iguales, actualizamos la cantidad
    else if (elemento.anio == nodo->elemento.anio) {
        nodo->elemento.cantidad += elemento.cantidad;
    }
}

void imprimeNodo(Nodo* nodo) {
    cout << nodo->elemento.anio << "-" << nodo->elemento.cantidad << "  ";
}

void imprimir(const Arbol& arbol) {
    Pila pila;
    Nodo* actual = arbol.raiz;

    while (actual != nullptr or not esPilaVacia(pila)) {
        // vamos full derecha
        while (actual != nullptr) {
            push(pila, actual);
            actual = actual->der;
        }

        // sacamos el ultimo apilado
        actual = pila.cima;
        pop(pila);

        imprimeNodo(actual);

        actual = actual->izq;
    }
}

bool esPilaVacia(const Pila& pila) {
    return pila.cima == nullptr;
}

void push(Pila& pila, Nodo* nodo) {
    nodo->sig = pila.cima;
    pila.cima = nodo;
}

Nodo* pop(Pila& pila) {
    Nodo* actual = pila.cima;
    pila.cima = actual->sig;
    return actual;
}