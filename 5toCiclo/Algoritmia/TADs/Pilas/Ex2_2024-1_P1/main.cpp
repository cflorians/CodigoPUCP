#include <iostream>
using namespace std;

#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/Funciones.h"

int main() {

    Pila original, clon;

    construir(original);
    construir(clon);

    apilar(original, {6});
    apilar(original, {5});
    apilar(original, {1});
    apilar(original, {7});
    apilar(original, {9});
    apilar(original, {3});

    cout << "Pila original: ";
    imprimir(original);

    clonaPila(original, clon);

    cout << "Pila clon: ";
    imprimir(clon);

    return 0;
}
