#include <iostream>
using namespace std;
#include "Funciones.h"

int main(int argc, char** argv) {

    int valor;
    int arreglo[10]={3,2,1,4,2,7,9,5}; // arreglo de números
    int n = 8; // cantidad de datos del arreglo
    int k = 6;

    mostrarArreglo(arreglo,n);
    cout << "BUSQUEDA: ";
    valor = BusquedaSecuencia(arreglo, n, k);

    if (valor!=-1) cout << "Se econtro en la posicion: " << valor+1 << endl;
    else cout << "No se encontro el numero" << endl;

    cout << "ORDENAMIENTO: " << endl;
    OrdenamientoSeleccion(arreglo,n);
    mostrarArreglo(arreglo,n);

    //TAREA: hacer ordenamiento burbuja
    return 0;
}