#include <iostream>
using namespace std;

#include "Lista.h"
#include "Funciones.h"

void construir(Lista& lista) {
    lista.fin = nullptr;
    lista.inicio = nullptr;
    lista.longitud = 0;
}

void insertar(Lista& lista, const Elemento& elemento) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = elemento;
    nuevo->next = nullptr;
    nuevo->skip_next = nullptr;

    if (lista.inicio == nullptr) {
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else {
        lista.fin->next = nuevo;
        lista.fin = nuevo;
        lista.fin->next = lista.inicio;
    }
    lista.longitud++;
}

void imprimir(const Lista& lista) {
    Nodo* actual = lista.inicio;
    int n = lista.longitud;
    for (int i = 0; i < n; i++) {
        cout << "Nodo " << actual->dato.id << " [";
        if (actual->dato.is_active) cout << "ACTIVO] ";
        else cout << "CAIDO] ";
        cout << " siguiente=" << actual->next->dato.id << " ";
        if (actual->skip_next != nullptr) cout << "skip_next=" << actual->skip_next->dato.id << " ";
        cout << endl;
        actual = actual->next;
    }
    cout << endl;
}

void calcular_skip_next(Lista& lista) {
    Nodo* actual = lista.inicio;
    Nodo* siguiente = nullptr;
    Nodo* subsiguiente = nullptr;
    int n = lista.longitud;
    for (int i = 0; i < n; i++) {
        siguiente = actual->next;
        subsiguiente = siguiente->next;
        actual->skip_next = subsiguiente;
        actual = siguiente;
    }
}

void auto_healing(Lista& lista) {
    Nodo* actual = lista.inicio;
    Nodo* siguiente = nullptr;
    Nodo* anterior = nullptr;
    int n = lista.longitud;
    for (int i = 0; i < n; i++) {
        anterior = actual;
        siguiente = actual->next;
        if (actual->dato.is_active == false) {
            while (siguiente->dato.is_active == false) siguiente = siguiente->next;
            
        }
    }
}