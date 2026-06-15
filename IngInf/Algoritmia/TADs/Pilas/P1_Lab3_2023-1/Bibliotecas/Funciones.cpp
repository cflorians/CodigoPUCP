#include <iostream>
using namespace std;

#include "Pila.h"
#include "Funciones.h"

void construir(Pila& pila) {
    pila.inicio = nullptr;
    pila.longitud = 0;
}

void apilar(Pila& pila, const Elemento& elemento) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = elemento;
    nuevo->siguiente = nullptr;

    if (esPilaVacia(pila)) {
        pila.inicio = nuevo;
    }
    else {
        nuevo->siguiente = pila.inicio;
        pila.inicio = nuevo;
    }
    pila.longitud++;
}

bool esPilaVacia(Pila& pila) {
    return pila.inicio == nullptr;
}

Nodo* desapilar(Pila& pila) {
    Nodo* desapilado = pila.inicio;
    pila.inicio = pila.inicio->siguiente;
    pila.longitud--;
    return desapilado;
}

Nodo* cima(const Pila& pila) {
    return pila.inicio;
}

void imprimir(Pila& pila) {
    Nodo* actual = pila.inicio;
    while (actual) {
        cout << actual->dato.num;
        if (actual->siguiente) cout << " -> ";
        actual = actual->siguiente;
    }
    cout << endl;
}

void unirPilas(Pila& pila1, Pila& pila2) {
    while (pila2.inicio) {
        apilar(pila1, desapilar(pila2)->dato);
        pila1.longitud++;
        pila2.longitud--;
    }
}

void ordenarPila(Pila& pila1, Pila& pila2) {
    while (not esPilaVacia(pila1)) {
        Nodo* actual = desapilar(pila1);

        while (not esPilaVacia(pila2) and cima(pila2)->dato.num < actual->dato.num) {
            apilar(pila1, desapilar(pila2)->dato);
        }
        apilar(pila2, actual->dato);
    }

    while (not esPilaVacia(pila2)) {
        apilar(pila1, desapilar(pila2)->dato);
    }
}

void pasaPila(Pila& org, Pila& dest) {
    if (org.inicio == nullptr) return;

    Nodo* temp = desapilar(org);

    pasaPila(org, dest);

    apilar(dest, temp->dato);
}