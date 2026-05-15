#include <iostream>
using namespace std;

#include "Biblioteca/Funciones.h"
#include "Biblioteca/Pila.h"

int main() {
    
    struct Pila pila1;
    struct Pila pila2;

    construir(pila1);
    construir(pila2);

    apilar(pila1,{1});
    apilar(pila1,{2});
    apilar(pila1,{3});
    apilar(pila1,{4});

    cout << "Pila 1: ";
    imprimirPila(pila1);
    cout << "Pila 2: ";
    imprimirPila(pila2);

    cout << endl;
    cout << "Pasamos la pila de un lado a otro" << endl;
    pasaPilaRecursiva(pila1,pila2);

    cout << "Pila 1: ";
    imprimirPila(pila1);
    cout << "Pila 2: ";
    imprimirPila(pila2);

    return 0;
}
