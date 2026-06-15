#include <iostream>
using namespace std;

#include "Bibliotecas/Funciones.h"
enum tipoV {CODIGO, VETERINARIO, SUELDO};
// CODIGO = 0
// VETERINARIO = 1
// SUELDO = 2

int main(int argc, char** argv) {
    
    int a = 10;
    double b = 20.5;
    char c = 'c';

    void* ptr;

    ptr = &a;
    cout << "Valor a: "<< *(int*)ptr << endl;

    ptr = &b;
    cout << "Valor b: "<< *(double*)ptr << endl;

    ptr = &c;
    cout << "Valor c: "<< *(char*)ptr << endl;

    int *ptrE;
    double *ptrD;
    char *ptrC;
    char s[12] = "Hello world";

    void *v;

    ptrE = &a;
    ptrD = &b;
    ptrC = &c;

    // ptrE = ptrD // ERROR no son del mismo tipo

    v = ptrE;
    cout << "Valor v: "<< *(int*)v << endl;

    v = s;
    cout << "Valor s: ";
    for (int i=0; ((char*)v)[i] ; i++) {
        cout << ((char*)v)[i];
    }
    cout << endl;

    imprimir(ptrE, 'i');
    imprimir(ptrD, 'd');
    imprimir(ptrC, 'c');

//******************************************

    int codigo = 1001;
    char veterinario[30] = "Luz Pedro";
    double sueldo = 3590.56;

    void **p;
    p = new void*[4];

    p[CODIGO] = &codigo;
    p[VETERINARIO] = veterinario;
    p[SUELDO] = &sueldo;

    cout << "Datos del veterinario: " << endl;
    imprimir(p[CODIGO], 'i');
    imprimir(p[VETERINARIO], 'x');
    // manera alternativa
    // cout << "Veterinario " << (char*)p[VETERINARIO] << endl;
    imprimir(p[SUELDO], 'd');

    delete p;

    return 0;
}
