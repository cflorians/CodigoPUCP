#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

#include "FuncionesAuxiliares.h"

void copiar(char* destino, const char* fuente) {
    int i;
    for (i = 0; fuente[i] ; i++) {
        destino[i] = fuente[i];
    }
    destino[i] = 0;
}

void concatenar(char* destino, const char* fuente) {
    int pos;
    for (pos=0; destino[pos]; pos++){}
    copiar(&destino[pos], fuente);
}

void aMayusculas(char* cadena) {
    for (int i=0; cadena[i]; i++) {
        if ('a'<=cadena[i] && cadena[i]<='z') {
            cadena[i] -= 'a'-'A';
        }
    }
}