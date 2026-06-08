#include <iostream>
using namespace std;

#include "BibliotecaArbolBinario/ArbolBinario.h"
#include "BibliotecaArbolBinario/FuncionesAB.h"

int main() {

    ArbolBinario arbol;
    ArbolBinario arbol1, arbol2, arbol3, arbol4, arbol5, arbol6, arbolVacio;

    //            100               raiz
    //          /     \
    //         50      150          2do nivel
    //       /   \    /   \
    //      25   80  120  200       3er nivel (hojas)
    //     /  \

    construir(arbol);
    construir(arbolVacio);

    // hacemos la insercion de abajo a arriba
    plantarArbolBinario(arbol1, arbolVacio, {25}, arbolVacio);
    plantarArbolBinario(arbol2, arbolVacio, {80}, arbolVacio);
    plantarArbolBinario(arbol3, arbolVacio, {120}, arbolVacio);
    plantarArbolBinario(arbol4, arbolVacio, {200}, arbolVacio);
    // Hasta ahorita hemos armado unicamente el nivel mas bajo (hojas)
    // Con esto ya podemos empezar a plantar los arboles que estan arriba (los padres)
    plantarArbolBinario(arbol5, arbol1, {50}, arbol2);
    plantarArbolBinario(arbol6, arbol3, {150}, arbol4);
    // ya tenemos el segundo nivel
    plantarArbolBinario(arbol, arbol5, {100}, arbol6);
    // Con esto ya tenemos el arbol completo

    // Hay varios tipos de impresion, dependiendo de como lo queramos mostrar
    recorrePreOrden(arbol);
    recorreEnOrden(arbol);
    recorrePostOrden(arbol);

    // altura
    cout << "Altura: " << altura(arbol) << endl;
    // numero de nodos
    cout << "Numero de nodos: " << numeroNodos(arbol) << endl;
    // numHojas
    cout << "Numero de hojas: " << numeroHojas(arbol) << endl;
    // es equilibrado?
    cout << "Es equilibrado: " << (esEquilibrado(arbol) ? "SI" : "NO") << endl;

    destruir(arbol);
    cout << "Arbol esta vacio?: " << (esArbolVacio(arbol) ? "SI": "NO")<< endl;

    return 0;
}
