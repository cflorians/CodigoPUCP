#include <iostream>
using namespace std;

#include "Arbol.h"
#include "Funciones.h"

void construir(Arbol& arbol) {
    arbol.raiz = nullptr;
}

void insertaDiaTurno(Nodo*& nodo, const Elemento& elemento) {
    if (nodo == nullptr) {
        Nodo* nuevo = new Nodo();
        nuevo->izq = nullptr;
        nuevo->der = nullptr;
        nuevo->dato = elemento;
        nodo = nuevo;
    }
    else {
        if (nodo->dato.clave < elemento.clave) {
            // si es mayor nos vamos a la derecha
            insertaDiaTurno(nodo->der, elemento);
        }
        else {
            insertaDiaTurno(nodo->izq, elemento);
        }
    }
}

void imprimeNodo(Nodo* nodo) {
    cout << nodo->dato.dia << "-" << nodo->dato.turno << "  ";
}

void imprime(Nodo* nodo) {
    if (nodo != nullptr) {
        imprime(nodo->izq);
        imprimeNodo(nodo);
        imprime(nodo->der);
    }
}

int cantNiveles(Nodo* nodo) {
    // CASO BASE
    if (nodo == nullptr) return 0;

    // PARTE RECURSIVA
    int cantidadNivelesIzq = cantNiveles(nodo->izq);
    int cantidadNivelesDer = cantNiveles(nodo->der);

    return max(cantidadNivelesIzq, cantidadNivelesDer) + 1;
}

bool estaBalanceado(Nodo* nodo) {
    // CASO BASE
    if (nodo == nullptr) return true;

    int izq = cantNiveles(nodo->izq);
    int der = cantNiveles(nodo->der);

    int diff = abs(izq - der);

    if (diff <= 1 and estaBalanceado(nodo->izq) and estaBalanceado(nodo->der)) {
        return true;
    }
    else {
        return false;
    }
}

void insertaEnMitades(Elemento A[], Nodo*& nodo, int ini, int fin, int tipo){
    // CASO BASE
    if (ini > fin) return;
    // PARTE RECURSIVA
    int mid = (ini + fin) / 2;

    if (tipo == 1) {
        insertaDiaTurno(nodo, A[mid]);
    }
    else {
        insertaCantidades(nodo, A[mid]);
    }

    insertaEnMitades(A, nodo, ini, mid-1,tipo);
    insertaEnMitades(A, nodo, mid+1, fin, tipo);
}

void insertaCantidades(Nodo*& nodo, const Elemento& elemento) {
    if (nodo == nullptr) {
        Nodo* nuevo = new Nodo();
        nuevo->izq = nullptr;
        nuevo->der = nullptr;
        nuevo->dato = elemento;
        nodo = nuevo;
    }
    else {
        if (nodo->dato.cantidades == elemento.cantidades) {
            if (nodo->dato.clave < elemento.clave) {
                // si es mayor nos vamos a la izquierda
                insertaCantidades(nodo->izq, elemento);
            }
            else {
                insertaCantidades(nodo->der, elemento);
            }
        }
        else {
            if (nodo->dato.cantidades < elemento.cantidades) {
                // si es mayor nos vamos a la izquierda
                insertaCantidades(nodo->izq, elemento);
            }
            else {
                insertaCantidades(nodo->der, elemento);
            }
        }
    }
}