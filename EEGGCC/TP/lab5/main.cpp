#include <iostream>
#include <iomanip>
using namespace std;
#include "Bibliotecas/FuncionesAdicionales.h"

int main(int argc, char *argv[])
{
    int arr[10]{}, n, min, max, indicesOrdenados[10]{}, arrSinDup[10]{};
    int cantDatos, cantSinDup;

    cargarDatos(arr, cantDatos);
    for (int i = 0; i < cantDatos; i++)
    {
        cout << i << "  ";
    }
    cout << endl;
    imprimirArreglo(arr, cantDatos);

    //buscarPosNumero(n , arr, cantDatos);
    //hallarMinYMax(min, max, arr, cantDatos);

    //invertirOrden(arr, cantDatos);
    //imprimirArreglo(arr, cantDatos);

    //ordenamientoBurbuja(arr, cantDatos);
    //imprimirArreglo(arr, cantDatos);

    //ordenamientoPorIndices(arr, cantDatos, indicesOrdenados);
    //imprimirArreglo(indicesOrdenados, cantDatos);

    eliminarDuplicados(arr, cantDatos, cantSinDup, arrSinDup);
    imprimirArreglo(arrSinDup, cantSinDup);

    return 0;
}