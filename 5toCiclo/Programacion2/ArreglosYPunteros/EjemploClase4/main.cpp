#include <iostream>
using namespace std;
#include "Bibliotecas/Funciones.h"

int main(int argc, char** argv) {

    // Niveles de indireccion

    // Puntero simple p->[10]
    int *p; // guarda la direccion de memoria de un entero
    p = new int; // reserva el espacio de memoria para un puntero
    *p = 10;
    delete p; // si se hace un new, estamos obligados a hacer un delete

    int *p2;
    p2 = new int(8); // una forma abreviada de inicializar, no confundir con [8]
    cout << *p2 << endl;
    delete p2;

    // Puntero doble q -> [ ] -> [23]
    int * *q;
    q = new int*;
    *q = new int;
    **q = 23;

    // Puntero triple r -> [] -> [] -> [30]
    int *** r;
    r = new int**;
    *r = new int*;
    **r = new int;
    ***r = 30;

    // Ejemplos practicos de uso
    int **m;
    m = new int*[5];
    m[3] = new int[6];
    m[3][2] = 7;
    m[3][3] = 0;

    // *m -> [ ][ ][ ][ ][ ]
    //        0  1  2  3  4
    // m[3] -> [ ][ ][ ][ ][ ][ ]
    //          0  1  2  3  4  5
    // m[3][2] -> [ ][ ][7][ ][ ][ ]
    //             0  1  2  3  4  5

    // Para la matriz completa
    // for (int i=0; i<5; i++) m[i] = new int[6];

    // Intercambio de datos
    cout << "ANTES DEL INTERCAMBIO: " << m[3][2] << " " << m[3][3] << endl;
    int temp;
    temp = m[3][2];
    m[3][2] = m[3][3];
    m[3][3] = temp;
    cout << "DESPUES DEL INTERCAMBIO: " << m[3][2] << " " << m[3][3] << endl;

    return 0;
}