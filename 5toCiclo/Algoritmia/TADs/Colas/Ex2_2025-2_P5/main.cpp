#include <iostream>
using namespace std;

#include "Bibliotecas/Cola.h"
#include "Bibliotecas/Funciones.h"

void invertir(Cola& cola, int i, int k) {
    // CASOS BASE
    if (cola.inicio == nullptr) return;
    if (i == k) return;

    // PARTE RECURSIVA
    Elemento elemento = desencolar(cola);
    invertir(cola, i+1, k);
    encolar(cola, elemento);
}

void invertirCola(Cola& cola, int k) {
    invertir(cola, 0, k);\
}

int main() {

    Cola cola;
    construir(cola);

    encolar(cola, {1});
    encolar(cola, {2});
    encolar(cola, {3});
    encolar(cola, {4});
    encolar(cola, {5});

    imprimir(cola);

    int k = 2;
    int n = cola.longitud;

    invertirCola(cola, k);

    for (int i = k; i < n; i++) {
        encolar(cola, desencolar(cola));
    }

    imprimir(cola);

    return 0;
}