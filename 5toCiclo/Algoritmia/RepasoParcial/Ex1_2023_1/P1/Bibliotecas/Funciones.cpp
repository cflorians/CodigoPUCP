//
// Created by Carlos on 5/21/2026.
//
#include "Pila.h"
#include "Funciones.h"

void construir(Pila& pila) {
    pila.inicio = nullptr;
    pila.longitud = 0;
}

void apilar(Pila& pila, const Elemento& elemento) {
    Nodo* nuevo = new Nodo;
    nuevo->elemento = elemento;
    nuevo->sgte = nullptr;

    if (pila.inicio == nullptr) {
        pila.inicio = nuevo;
    }
    else {
        nuevo->sgte = pila.inicio;
        pila.inicio = nuevo;
    }
    pila.longitud++;
}

Elemento desapilar(Pila& pila) {
    if (pila.inicio != nullptr) {
        Elemento desapilado = pila.inicio->elemento;
        pila.inicio = pila.inicio->sgte;
        pila.longitud--;
        return desapilado;
    }
    else return {-1};
}