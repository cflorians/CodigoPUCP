#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Bibliotecas/FuncionesAdicionales.h"

int main(int  argc, char *argv[])
{
    int arr[10]{}, cantDatos, max, min, i, indicesOrd[10]{};

    cargarDatos(arr, cantDatos);
    encontrarMaxyMin(arr, cantDatos, max, min);
    imprimir(arr, cantDatos);

    cout << "El maximo es: " << max << endl;
    cout << "El minimo es: " << min << endl;

    ordenamientoPorIndices(arr, cantDatos, indicesOrd);

    for (i=0; i<cantDatos; i++)
    {
        cout << arr[indicesOrd[i]] << endl;
    }

    return 0;
}