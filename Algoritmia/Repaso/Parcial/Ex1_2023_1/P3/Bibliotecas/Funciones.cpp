#include <iostream>
using namespace std;
#include "Lista.h"
#include "Funciones.h"

void construir(Lista& lista) {
    lista.inicio = nullptr;
    lista.fin = nullptr;
    lista.longitud = 0;
}

bool estaVacia(const Lista& lista) {
    return lista.inicio == nullptr;
}

void insertarInicio(Lista& lista, const Elemento& elemento) {
    Nodo* nuevo = new Nodo;
    nuevo->elemento = elemento;
    nuevo->sgte = nullptr;
    if (estaVacia(lista)) {
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else {
        nuevo->sgte = lista.inicio;
        lista.inicio = nuevo;
    }
    lista.longitud++;
}

void insertarFinal(Lista& lista, const Elemento& elemento) {
    Nodo* nuevo = new Nodo;
    nuevo->elemento = elemento;
    nuevo->sgte = nullptr;
    if (estaVacia(lista)) {
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else {
        lista.fin->sgte = nuevo;
        lista.fin = nuevo;
    }
    lista.longitud++;
}

void imprimir(const Lista& lista) {
    Nodo* actual = lista.inicio;
    while (actual) {
        cout << actual->elemento.poder;
        if (actual->sgte != nullptr) cout << "->";
        actual = actual->sgte;
    }
    cout << endl;
}

int fuerza(const Lista& lista) {
    int fuerza = 0;
    Nodo* actual = lista.inicio;
    while (actual) {
        fuerza += actual->elemento.poder;
        actual = actual->sgte;
    }
    return fuerza;
}

void insertarOrdenado(Lista& lista, Nodo* nodo) {
    Nodo* actual = lista.inicio;
    Nodo* anterior = nullptr;

    // lista vacia
    if (actual == nullptr) {
        lista.inicio = nodo;
        lista.fin = nodo;
        nodo->sgte = nullptr;
        lista.longitud++;
        return;
    }

    // buscar posicion
    while (actual) {
        if (nodo->elemento.poder < actual->elemento.poder) {
            nodo->sgte = actual;
            if (anterior) {
                anterior->sgte = nodo;
            }
            else {
                lista.inicio = nodo;
            }
            lista.longitud++;
            return;
        }
        anterior = actual;
        actual = actual->sgte;
    }

    // al final de la lista
    anterior->sgte = nodo;
    nodo->sgte = nullptr;
    lista.fin = nodo;
    lista.longitud++;
}

Nodo* quitarNodo(Lista& lista) {
    if (lista.inicio == nullptr) return nullptr;
    Nodo* aQuitar = lista.inicio;
    lista.inicio = lista.inicio->sgte;
    lista.longitud--;
    aQuitar->sgte = nullptr;
    return aQuitar;
}

void distribuirGuerreros(Lista& lista, Lista& bowser, Lista& peach, Lista& donkey) {
    Nodo* actual = nullptr;
    while (not estaVacia(lista)) {
        actual = quitarNodo(lista);
        if ((actual->elemento.poder)%10 == 1) {
            actual->elemento.poder /= 10;
            insertarOrdenado(bowser, actual);
        }
        else if ((actual->elemento.poder)%10 == 2) {
            actual->elemento.poder /= 10;
            insertarOrdenado(peach, actual);
        }
        else {
            actual->elemento.poder /= 10;
            insertarOrdenado(donkey, actual);
        }
    }
}

void fusionarListas(Lista& lista1, Lista& lista2) {
    // quitamos uno de cada uno y colocamos el primero al inicio
    Nodo* inicio = nullptr;
    Nodo* fin = nullptr;
    Nodo* a, *b;
    int longitud = lista1.longitud + lista2.longitud;
    while (true) {
        if (inicio == nullptr){
            a = quitarNodo(lista1);
            b = quitarNodo(lista2);
        }
        if (a->elemento.poder < b->elemento.poder) {
            if (inicio == nullptr) {
                inicio = a;
                fin = a;
            }
            else {
                fin->sgte = a;
                fin = a;
            }
            a = quitarNodo(lista1);
        }
        else {
            if (inicio == nullptr) {
                inicio = b;
                fin = b;
            }
            else {
                fin->sgte = b;
                fin = b;
            }
            b = quitarNodo(lista2);
        }
        if (a == nullptr or b == nullptr) {
            if (a != nullptr) {
                fin->sgte = a;
                fin = a;
            }
            else {
                fin->sgte = b;
                fin = b;
            }
            break;
        }
    }
    if (estaVacia(lista1)) {
        fin->sgte = lista2.inicio;
        fin = lista2.fin;
    }
    if (estaVacia(lista2)) {
        fin->sgte = lista1.inicio;
        fin = lista1.fin;
    }
    lista1.inicio = inicio;
    lista1.fin = fin;
    lista1.longitud = longitud;

    lista2.inicio = nullptr;
    lista2.fin = nullptr;
    lista2.longitud = 0;
}

void batalla(Lista& lista1, Lista& lista2, Lista& lista3, int n) {
    Nodo* actual1;
    Nodo* actual2;

    while (not estaVacia(lista1) and not estaVacia(lista2)) {
        actual1 = lista1.inicio;
        actual2 = lista2.inicio;
        cout << "Inicio la batalla: "<< endl;
        imprimir(lista1);
        imprimir(lista2);
        for (int i = 0; i < n and i < lista2.longitud; i++) {
            cout << "Pelea " << i+1 << ": " << actual1->elemento.poder << " vs " << actual2->elemento.poder;
            if (actual1->elemento.poder > actual2->elemento.poder) {
                cout << ", gana " << actual1->elemento.poder << endl;
                actual1 = actual1->sgte;
                actual2 = actual2->sgte;
                quitarNodo(lista2);
            } else {
                cout << ", gana " << actual2->elemento.poder << endl;
                actual1 = actual1->sgte;
                actual2 = actual2->sgte;
                quitarNodo(lista1);
            }
        }
        cout << "Nivel de ataque Ejercito 1: " << fuerza(lista1) << endl;
        cout << "Nivel de ataque Ejercito 2: " << fuerza(lista2) << endl;
        if (fuerza(lista2) == 0) cout << "Gana Bowser" << endl;
        else if (fuerza(lista2) <= fuerza(lista1)) {
            if (not estaVacia(lista3)) {
                cout << "El ejercito de DonKey Kong se une al ejercito de Peach" << endl;
                fusionarListas(lista2, lista3);
            }
            else {
                cout << "Ya nadie se puede unir al ejercito de Peach" << endl;
            }
        }
        cout << endl;
    }
}