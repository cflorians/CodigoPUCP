#include <iostream>
using namespace std;

#include "Bibliotecas/Arbol.h"
#include "Bibliotecas/Funciones.h"

void muestraPalabras(Arbol& arbol, Nodo*& nodo) {
    // si no tiene hijos
    if (nodo->izq == nullptr and nodo->der == nullptr) {
        // imprimimos, mostramos el cambio de linea y regresamos
        cout << nodo->elemento.letra << endl;
        return;
    }

    if (nodo->izq->elemento.impreso and nodo->der->elemento.impreso) {
        return;
    }
    else {
        cout << nodo->elemento.letra;
    }

    // si tiene 2 hijos
    if (nodo->izq != nullptr and nodo->der != nullptr) {
        // hay 2 casos, si no esta impreso izq, si esta impreso izq y si esta impreso der
        if (nodo->izq->elemento.impreso) {
            // si es que esta impreso el lado izquierdo, imprimimos el lado derecho
            muestraPalabras(arbol, nodo->der);
            // marcamos el nodo derecho como impreso y el nodo raiz tambien
            nodo->elemento.impreso = true;
            nodo->der->elemento.impreso = true;
            // ya marcados los impresos
            muestraPalabras(arbol, arbol.raiz);
        }
        else {
            // si la izquierda no esta impresa, vamos por ese camino
            muestraPalabras(arbol, nodo->izq);
            // ahora marcamos que ya se imprimio la izq
            nodo->izq->elemento.impreso = true;
            // como ya marcamos, reiniciamos la impresion a la raiz
            muestraPalabras(arbol, arbol.raiz);
        }
    }
    else if (nodo->izq == nullptr) {
        // si el nodo izquierdo es el que no existe avanzamos a la derecha
        muestraPalabras(arbol, nodo->der);
    }
    else {
        // caso contrario avanzamos a la izq
        muestraPalabras(arbol, nodo->izq);
    }
}

int main() {

    Arbol arbol;
    Arbol arbol1, arbol2, arbol3, arbol4, arbol5, arbol6, arbol7, arbol8
         ,arbol9, arbol10, arbol11, arbol12, arbol13, arbol14, arbol15, arbol16
         , arbol17, arbol18;

    construir(arbol);
    construir(arbol1);
    construir(arbol2);
    construir(arbol3);
    construir(arbol4);
    construir(arbol5);
    construir(arbol6);
    construir(arbol7);
    construir(arbol8);
    construir(arbol9);
    construir(arbol10);
    construir(arbol11);
    construir(arbol12);
    construir(arbol13);
    construir(arbol14);
    construir(arbol15);
    construir(arbol16);
    construir(arbol17);
    construir(arbol18);


    // plantamos la O del nivel mas bajo
    plantar(arbol1, {'O'}, nullptr, nullptr);
    plantar(arbol2, {'S'}, nullptr, nullptr);
    plantar(arbol3, {'S'}, nullptr, nullptr);
    // plantamos el siguiente nivel
    plantar(arbol4,{'A'}, arbol1.raiz, nullptr);
    plantar(arbol5, {'A'}, nullptr, nullptr);
    plantar(arbol6, {'O'}, nullptr, arbol2.raiz);
    plantar(arbol7, {'A'}, nullptr, nullptr);
    plantar(arbol8, {'O'}, nullptr, arbol3.raiz);
    // subimos un nivel mas
    plantar(arbol9, {'N'}, nullptr, nullptr);
    plantar(arbol10, {'B'}, arbol4.raiz, nullptr);
    plantar(arbol11, {'N'}, arbol5.raiz, arbol6.raiz);
    plantar(arbol12, {'R'}, arbol7.raiz, arbol8.raiz);
    // subimos otro nivel
    plantar(arbol13, {'E'}, arbol9.raiz, nullptr);
    plantar(arbol14, {'L'}, arbol10.raiz, nullptr);
    plantar(arbol15, {'E'}, arbol11.raiz, nullptr);
    plantar(arbol16, {'R'}, nullptr, arbol12.raiz);
    // subimos otro
    plantar(arbol17, {'I'}, arbol13.raiz, arbol14.raiz);
    plantar(arbol18, {'U'}, arbol15.raiz, arbol16.raiz);
    // subimos un ultimo nivel
    plantar(arbol, {'B'}, arbol17.raiz, arbol18.raiz);

    muestraPalabras(arbol, arbol.raiz);

    return 0;
}
