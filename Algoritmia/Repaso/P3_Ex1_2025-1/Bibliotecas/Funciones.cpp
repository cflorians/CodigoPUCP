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
    nuevo->sgte = nullptr;

    if (esPilaVacia(pila)) {
        pila.inicio = nuevo;
    }
    else {
        nuevo->sgte = pila.inicio;
        pila.inicio = nuevo;
    }
    pila.longitud++;
}

Nodo* desapilar(Pila& pila) {
    Nodo* desapilado = pila.inicio;
    pila.inicio = pila.inicio->sgte;
    pila.longitud--;
    return desapilado;
}

Nodo* cima(Pila& pila) {
    return pila.inicio;
}

bool esPilaVacia(Pila& pila) {
    return pila.inicio == nullptr;
}

Elemento minimo(Pila& pila, Pila& aux) {
    // CASO BASE
    // cuando es pila vacia
    if (esPilaVacia(pila)) return cima(aux)->dato;

    // PARTE RECURSIVA
    // Desapilamos de pila y apilamos en aux
    Elemento actual = desapilar(pila)->dato;
    apilar(aux, actual);

    // Entramos a la siguiente recursion, luego de haber movido
    // un elemento de pila a aux
    Elemento min = minimo(pila, aux);

    // Cuando regresamos, comparamos el actual
    // con el minimo hallado hasta ahora
    if (actual.cod < min.cod) return actual;
    return min;
}