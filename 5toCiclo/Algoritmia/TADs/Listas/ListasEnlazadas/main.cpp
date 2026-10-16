#include <iostream>
using namespace std;

#include "Bibliotecas/Listas.h"
#include "Bibliotecas/Funciones.h"

int main(int argc, char** argv) {
    
    // ---------------NIVEL 1-----------------
    struct Lista lista;
    // inicializamos lista
    lista.inicio = nullptr;
    lista.longitud = 0;
    // insertamos los datos
    insertarAlFinal(lista, {1});
    insertarAlFinal(lista, {2});
    insertarAlFinal(lista, {2});
    insertarAlFinal(lista, {2});
    insertarAlFinal(lista, {3});
    insertarAlFinal(lista, {3});
    insertarAlFinal(lista, {4});
    insertarAlFinal(lista, {5});
    // mostramos la lista
    imprimirLista(lista);
    // eliminamos los repetidos
    eliminarRepetidos(lista);
    // volvemos a mostrar la lista
    imprimirLista(lista);
    cout << endl;

    // ---------------NIVEL 2-----------------
    struct Lista lista2;
    lista2.inicio = nullptr;
    lista2.longitud = 0;
    // Insertamos datos
    insertarAlFinal(lista2, {7});
    insertarAlFinal(lista2, {4});
    insertarAlFinal(lista2, {3});
    insertarAlFinal(lista2, {9});
    insertarAlFinal(lista2, {1});
    imprimirLista(lista2);
    // Hacemos lo que pide
    moverMayorAInicio(lista2);
    imprimirLista(lista2);
    cout << endl;

    // ---------------NIVEL 3-----------------
    struct Lista lista3;
    lista3.inicio = nullptr;
    lista3.longitud = 0;

    insertarAlFinal(lista3, {13});
    insertarAlFinal(lista3, {20});
    insertarAlFinal(lista3, {21});
    insertarAlFinal(lista3, {9});
    insertarAlFinal(lista3, {14});
    insertarAlFinal(lista3, {17});
    imprimirLista(lista3);
    // reordenamos la lista
    reordenarLista(lista3);
    // mostramos la lista reordenada
    imprimirLista(lista3);

    return 0;
}
