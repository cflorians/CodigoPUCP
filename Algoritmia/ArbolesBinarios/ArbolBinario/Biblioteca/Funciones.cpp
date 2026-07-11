#include <iostream>
#include <iomanip>
using namespace std;

#include "../BibliotecaCola/Cola.h"
#include "../BibliotecaCola/Funciones.h"

#include "Arbol.h"
#include "Funciones.h"

void construir(Arbol& arbol) {
    arbol.raiz = nullptr;
}

void plantar(Arbol& arbol, const Elemento& elemento ,Nodo* izq, Nodo* der) {
    Nodo* nuevo = new Nodo;
    nuevo->elemento = elemento;
    nuevo->izq = izq;
    nuevo->der = der;
    arbol.raiz = nuevo;
}

void insertar(Arbol& arbol, int num) {
    insertar(arbol.raiz, {num});
}

void insertar(Nodo*& nodo, const Elemento& elemento) {
    if (nodo == nullptr) {
        Nodo* nuevo = new Nodo;
        nuevo->elemento = elemento;
        nuevo->izq = nullptr;
        nuevo->der = nullptr;
        nodo = nuevo;
        return;
    }
    if (nodo->elemento.num < elemento.num) insertar(nodo->der, elemento);
    else insertar(nodo->izq, elemento);
}

Nodo* buscarElemento(const Arbol& arbol, const Elemento& elemento) {
    return buscarElemento(arbol.raiz, elemento);
}

Nodo* buscarElemento(Nodo* nodo, const Elemento& elemento) {
    if (nodo == nullptr) return nullptr;

    if (nodo->elemento.num < elemento.num) return buscarElemento(nodo->der, elemento);
    else if (nodo->elemento.num > elemento.num) return buscarElemento(nodo->izq, elemento);
    else return nodo;
}

Nodo* buscarElementoIterativo(const Arbol& arbol, const Elemento& elemento) {
    if (elemento.num == -1) return nullptr;

    Nodo* actual = arbol.raiz;

    while (actual != nullptr) {
        if (actual->elemento.num < elemento.num) actual = actual->der;
        else if (actual->elemento.num > elemento.num) actual = actual->izq;
        else return actual;
    }

    return actual;
}

void imprimePorNivel(const Arbol& arbol) {
    if (arbol.raiz == nullptr) return;

    Nodo* actual = arbol.raiz;
    Cola cola;
    construir(cola);

    encolar(cola, actual->elemento);

    encolar(cola, {-1}); // centinela para el salto de linea

    while (not esColaVacia(cola)) {
        actual = buscarElementoIterativo(arbol, desencolar(cola));

        if (actual == nullptr) {
            cout << endl; // imprimimos el salto de linea
            if (!esColaVacia(cola)) {
                encolar(cola, {-1}); // colocamos un centinela al final
            }
        }
        else {
            cout << left << setw(2) << actual->elemento.num << " ";

            if (actual->izq) {
                encolar(cola, actual->izq->elemento);
            }
            if (actual->der) {
                encolar(cola, actual->der->elemento);
            }
        }
    }
    cout << endl;
}

Nodo* eliminaNodo(Arbol& arbol, int num) {
    return eliminaNodo(arbol.raiz, num);
}

Nodo* eliminaNodo(Nodo *nodo, int num) {
    if (nodo == nullptr) return nullptr;

    if (nodo->elemento.num < num) nodo->der = eliminaNodo(nodo->der, num);
    else if (nodo->elemento.num > num) nodo->izq = eliminaNodo(nodo->izq, num);
    else {
        // CASO 1: sin hijo izquierdo
        if (nodo->izq == nullptr) {
            Nodo* temp = nodo->der;
            delete nodo;
            return temp;
        }

        // CASO 2: sin hijo derecho
        if (nodo->der == nullptr) {
            Nodo* temp = nodo->izq;
            delete nodo;
            return temp;
        }

        // CASO 3: con 2 hijos
        Nodo* sucesor = buscaMinimo(nodo->der);

        nodo->elemento = sucesor->elemento;
        nodo->der = eliminaNodo(nodo->der, sucesor->elemento.num);
    }
    return nodo;
}

Nodo* buscaMinimo(Nodo *nodo) {
    if (nodo == nullptr) return nullptr;

    if (nodo->izq) {
        return buscaMinimo(nodo->izq);
    }
    return nodo;
}

int cantNiveles(const Arbol& arbol) {
    return cantNiveles(arbol.raiz);
}

