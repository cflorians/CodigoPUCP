#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#include "Arbol.h"
#include "Medicamento.h"

Arbol::Arbol() {
    raiz = nullptr;
}

Arbol::~Arbol() {
    destruir(raiz);
}

void Arbol::destruir(Nodo*& n) {
    if (n != nullptr) {
        Nodo* izq = n->getIzq();
        destruir(izq);
        Nodo* der = n->getDer();
        destruir(der);
        delete n;
    }
}

void Arbol::insertar(Medicamento *m) {
    insertarRecursivo(raiz, m);
}

void operator<<(ofstream &arch, const Arbol &arbol) {
    arch << arbol.get;
}

void Arbol::insertarRecursivo(Nodo*& n, Medicamento *m) {
    if (n == nullptr) { // Si esta vacio insertamos
        n = new Nodo;
        n->setMedicamento(m);
        return;
    }
    // Si es que no esta vacio comparamos y recorremos en base a eso
    if (*m < *(n->getMedicamento())) {
        // Si m es menor al nodo en el que estamos, nos vamos a la izquierda
        Nodo* izq = n->getIzq();
        insertarRecursivo(izq, m);
    }
    else {
        // Si no, nos vamos a la derecha
        Nodo* der = n->getDer();
        insertarRecursivo(der, m);
    }
}


