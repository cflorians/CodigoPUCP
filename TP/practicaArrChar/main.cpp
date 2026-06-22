#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Bibliotecas/FuncionesAuxiliares.h"

int main(int argc, char* argv[]) {

    char nombre[50]{}, nombre2[50]{}, apellido1[50]{}, apellido2[50]{};
    char nombreCopiado[50];

    cin >> nombre >> nombre2 >> apellido1 >> apellido2;
    // concatenar(nombre, " ");
    // concatenar(nombre, nombre2);
    // concatenar(nombre, " ");
    // concatenar(nombre, apellido1);
    // concatenar(nombre, " ");
    // concatenar(nombre, apellido2);
    // aMayusculas(nombre);

    strncat(nombre, " ", sizeof(nombre)-1);
    strncat(nombre, nombre2, sizeof(nombre)-1);

    cout << nombre << endl;

    return 0;
}