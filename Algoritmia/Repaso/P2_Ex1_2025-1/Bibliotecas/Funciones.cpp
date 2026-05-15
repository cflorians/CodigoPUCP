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
    Nodo* nuevo = new Nodo;
    nuevo->elemento = elemento;
    nuevo->sgte = nullptr;

    if (esListaVacia(lista)) {
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else {
        lista.fin->sgte = nuevo;
        lista.fin = nuevo;
    }
    lista.longitud++;
}

bool esListaVacia(Lista& lista) {
    return lista.inicio == nullptr;
}

void reorganizar(Lista& lista) {
    Nodo* inicio = nullptr;
    Nodo* anterior = nullptr;
    Nodo* actual = lista.inicio;
    Nodo* aMover = nullptr;
    Nodo* siguiente = nullptr;

    while (actual) {
        siguiente = actual->sgte;
        // Si es rioridad A lo mandamos al inicio de la lista
        // pero en orden como nos la encontramos
        if (actual->elemento.prioridad == 'A') {
            if (anterior == nullptr) {
                // si es el primer elemento de la lista, no modificamos nada
                // solo actualizamos inicio
                inicio = actual;
                anterior = actual;
            }
            else {
                // si es otro elemento cualquiera
                aMover = actual;
                anterior->sgte = siguiente;
                if (aMover == lista.fin) lista.fin = anterior;

                if (inicio == nullptr) { // si es que todavia no definimos inicio
                    aMover->sgte = lista.inicio;
                    lista.inicio = aMover;
                    inicio = aMover;
                }
                else {
                    aMover->sgte = inicio->sgte;
                    inicio->sgte = aMover;
                    inicio = aMover;
                }
            }
        }
        else {
            // Si no es prioridad A, verificamos que este en grupo
            // si coincide con el siguiente, es porque esta en grupo
            if (actual->sgte != nullptr and (actual->elemento.prioridad == actual->sgte->elemento.prioridad) or
                (anterior != nullptr and anterior->elemento.prioridad == actual->elemento.prioridad)) {
                // como coincide con el siguiente los dejamos en su posicion
                // y nos los saltamos
                anterior = actual;
            }
            else if (anterior != nullptr and actual->elemento.prioridad == anterior->sgte->elemento.prioridad) {
                anterior = actual;
            }
            else {
                // Si no coincide lo debemos mandar al final de la lista
                aMover = actual;

                if (anterior == nullptr) {
                    // si es el primer elemento
                    lista.inicio = siguiente;
                }
                else{
                    anterior->sgte = siguiente;
                }

                if (lista.fin != aMover) {
                    lista.fin->sgte = aMover;
                    lista.fin = aMover;
                }
                aMover->sgte = nullptr;
            }
        }
        actual = siguiente;
    }
}

void imprimir(Lista& lista) {
    Nodo* actual = lista.inicio;
    while (actual) {
        cout << actual->elemento.codigo << actual->elemento.prioridad << " ";
        actual = actual->sgte;
    }
    cout << endl;
}