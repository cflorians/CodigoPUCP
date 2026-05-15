#include <iostream>
using namespace std;

#include "Biblioteca/Funciones.h"
#include "Biblioteca/Pila.h"

int main() {
    struct Pila pila;
    int respuesta;

    construir(pila);
    notacionPostFija(pila);
    respuesta = cima(pila)->elemento.codigo;
    cout << respuesta << endl;

    return 0;
}
