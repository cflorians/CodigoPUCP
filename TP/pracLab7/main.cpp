#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Biblioteca/FuncionesAdicionales.h"

int main(int argc, char *argv[]) {

    ifstream arch("ArchivosDeDatos/arch.txt", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir archivo" << endl;
        exit(1);
    }

    // int cantNombres;
    // char *nombres[25]{}, nombre[150]{};
    // char *nueva;
    //
    // cantNombres = 0;
    // while (arch.peek() != '\n') {
    //     arch >> nombre;
    //
    //     toMayus(nombre);
    //
    //     nueva = new char [strlen(nombre) + 1];
    //     strcpy(nueva, nombre);
    //     nombres[cantNombres] = nueva;
    //
    //     cantNombres++;
    // }
    //
    // ordenarPorNombre(nombres, cantNombres);
    //
    // for (int i=0; i < cantNombres; i++) {
    //     cout << nombres[i] << endl;
    // }

    int cantNombres;
    char nombres[150]{}, nombre[25]{};
    char *nueva;

    cantNombres = 0;
    while (arch.peek() != '\n') {
        arch >> nombre;

        toMayus(nombre);

        concatenar(nombres, nombre);
        concatenar(nombres, " ");
    }

    cout << nombres << endl;

    return 0;
}