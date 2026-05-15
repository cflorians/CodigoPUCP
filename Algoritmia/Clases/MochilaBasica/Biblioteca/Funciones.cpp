//
// Created by carlo on 3/30/2026.
//

#include "Funciones.h"

void carga_binaria(int numero,int* cromosoma,int n) {
    int i=0;
    int aux;

    // Inicializamos todos los genes dentro de cromosoma
    for (int i=0; i<n; i++) {
        cromosoma[i] = 0;
    }

    // Mediante divisiones sucesivas, obtengo el número binario
    i=0;
    while (numero>0) {
        aux = numero%2;
        numero /= 2;
        cromosoma[i] = aux;
        i++;
    }


}