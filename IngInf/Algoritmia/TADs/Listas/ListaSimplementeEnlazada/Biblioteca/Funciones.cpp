//
// Created by carlo on 4/20/2026.
//

#include "Funciones.h"

#include <iostream>
using namespace std;

#include "Lista.h"

void construir(struct Lista& listaTAD) {
    listaTAD.inicio = nullptr;
    listaTAD.longitud = 0;
}

bool esListaVacia(const struct Lista& listaTAD) {
    return listaTAD.inicio == nullptr;
}

void insertarAlInicio(struct Lista& listaTAD,const struct ElementoLista& elemento) {
    struct NodoLista *nuevo;
    // crear este es importante porque si no, perdemos la referencia de listaTAD
    nuevo = new struct NodoLista;
    nuevo->elemento = elemento;
    nuevo->sgte = listaTAD.inicio;
    listaTAD.inicio = nuevo;
    listaTAD.longitud++;
}

void insertarAlFinal(struct Lista& listaTAD, const struct ElementoLista& elemento) {
    struct NodoLista* ultimoNodoLista = obtenerUltimoNodo(listaTAD);
    struct NodoLista *nuevo;
    nuevo = new struct NodoLista;
    nuevo->elemento = elemento;
    nuevo->sgte = nullptr;

    if (ultimoNodoLista == nullptr) { // si la lista esta vacia significa que
        listaTAD.inicio = nuevo; // este es nuestro inicio
    }
    else { // si la lista ya contiene elemento(s)
        ultimoNodoLista->sgte = nuevo; // entonces lo agregamos al final
    }
    listaTAD.longitud++;
}

struct NodoLista* obtenerUltimoNodo(const struct Lista& listaTAD) {
    struct NodoLista* ultimo = nullptr;
    struct NodoLista* recorrido = listaTAD.inicio;
    // necesitamos ambos para poder recorrer la lista
    // y saber cuando termina
    while (recorrido != nullptr) {
        ultimo = recorrido;
        recorrido = recorrido->sgte;
    }
    return ultimo;
}

void imprimir(const struct Lista& listaTAD) {
    // creamos una copia para recorrer la lista sin
    // afectar la original
    struct NodoLista* p;
    p = listaTAD.inicio;
    if (not esListaVacia(listaTAD)) {
        cout << "[";
        for (int i=0; p != nullptr ; i++) {
            if (i != 0) cout << ", ";
            cout << p->elemento.codigo;
            p= p->sgte;
        }
        cout << "]" << endl;
    }
    else {
        cout << "Lista vacia" << endl;
    }
}

void insertarEnOrden(struct Lista& listaTAD, const struct ElementoLista& elemento) {
    struct NodoLista* nuevo, *recorrido = listaTAD.inicio, *anterior = nullptr;
    nuevo = new struct NodoLista;
    nuevo->elemento = elemento;
    while (recorrido) {
        if (recorrido->elemento.codigo > elemento.codigo) break;
        anterior = recorrido;
        recorrido = recorrido->sgte;
    }
    nuevo->sgte = recorrido;
    if (anterior == nullptr) listaTAD.inicio = nuevo;
    else anterior->sgte = nuevo;
    listaTAD.longitud++;
}

void eliminaNodo(struct Lista& listaTAD, const struct ElementoLista& elemento) {
    struct NodoLista* ultimo = nullptr;
    struct NodoLista* recorrido = listaTAD.inicio;

    while ((recorrido != nullptr) and (recorrido->elemento.codigo != elemento.codigo)) {
        ultimo = recorrido;
        recorrido = recorrido->sgte;
    }

    if (recorrido != nullptr) {
        if (ultimo == nullptr) {
            listaTAD.inicio = recorrido->sgte;
        }
        else {
            ultimo->sgte = recorrido->sgte;
        }
        delete recorrido;
    }
    listaTAD.longitud--;
}

void destruir(struct Lista& listaTAD) {
    struct NodoLista* recorrido = listaTAD.inicio;
    struct NodoLista* sgte;

    while (recorrido != nullptr) {
        sgte = recorrido->sgte;
        delete recorrido;
        recorrido = sgte;
    }
    listaTAD.inicio = nullptr;
}

void invertirListaIterativa(struct Lista& lista) {
    struct NodoLista* ultimo;
    struct NodoLista* anteriorUltimo;

    // Para "guardar" el ultimo nodo que se convertira en la nueva cabeza de la lista
    struct NodoLista* ultimoNodo = obtenerUltimoNodo(lista);

    ultimo = obtenerUltimoNodo(lista);
    while (true) {
        anteriorUltimo = obtenerNodoAnterior(lista, ultimo->elemento);
        if (anteriorUltimo == nullptr) break;
        ultimo->sgte = anteriorUltimo;
        anteriorUltimo->sgte = nullptr;
        ultimo = anteriorUltimo;
    }
    lista.inicio = ultimoNodo;
}

struct NodoLista* obtenerNodoAnterior(const struct Lista& lista, const struct ElementoLista& elemento) {
    struct NodoLista *recorrido = lista.inicio, *anterior = nullptr;

    while (recorrido) {
        if (recorrido->elemento.codigo == elemento.codigo) break;
        anterior = recorrido;
        recorrido = recorrido->sgte;
    }
    if (recorrido == nullptr) return nullptr; // OJO
    return anterior;
}

void invertirListaRecursiva(struct Lista& lista, int n) {
    struct NodoLista* ultimo;
    struct NodoLista* anteriorUltimo;
    // CASO BASE
    if (n == 1) return;

    // PARTE RECURSIVA
    ultimo = obtenerUltimoNodo(lista);
    anteriorUltimo = obtenerNodoAnterior(lista, ultimo->elemento);
    ultimo->sgte = anteriorUltimo;
    anteriorUltimo->sgte = nullptr;
    invertirListaRecursiva(lista, n-1);

    lista.inicio = ultimo;
}