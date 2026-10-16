#include <iostream>
using namespace std;

#include "Cadena.h"
#include "Funciones.h"

void ordenar(Cadena* cadenas, int cant) {
    qsort(cadenas,cant,sizeof(Cadena), compararCadenas);
}

int compararCadenas(const void* a, const void* b) {
    Cadena* cadena1 = (Cadena*)a;
    Cadena* cadena2 = (Cadena*)b;
    if (*cadena1 > *cadena2) return 1;
    else if (*cadena1 < *cadena2) return -1;
    else return 0;
}

