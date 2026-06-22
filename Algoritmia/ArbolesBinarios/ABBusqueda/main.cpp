#include <iostream>
using namespace std;

#include "BibliotecaArbolBinarioBusqueda/ArbolBinario.h"
#include "BibliotecaArbolBinarioBusqueda/FuncionesAB.h"

int main() {
    //  Son arboles binarios pero con la propiedad de que el
    //  hijo IZQUIERDO tiene un valor INFERIOR al del padre, mientras que el
    //  hijo DERECHO tiene un valor SUPERIOR al del padre
    ArbolBinario arbol;
    construir(arbol);

    insertar(arbol, {100});
    insertar(arbol, {50});
    insertar(arbol, {150});
    insertar(arbol, {125});
    insertar(arbol, {175});
    insertar(arbol, {200});
    insertar(arbol, {25});
    insertar(arbol, {75});

    recorreEnOrden(arbol);

    cout << "Esta 20 en el arbol? " << (buscar(arbol, {20}) ? "SI":"NO") << endl;
    cout << "Esta 100 en el arbol? " << (buscar(arbol, {100}) ? "SI":"NO") << endl;

    eliminar(arbol.raiz, 50);
    recorreEnOrden(arbol);

    return 0;
}
