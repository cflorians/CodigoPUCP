#include <iostream>
using namespace std;

#include "Biblioteca/Arbol.h"
#include "Biblioteca/Funciones.h"

int main() {

    Arbol arbol;

    construir(arbol);


    insertar(arbol, 10);
    insertar(arbol, 5);
    insertar(arbol, 15);
    insertar(arbol, 2);
    insertar(arbol, 7);
    insertar(arbol, 12);
    insertar(arbol, 17);
    insertar(arbol, 4);
    insertar(arbol, 6);
    insertar(arbol, 8);
    insertar(arbol, 9);
    insertar(arbol, 14);
    insertar(arbol, 19);
    insertar(arbol, 20);
    insertar(arbol, 21);
    insertar(arbol, 22);

    imprimePorNivel(arbol);
    cout << cantNiveles(arbol) << endl;
    cout << "Esta balanceado? " << (balanceado(arbol) ? "true" : "false") << endl;
    cout << endl;

    balanceaArbol(arbol);

    imprimePorNivel(arbol);
    cout << cantNiveles(arbol) << endl;
    cout << "Esta balanceado? " << (balanceado(arbol) ? "true" : "false") << endl;
    cout << endl;

    Arbol avl;
    construir(avl);
    for (int i = 0; i < 10; i++) {
        insertarAVL(avl, i);
    }

    imprimePorNivel(avl);
    cout << cantNiveles(avl) << endl;
    cout << "Esta balanceado? " << (balanceado(avl) ? "true" : "false") << endl;

    return 0;
}
