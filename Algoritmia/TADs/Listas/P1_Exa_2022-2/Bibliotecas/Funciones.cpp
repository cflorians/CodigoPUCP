#include <cstring>
#include <iostream>
using namespace std;

#include "Lista.h"
#include "Funciones.h"

void construir(Lista& lista) {
    lista.inicio = nullptr;
    lista.fin = nullptr;
    lista.longitud = 0;
}

void insertarAlFinal(Lista& lista, const Elemento& elemento) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->sgte = nullptr;

    if (esListaVacia(lista)) {
        lista.inicio = nuevoNodo;
        lista.fin = nuevoNodo;
    }
    else {
        lista.fin->sgte = nuevoNodo;
        lista.fin = nuevoNodo;
    }
    lista.longitud++;
}

bool esListaVacia(const Lista& lista) {
    return lista.inicio == nullptr;
}

void imprimirLista(const Lista& lista) {
    Nodo* actual = lista.inicio;

    for (int i=0; actual; i++) {
        cout << actual->elemento.hora << "(" << actual->elemento.sucursal << ")"
             << "(" << actual->elemento.dia << ") ";
        if (actual->sgte != nullptr) cout << "-> ";
        else cout << endl;
        actual = actual->sgte;
    }
}

void fusionarLista(Lista& lista1, Lista& lista2) {
    // Tomamos 2 listas y las fusionamos, tenemos 3 casos posibles
    // Caso 1:
    // Todos los elementos de lista1 son mayores a los de lista2
    if (lista1.inicio->elemento.hora >= lista2.fin->elemento.hora) {
        lista1.longitud += lista2.longitud;
        lista2.fin->sgte = lista1.inicio;
        lista2.fin = lista1.fin;
        lista1.inicio = lista2.inicio;
        return;
    }
    // Caso 2:
    // Todos los elementos de lista2 son mayores a los de lista2
    if (lista2.inicio->elemento.hora > lista1.fin->elemento.hora) {
        lista1.longitud += lista2.longitud;
        lista1.fin->sgte = lista2.inicio;
        lista1.fin = lista2.fin;
        return;
    }
    // Caso 3:
    // Si existe superposicion
    else {
        Nodo* inicio = nullptr;
        Nodo* actual = nullptr;
        while (lista1.inicio and lista2.inicio) { // vamos a ir avanzando las listas
            // comparamos los datos que se encuentran al inicio de las listas
            if (lista1.inicio->elemento.hora <= lista2.inicio->elemento.hora) {
                // Si el dato de la lista1 es menor igual, insertamos el dato de lista1
                if (inicio == nullptr) {
                    inicio = lista1.inicio;
                    actual = lista1.inicio;
                }
                else {
                    actual->sgte = lista1.inicio;
                    actual = lista1.inicio;
                }
                lista1.inicio = lista1.inicio->sgte;
            }
            else {
                // Caso contrario, insertamos el dato de lista2
                if (inicio == nullptr) {
                    inicio = lista2.inicio;
                    actual = lista2.inicio;
                }
                else {
                    actual->sgte = lista2.inicio;
                    actual = lista2.inicio;
                }
                lista2.inicio = lista2.inicio->sgte;
            }
        }
        // Cuando acabamos el while, preguntamos que lista se quedo vacia primero
        if (lista1.inicio == nullptr) {
            // Como lista1 quedo vacia, insertaremos toda la lista 2 al final
            actual->sgte = lista2.inicio;
            actual = lista2.fin;
        }
        else if (lista2.inicio == nullptr) {
            // Como lista2 quedo vacia, insertamos lista1 al final
            actual->sgte = lista1.inicio;
            actual = lista1.fin;
        }
        // Ahora apuntamos el inicio de la lista1 al inicio que obtuvimos
        lista1.inicio = inicio;
        lista1.fin = actual;
        lista1.longitud += lista2.longitud;
    }
}