int cantNiveles(Nodo *nodo) {
    if (nodo == nullptr) return 0;

    int cantIzq = cantNiveles(nodo->izq);
    int cantDer = cantNiveles(nodo->der);

    return 1 + max(cantIzq, cantDer);
}

bool balanceado(const Arbol& arbol) {
    return balanceado(arbol.raiz);
}

bool balanceado(Nodo *nodo) {
    if (nodo == nullptr) return true;

    int cantNivIzq = cantNiveles(nodo->izq);
    int cantNivDer = cantNiveles(nodo->der);

    return abs(cantNivIzq - cantNivDer) <= 1;
}

int cantNodos(Arbol& arbol) {
    return cantNodos(arbol.raiz);
}

int cantNodos(Nodo *nodo) {
    if (nodo == nullptr) return 0;

    int cantIzq = cantNodos(nodo->izq);
    int cantDer = cantNodos(nodo->der);

    return 1 + cantIzq + cantDer;
}

void balanceaArbol(Arbol& arbol) {
    int n = cantNodos(arbol);
    if (n<=2) return;

    // creamos un arreglo temp
    Elemento* A = new Elemento[n];
    int indice = 0;

    almacenarInOrden(arbol.raiz, A, indice);

    destruir(arbol);
    arbol.raiz = nullptr;

    arbol.raiz = construirArbolBalanceado(A, 0, n-1);

    delete[] A;
}

Nodo* construirArbolBalanceado(Elemento* A, int ini, int fin) {
    if (ini > fin) return nullptr;

    int mid = (ini + fin) / 2;

    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->elemento = A[mid];
    nuevoNodo->izq = construirArbolBalanceado(A, ini, mid-1);
    nuevoNodo->der = construirArbolBalanceado(A, mid + 1, fin);

    return nuevoNodo;
}

void almacenarInOrden(Nodo* nodo, Elemento* A, int& indice) {
    if (nodo != nullptr) {
        almacenarInOrden(nodo->izq, A, indice);
        A[indice] = nodo->elemento;
        indice++;
        almacenarInOrden(nodo->der, A, indice);
    }
}

void destruir(Arbol& arbol) {
    destruir(arbol.raiz);
}

void destruir(Nodo* nodo) {
    if (nodo != nullptr) {
        destruir(nodo->izq);
        destruir(nodo->der);
        delete nodo;
    }
}

int obtenerFactorEquilibrio(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    return cantNiveles(nodo->izq) - cantNiveles(nodo->der);
}

void insertarAVL(Arbol& arbol, int num) {
    arbol.raiz = insertarAVL(arbol.raiz, {num});
}

Nodo* insertarAVL(Nodo* nodo, const Elemento& elemento) {
    // insertamos normalmente
    if (nodo == nullptr) {
        Nodo* nuevo = new Nodo;
        nuevo->elemento = elemento;
        nuevo->izq = nullptr;
        nuevo->der = nullptr;
        return nuevo;
    }
    if (nodo->elemento.num < elemento.num) nodo->der = insertarAVL(nodo->der, elemento);
    else if (nodo->elemento.num > elemento.num) nodo->izq = insertarAVL(nodo->izq, elemento);
    else return nodo;

    int fe = obtenerFactorEquilibrio(nodo);

    // si el nodo esta desbalanceado
    // caso izq - izq (rotacion simple a la derecha)
    if (fe>1 and elemento.num < nodo->izq->elemento.num) {
        return rotarDer(nodo);
    }

    // caso der - der (rotacion simple a la izquierda)
    if (fe<-1 and elemento.num > nodo->der->elemento.num) {
        return rotarIzq(nodo);
    }

    // caso izq - der (rotacion doble, izquierda al hijo, derecha al padre)
    if (fe>1 and elemento.num > nodo->izq->elemento.num) {
        nodo->izq = rotarIzq(nodo->izq);
        return rotarDer(nodo);
    }

    // caso der - izq (rotacion doble, derecha al hijo, izquierda al padre)
    if (fe<-1 and elemento.num < nodo->der->elemento.num) {
        nodo->der = rotarDer(nodo->der);
        return rotarIzq(nodo);
    }

    return nodo;
}

Nodo* rotarDer(Nodo* y) {
    Nodo* x = y->izq;
    Nodo* T2 = x->der;

    x->der = y;
    y->izq = T2;

    return x;
}

Nodo* rotarIzq(Nodo* x) {
    Nodo* y = x->der;
    Nodo* T2 = y->izq;

    y->izq = x;
    x->der = T2;

    return y;
}