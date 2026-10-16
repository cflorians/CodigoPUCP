#include <iostream>
using namespace std;

#include "Biblioteca/Funciones.h"
#include "Biblioteca/Pila.h"

void submarino(struct Pila& pila,char orden[],int n) {
    int i=0;
    int nivel = 2;
    while (i<n) {
        if (pila.inicio == nullptr) {
            apilar(pila,{1});
        }
        if (orden[i]=='S') { // "suelto" todos os niveles acumulados
            while (pila.inicio != nullptr) {
                cout << desapilar(pila)->elemento.codigo << " ";
            }
            apilar(pila, {nivel});
            nivel++;
        }
        else { // si es "B", no muestro el movimiento, solo apilo
            apilar(pila,{nivel});
            nivel++;
        }
        i++;
    }
}

int main() {
    
    struct Pila pila;
    construir(pila);

    int n=7;
    char orden[n] = {'S','B','S','B','B','S','S'};
    submarino(pila, orden,n);

    return 0;
}
