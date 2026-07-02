#include <iostream>
using namespace std;

#include "Bibliotecas/Arbol.h"
#include "Bibliotecas/Funciones.h"

void muestraPalabras(Nodo* nodo, char* buffer, int profundidad) {
    if (nodo == nullptr) return;

    // colocamos e una posicion de un buffer la letra en especifico mientras bajamos de nivel
    buffer[profundidad] = nodo->elemento.letra;

    if (nodo->izq == nullptr and nodo->der == nullptr) {
        buffer[profundidad+1] = '\0'; // colocamos el fin de linea
        cout << buffer << endl;
        return;
    }

    muestraPalabras(nodo->izq, buffer, profundidad+1);
    muestraPalabras(nodo->der, buffer, profundidad+1);
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

    char buffer[50];
    muestraPalabras(arbol.raiz, buffer, 0);

    return 0;
}
