#include <iostream>
using namespace std;

#include "Bibliotecas/Pila.h"
#include "Bibliotecas/Funciones.h"

int main() {
    
    Pila kupa1, kupa2;
    Pila champinon;

    construir(kupa1);
    construir(kupa2);
    construir(champinon);

    apilar(kupa1, {27});
    apilar(kupa1, {30});
    apilar(kupa1, {56});
    apilar(kupa1, {15});
    apilar(kupa1, {85});

    apilar(kupa2, {20});
    apilar(kupa2, {68});
    apilar(kupa2, {22});
    apilar(kupa2, {45});

    imprimir(kupa1);
    imprimir(kupa2);

    // unimos las pilas sin criterio alguno
    unirPilas(kupa1, kupa2);

    imprimir(kupa1);

    // ahora ordenamos la pila
    // kupa 2 noos servira como auxiliar
    ordenarPila(kupa1, kupa2);

    imprimir(kupa1);

    pasaPila(kupa1, champinon);

    imprimir(champinon);

    return 0;
}
