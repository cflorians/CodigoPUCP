#include <iostream>
using namespace std;

#include "Arbol.h"

#include "Funciones.h"

void construir(Arbol& arbol) {
    arbol.raiz = nullptr;
}

void plantar(Arbol& arbol, const Elemento& elemento,
             Nodo* izq, Nodo* der) {
    Nodo* nuevo = new Nodo;
    nuevo->elemento = elemento;
    nuevo->izq = izq;
    nuevo->der = der;
    arbol.raiz = nuevo;
}