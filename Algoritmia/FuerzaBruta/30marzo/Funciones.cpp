//
// Created by carlo on 3/30/2026.
//

#include "Funciones.h"
#include <iostream>
using namespace std;

int BusquedaSecuencia(int arreglo[],int n,int k) {
    int i=0;
    while (i<n and arreglo[i]!=k) i++;
    // cuando ya recorrimos el arreglo o hemos encontrado el dato
    if (i<n) return i;
    else return -1;
}

void OrdenamientoSeleccion(int arreglo[], int n) {
    int i=0, j=0, minimo, aux;
    for (i = 0; i < n; i++) { // recorremos el arrgelo entero
        minimo = i; // partimos que la posicion en la que nos encontramos se encuentra el menor
        for (j = i+1; j < n; j++) { // vamos en la busqueda de un nuevo menor
            if (arreglo[j] < arreglo[minimo]) minimo = j; // marcamos la posicion del nuevo minimo
        }
    } // Ahora intercambiamos en menor con la posición
    aux = arreglo[i];
    arreglo[i] = arreglo[minimo];
    arreglo[minimo] = aux;

}

void mostrarArreglo(int* arreglo, int n) {
    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }
}