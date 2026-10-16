#include <iostream>
using namespace std;

#include "Funciones.h"

void imprimir(void* v, char tipo) {
    switch (tipo) {
    case 'i': cout << "Entero: " << *(int*)v << endl; break;
    case 'd': cout << "Real: " << *(double*)v << endl; break;
    case 'c': cout << "Caracter: " << *(char*)v << endl; break;
    case 'x':
        cout << "Cadena: ";
        for (int i=0; ((char*)v)[i] ; i++) cout << ((char*)v)[i];
        cout << endl;
        break;
    default: cout << "Tipo no soportado" << endl;
    }
}