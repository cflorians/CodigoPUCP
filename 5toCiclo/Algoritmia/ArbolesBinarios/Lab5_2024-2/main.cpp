#include <iostream>
using namespace std;

#include "Bibliotecas/Arbol.h"
#include "Bibliotecas/Funciones.h"

int main() {

    int A[4][7] {
        {100,103,100,101,100,99,100},
        {100,102,102,92,99,100,98},
        {100,100,102,100,100,101,100},
        {98,96,93,99,100,102,95}
    };

    Arbol arbolDiaTurno;
    construir(arbolDiaTurno);

    // Pasamos el arreglo de 2 dimensiones a 1 dimension
    Elemento listaDatos[28];
    int k = 0; // indice para la insercion
    for (int i=0; i<4; i++) {
        for (int j=0; j<7; j++) {
            int codigoClave = j*10 + i;
            listaDatos[k] = {j, i, codigoClave, A[i][j]};
            k++;
        }
    }

    // Ordenamos el arreglo de 1 dimension
    for (int i = 0; i < 28 - 1; i++) {
        for (int j = 0; j < 28 - i - 1; j++) {
            if (listaDatos[j].clave > listaDatos[j + 1].clave) {
                // Intercambio manual de estructuras
                Elemento temporal = listaDatos[j];
                listaDatos[j] = listaDatos[j + 1];
                listaDatos[j + 1] = temporal;
            }
        }
    }

    // Insertamos de forma balanceada
    insertaEnMitades(listaDatos, arbolDiaTurno.raiz, 0, 26,1);

    imprime(arbolDiaTurno.raiz);

    cout << endl << "Cantidad Niveles: " << cantNiveles(arbolDiaTurno.raiz);
    cout << endl << "Esta balanceado?: " << (estaBalanceado(arbolDiaTurno.raiz) ? "Si" : "No") << endl;

    // AHORA HACEMOS LO MISMO PERO CON LA CANTIDAD

    Arbol arbolCantidad;
    construir(arbolCantidad);

    // Pasamos el arreglo de 2 dimensiones a 1 dimension
    Elemento lista2[28];
    k = 0; // indice para la insercion
    for (int i=0; i<4; i++) {
        for (int j=0; j<7; j++) {
            int codigoClave = j*10 + i;
            lista2[k] = {j, i, codigoClave, A[i][j]};
            k++;
        }
    }

    // Ordenamos el arreglo de 1 dimension
    for (int i = 0; i < 28 - 1; i++) {
        for (int j = 0; j < 28 - i - 1; j++) {
            if (lista2[j].cantidades > lista2[j + 1].cantidades) {
                // Intercambio manual de estructuras
                Elemento temporal = lista2[j];
                lista2[j] = lista2[j + 1];
                lista2[j + 1] = temporal;
            }
            else if (lista2[j].cantidades == lista2[j + 1].cantidades) {
                if (lista2[j].clave > lista2[j + 1].clave) {
                    // Intercambio manual de estructuras
                    Elemento temporal = lista2[j];
                    lista2[j] = lista2[j + 1];
                    lista2[j + 1] = temporal;
                }
            }
        }
    }

    insertaEnMitades(lista2, arbolCantidad.raiz, 0, 26,2);
    imprime(arbolCantidad.raiz);
    cout << endl << "Cantidad Niveles: " << cantNiveles(arbolCantidad.raiz);
    cout << endl << "Esta balanceado?: " << (estaBalanceado(arbolCantidad.raiz) ? "Si" : "No");

    return 0;
}
