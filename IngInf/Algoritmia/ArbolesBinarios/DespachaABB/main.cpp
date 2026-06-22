#include <iostream>
using namespace std;

#include "BibliotecaArbolBinarioBusqueda/ArbolBinario.h"
#include "BibliotecaArbolBinarioBusqueda/FuncionesAB.h"

// Lab 4 - 2019-1

int main() {

    ArbolBinario arbol;
    construir(arbol);

    insertar(arbol, {20170620, 20});
    insertar(arbol, {20180211, 20});
    insertar(arbol, {20170810, 20});
    insertar(arbol, {20180409, 10});

    recorreEnOrden(arbol);

    // despachar los productos del almacen de acuerdo con un pedido solicitado
    int cantProd;
    cout << "Cantidad de productos";
    cin >> cantProd;

    while (cantProd > 0) {
        if (arbol.raiz == nullptr) break;
        // Mientras hay al menos 1 producto por despachar, seguimos entrando al ABB
        Nodo* loteMasAntiguo = encuentraMinimo(arbol.raiz);

        Elemento elementoMasAntiguo = loteMasAntiguo->elemento;

        if (loteMasAntiguo->elemento.cantidad <= cantProd) {
            cantProd -= elementoMasAntiguo.cantidad;
            arbol.raiz = eliminar(arbol.raiz, elementoMasAntiguo.numero);
        }
        else {
            loteMasAntiguo->elemento.cantidad -= cantProd;
            cantProd = 0;
        }
    }

    recorreEnOrden(arbol);

    return 0;
}
