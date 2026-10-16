//
// Created by Carlos on 10/06/2026.
//
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "Lista.h"

Lista::Lista() {
    construir();
}

Lista::~Lista() {
    Nodo* sale;
    while (not esListaVacia()) {
        sale = lista;
        lista = lista->sig;
        delete sale;
    }
}

void Lista::construir() {
    lista = nullptr;
}

void Lista::crear(const char *nombArch) {
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

void Lista::insertar(Persona& dat) {
    // Creamos un nuevo nodo que incluya el dato
    Nodo* nuevo = new Nodo;
    nuevo->dato = dat;
    nuevo->sig = nullptr;

    // Creamos nuestros nodos auxiliares para insertar en orden
    Nodo* actual = lista;
    Nodo* anterior = nullptr;

    // hallamos la posicion correcta
    while (actual) {
        if (actual->dato > dat) break;
        anterior = actual;
        actual = actual->sig;
    }

    // enlazamos
    nuevo->sig = actual;
    if (anterior != nullptr) anterior->sig = nuevo;
    else lista = nuevo;

}

bool Lista::esListaVacia() {
    return lista == nullptr;
}

void Lista::imprimir(const char *nombArch) {
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    Nodo* actual = lista;
    arch << "Impresion Recursiva:" << endl;
    imprimirRecursivo(arch, actual);
    arch << endl;

    arch << "Impresion Iterativa:" << endl;
    // arch << "["; SI QUEREMOS FORMATO
    while (actual) {
        arch << actual->dato;
        // if (actual->sig != nullptr) arch << ", ";  SI QUEREMOS FORMATO
        // else arch << "]";
        actual = actual->sig;
    }
}

void Lista::imprimirRecursivo(ofstream &arch, Nodo *actual) {
    // CASO BASE
    if (actual == nullptr) {
        // Cuando llegamos al final ponemos el ] para cerrar
        // arch << "]"; SI QUEREMOS FORMATO
        return;
    }
    // PARTE RECURSIVA
    // Si es que actual es igual a lista, significa que es el primer elemento,
    // por lo que abrimos corchetes
    // if (actual == lista) arch << "[";  SI QUEREMOS FORMATO
    arch << actual->dato;
    // Si es que existe el siguiente, colocamos una coma
    // if (actual->sig != nullptr) arch << ", ";  SI QUEREMOS FORMATO
    // Llamamos de forma recursiva al final, si lo llamamos al inicio invertimos el orden
    imprimirRecursivo(arch, actual->sig);
}
