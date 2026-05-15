#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Biblioteca/FuncionesAuxiliares.h"

int main(int argc, char *argv[]) {

    // INSERSION ORDENADA
    int numeros[15]{}, cantNumeros, n, pos;
    ifstream arch;
    abrirArchivo(arch,"ArchivosDeDatos/Source.txt");
    cantNumeros=0;
    while (not arch.eof()) {
        arch >> n;
        pos = buscarPos(numeros,cantNumeros, n);
        crearEspacio(numeros,cantNumeros,pos);
        numeros[pos] = n;
    }
    mostrarArreglo(numeros, cantNumeros);

    // BUSQUEDA BINARIA
    int objetivo, posicion;
    cout << endl << "Ingrese un numero a buscar: ";
    cin >> objetivo;
    posicion = busquedaBinaria(numeros, cantNumeros, objetivo);
    if (posicion != -1) {
        cout << "El numero " << objetivo << " esta en la posicion " << posicion << endl;
    }
    else {
        cout << "No se encontro dicho numero" << endl;
    }

    // ELIMINACION
    eliminarPorIndice(numeros, cantNumeros, posicion);
    mostrarArreglo(numeros, cantNumeros);

    return 0;
}