//
// Created by Carlos on 11/06/2026.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Arbol.h"

Arbol::Arbol() {
    construir();
}

Arbol::~Arbol() {
    destruir(raiz);
}

void Arbol::construir() {
    raiz = nullptr;
}

void Arbol::destruir(Nodo* nodo) {
    if (nodo != nullptr) {
        destruir(nodo->izq);
        destruir(nodo->der);
        delete nodo;
    }
}

void Arbol::insertarRecursivo(Nodo*& nodo, const Persona& dato) {
    if (nodo == nullptr) { // Si esta vacio, es porque no tiene datos
        nodo = new Nodo;
        nodo->dato = dato;
        return;
    }
    // Si es que no esta vacio, debemos buscar hacia donde tenemos que ir para colocarlo
    if (nodo->dato > dato) insertarRecursivo(nodo->izq, dato); // si es menor nos vamos a la izquierda
    else insertarRecursivo(nodo->der, dato); // si es mayor igual nos vamos a la derecha
}

void Arbol::crearArbol(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    Persona dato;
    while (true) {
        arch >> dato;
        if (arch.eof()) break;
        insertar(dato);
    }
}

void Arbol::insertar(const Persona& dato) {
    insertarRecursivo(raiz, dato);
}

void Arbol::recorrerEnOrden(const char *nombArch) {
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    arch << "Datos: " << endl;
    recorrerEnOrdenRecursivo(raiz, arch);
    arch << endl;
}

void Arbol::recorrerEnOrdenRecursivo(class Nodo *nodo, ofstream& arch) {
    if (nodo != nullptr) {
        // En orden es: izq/raiz/der
        recorrerEnOrdenRecursivo(nodo->izq, arch);
        arch << nodo->dato;
        recorrerEnOrdenRecursivo(nodo->der, arch);
    }
}
