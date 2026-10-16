#include <iostream>
#include <cmath>
using namespace std;

#include "Biblioteca/Funciones.h"

int main(int argc, char** argv) {

    // OBJETOS CON DETERMINADOS PESOS Y CANTIDAD DE OBJETOS
    int objetos[5] = {1,2,1,12,4};
    int n = 5;

    // Para el análisis de cada combinación
    int cromosoma[n];
    int peso_mochila;

    //LIMITANTES
    int peso_maximo = 15;

    int combinaciones;
    combinaciones = pow(2,n);

    // Nos permitiran quedarnos con la mejor combinacion como solucion
    int mejor_peso_mochila = 0;
    int mejor_combinacion;

    // como en la combinacion 0 no se asigna nada, la omitimos
    // Iniciamos FUERZA BRUTA analizando cada combinación
    for (int i=1; i<combinaciones; i++) {
        carga_binaria(i, cromosoma, n);
        // Comienzo a analizar si la combinación cumple la(s) limitante(s)
        peso_mochila = 0; // peso de la combinación actual
        for (int j=0; j<n; j++) {
            // el arreglo cromosoma es un arreglo que determina si estan activos o inactivos
            // si estan inctivos, al multiplicar por 0, no sumara al peso de la mochila actual
            peso_mochila += objetos[j]*cromosoma[j];
        }
        // Aca ya tengo el peso final de la combinación
        // Ahora toca verificar el peso de la combinacion con el peso_maximo
        if (peso_mochila <= peso_maximo and mejor_peso_mochila <= peso_mochila) {
            // la mejor combinacion, es decir, la que me permita colocar más peso sin sobrepasar
            // el limite
            mejor_peso_mochila = peso_mochila;
            mejor_combinacion = i;
        }

    }
    // como ya encotre la mejor combinacion, la muestro:
    carga_binaria(mejor_combinacion, cromosoma, n);
    cout << "SOLUCIÓN: ";
    for (int j=0; j<n; j++) {
        if (cromosoma[j] == 1) cout << objetos[j] << " ";
    }
    cout << endl;

    return 0;
}