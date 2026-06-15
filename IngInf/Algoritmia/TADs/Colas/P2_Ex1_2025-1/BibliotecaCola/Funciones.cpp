#include <iostream>
using namespace std;
#include "Cola.h"
#include "Funciones.h"

void construirCola(Cola& cola) {
    cola.inicio = nullptr;
    cola.fin = nullptr;
    cola.longitud = 0;
}

void encolar(Cola& cola, const Elemento& elemento) {
    Nodo* nuevo = new Nodo;
    nuevo->elemento = elemento;
    nuevo->sgte = nullptr;

    if (cola.inicio == nullptr) {
        cola.inicio = nuevo;
        cola.fin = nuevo;
    }
    else {
        cola.fin->sgte = nuevo;
        cola.fin = nuevo;
    }
    cola.longitud++;
}

Nodo* desencolar(Cola& cola) {
    Nodo* desencolado = cola.inicio;
    cola.inicio = cola.inicio->sgte;
    cola.longitud--;
    return desencolado;
}

double calcularPromedio(Cola& cola) {
    int n = cola.longitud;
    if (n==0) return 0;

    return (double)sumarYRotar(cola, n)/n;
}

int sumarYRotar(Cola& cola,int n) {
    // CASO BASE
    if (n == 0) return 0;

    // PARTE RECURSIVA
    int dato = desencolar(cola)->elemento.temp;
    encolar(cola, {dato});

    return dato + sumarYRotar(cola, n-1);
}

void imprimirCola(Cola& cola) {
    Nodo* actual = cola.inicio;
    for (int i = 0; i < cola.longitud; i++) {
        cout << actual->elemento.temp << " ";
        actual = actual->sgte;
    }
    cout << endl;
}