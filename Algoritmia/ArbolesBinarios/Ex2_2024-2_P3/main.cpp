#include <iostream>
using namespace std;

#include "BibliotecaArbol/ArbolBinario.h"
#include "BibliotecaArbol/FuncionesAB.h"

#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/Funciones.h"

#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/Funciones.h"

void diagonal(const ArbolBinario& arbol) {
    Nodo* raiz = arbol.raiz;

    Cola cola;
    construir(cola);

    encolar(cola, {raiz->elemento.flag, raiz->elemento.id});

    while (not esColaVacia(cola)) {
        // buscamos el elemento de la cola
        ElementoCola elemento= desencolar(cola);
        Nodo* actual = buscaElemento(arbol, {elemento.flag, elemento.id});


        while (actual != nullptr) {
            // imprimimos el actual
            cout << actual->elemento.flag << "-" << actual->elemento.id << "  ";

            // si tiene hijo a la izq, encolamos
            if (actual->izq != nullptr) {
                encolar(cola, {actual->izq->elemento.flag, actual->izq->elemento.id});
            }

            // pasamos al siguiente de la derecha
            if (actual->der != nullptr) actual = actual->der;
            else break;
        }
    }
    cout << endl;
}

void diagonalInversa(const ArbolBinario& arbol) {
    // Aplicamos la misma estrategia que antes, pero en lugar de imprimir,
    // apilaremos para imprimir al llegar al final de la diagonal
    Nodo* raiz = arbol.raiz;

    Cola cola;
    construir(cola);

    Pila pila;
    construir(pila);


    encolar(cola, {raiz->elemento.flag, raiz->elemento.id});

    while (not esColaVacia(cola)) {
        // buscamos el elemento de la cola
        ElementoCola elemento= desencolar(cola);
        Nodo* actual = buscaElemento(arbol, {elemento.flag, elemento.id});

        while (actual != nullptr) {
            // apilamos el actual
            apilar(pila, {actual->elemento.flag, actual->elemento.id});

            if (actual->izq != nullptr) {
                encolar(cola, {actual->izq->elemento.flag, actual->izq->elemento.id});
            }
            // pasamos al siguiente de la derecha
            if (actual->der != nullptr) actual = actual->der;
            else break;
        }
    }

    while (cima(pila)) {
        ElementoPila elem = desapilar(pila)->elemento;
        cout << elem.flag << "-" << elem.id << "  ";
    }
    cout << endl;
}

int main() {

    ArbolBinario red;

    construir(red);

    insertar(red,{false,100});
    insertar(red,{false,50});
    insertar(red,{false,150});
    insertar(red,{false,25});
    insertar(red,{false,75});
    insertar(red,{true, 125});
    insertar(red, {false, 175});
    insertar(red, {false, 40});
    insertar(red, {false, 200});

    diagonal(red);

    diagonalInversa(red);

    return 0;
}
