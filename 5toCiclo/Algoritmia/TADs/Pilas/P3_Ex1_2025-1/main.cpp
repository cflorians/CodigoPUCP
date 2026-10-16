#include <iostream>
using namespace std;

#include "Bibliotecas/Pila.h"
#include "Bibliotecas/Funciones.h"

int main() {
    
    Pila pila, aux;

    construir(pila);
    construir(aux);

    apilar(pila, {201809});
    apilar(pila, {202010});
    apilar(pila, {202109});
    apilar(pila, {201510});
    apilar(pila, {202409});

    desapilar(pila);
    desapilar(pila);

    cout << "Minimo: " << minimo(pila, aux).cod << endl;

    return 0;
}
