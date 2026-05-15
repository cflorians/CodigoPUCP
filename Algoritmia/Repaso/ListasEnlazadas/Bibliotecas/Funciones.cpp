#include <iostream>
using namespace std;

#include "Listas.h"
#include "Funciones.h"

void insertarAlFinal(struct Lista& lista, struct Dato dato) {
    struct Nodo* nuevo = new struct Nodo;
    nuevo->dato = dato;
    nuevo->sgte = nullptr;
    struct Nodo* recorrido = lista.inicio;
    struct Nodo* ultimo = nullptr;
    while (recorrido) {
        ultimo = recorrido;
        recorrido = recorrido->sgte;
    }
    if (ultimo) ultimo->sgte = nuevo;
    else lista.inicio = nuevo;
    lista.longitud++;
}

void imprimirLista(const struct Lista& lista) {
    struct Nodo* actual = lista.inicio;
    for (int i = 0; i < lista.longitud; i++) {
        if (i==0) cout << "[";
        cout << actual->dato.numero;
        if (i!=lista.longitud-1) cout << ", ";
        if (i==lista.longitud-1) cout << "]";
        actual = actual->sgte;
    }
    cout << endl;
}

void eliminarRepetidos(struct Lista& lista) {
    // Como la lista esta ordenada, los datos iguales estan juntos
    struct Nodo* actual = lista.inicio;
    struct Nodo* siguiente = actual->sgte;
    struct Nodo* aEliminar = nullptr;
    for (int i = 0; i < lista.longitud; i++) {
        if (actual->dato.numero == siguiente->dato.numero) {
            aEliminar = siguiente;
            siguiente = siguiente->sgte;
            actual->sgte = siguiente;
            aEliminar->sgte = nullptr;
            delete aEliminar;
            lista.longitud--;
        }
        else {
            actual = siguiente;
            siguiente = siguiente->sgte;
        }
    }
}

void moverMayorAInicio(struct Lista& lista) {
    struct Nodo* mayor = lista.inicio;
    struct Nodo* antMayor = nullptr;
    hallarMayor(lista, mayor, antMayor);
    antMayor->sgte = mayor->sgte;
    mayor->sgte = lista.inicio;
    lista.inicio = mayor;
}

void hallarMayor(const struct Lista& lista, struct Nodo*& mayor, struct Nodo*& antMayor) {
    struct Nodo* actual = lista.inicio;
    struct Nodo* anterior = nullptr;
    for (int i = 0; i < lista.longitud; i++) {
        if (mayor->dato.numero < actual->dato.numero) {
            mayor = actual;
            antMayor = anterior;
        }
        anterior = actual;
        actual = actual->sgte;
    }
}

void reordenarLista(struct Lista& lista) {
    struct Nodo* inicioMenores = nullptr;
    struct Nodo* finMenores = nullptr;
    struct Nodo* inicioMayores = nullptr;
    struct Nodo* finMayores = nullptr;
    struct Nodo* actual = lista.inicio;
    while (actual) {
        if (actual->dato.numero < 15) {
            // significa que es menor
            if (inicioMenores == nullptr) {
                inicioMenores = actual;
                finMenores = actual;
            }
            else {
                finMenores->sgte = actual;
                finMenores = actual;
            }
        }
        else {
            // significa que es >= 15
            if (inicioMayores == nullptr) {
                inicioMayores = actual;
                finMayores = actual;
            }
            else {
                finMayores->sgte = actual;
                finMayores = actual;
            }
        }
        actual = actual->sgte;
    }
    // ahora juntamos menores con mayores
    if (inicioMenores != nullptr) lista.inicio = inicioMenores;
    else lista.inicio = inicioMayores;
    finMenores->sgte = inicioMayores;
    finMayores->sgte = nullptr;
}