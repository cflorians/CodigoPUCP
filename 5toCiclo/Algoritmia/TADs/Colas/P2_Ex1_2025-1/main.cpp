#include <iostream>
using namespace std;


#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/Funciones.h"
#include "Bibliotecas/Lista.h"
#include "Bibliotecas/Funciones.h"


int main() {

    // APARTADO A
    // Lista lista;
    //
    // insertarAlFinal(lista, {1, 10, 'B'});
    // insertarAlFinal(lista, {2, 20, 'A'});
    // insertarAlFinal(lista, {3, 15, 'B'});
    // insertarAlFinal(lista, {4, 12, 'B'});
    // insertarAlFinal(lista, {5, 5, 'C'});
    // insertarAlFinal(lista, {6, 6, 'A'});
    // insertarAlFinal(lista, {7, 8, 'C'});
    // insertarAlFinal(lista, {8, 4, 'C'});
    // insertarAlFinal(lista, {9, 2, 'B'});
    //
    // imprimir(lista);
    //
    // reorganizar(lista);
    //
    // imprimir(lista);

    // APARTADO B
    Cola temperaturas;
    int temp, k;

    construirCola(temperaturas);

    cout << "Ingrese K: ";
    cin >> k;
    while (true) {
        cout << "Ingrese Temperatura: ";
        cin >> temp;
        if (temp == -1) break;
        if (temperaturas.longitud < k) {
            encolar(temperaturas, {temp});
        }
        else {
            desencolar(temperaturas);
            encolar(temperaturas, {temp});
        }
        imprimirCola(temperaturas);
        cout << "Promedio: " <<
            calcularPromedio(temperaturas) << endl;
    }


    return 0;
}
