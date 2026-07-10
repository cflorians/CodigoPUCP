//
// Created by carlo on 4/27/2026.
//

#include "Funciones.h"

#include <cstring>
#include <iostream>

using namespace std;

#include "Pila.h"

#define MAX 10

void construir(struct Pila& pila) {
    pila.inicio = nullptr;
    pila.longitud = 0;
}

void apilar(struct Pila& pila, struct ElementoPila elemento) {
    struct NodoPila* nodo = new struct NodoPila;
    nodo->elemento = elemento;
    nodo->sgte = pila.inicio;
    pila.inicio = nodo;
}

struct NodoPila* cima(const struct Pila& pila) {
    return pila.inicio;
}

void imprimir(const struct Pila& pila) {
    struct NodoPila* actual = pila.inicio;
    cout << "[";
    while (actual != nullptr) {
        cout << actual->elemento.id;
        if (actual->sgte != nullptr) {
            cout << ", ";
        }
        actual = actual->sgte;
    }
    cout << "]" << endl;
}

struct NodoPila* desapilar(struct Pila& pila) {
    if (pila.inicio != nullptr) {
        struct NodoPila* aux = pila.inicio;
        pila.inicio = aux->sgte;
        return aux;
    }
}
