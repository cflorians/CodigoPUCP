#include <iostream>
using namespace std;

#include "Bibliotecas/Funciones.h"
#include "Bibliotecas/Cola.h"

int main() {
    
    Cola cola;
    construir(cola);
    // for (int i=9; i>=0; i--) {
    //     encolar(cola, {i});
    // }
    // imprimir(cola);

    encolar(cola, {4});
    encolar(cola, {9});
    encolar(cola, {3});
    encolar(cola, {7});
    encolar(cola, {8});
    encolar(cola, {5});
    encolar(cola,{1});
    encolar(cola, {6});
    encolar(cola,{2});
    encolar(cola,{});
    imprimir(cola);

    ordenarRecursivo(cola, cola.longitud);

    imprimir(cola);
    
    return 0;
}
