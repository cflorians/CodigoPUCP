#include <iostream>
using namespace std;

#include "Biblioteca/Funciones.h"
#include "Biblioteca/Lista.h"

int main(int argc, char** argv) {

    struct ElementoLista elemento;
    struct Lista listaInicio{};

    construir(listaInicio);
    cout << "Si la lista esta vacía: " << esListaVacia(listaInicio) << endl;

    for (int i=0; i<5; i++) {
        elemento.codigo = i;
        insertarAlInicio(listaInicio, elemento);
    }

    struct Lista listaFinal{};
    construir(listaFinal);
    for (int i=0; i<5; i++) {
        elemento.codigo = i;
        insertarAlFinal(listaFinal, elemento);
    }
    imprimir(listaInicio);
    elemento.codigo = 10;
    insertarAlFinal(listaFinal, elemento);
    elemento.codigo = 7;
    insertarEnOrden(listaFinal, elemento);
    imprimir(listaFinal);
    eliminaNodo(listaFinal, elemento);
    imprimir(listaFinal);
    // destruir(listaFinal);
    // imprimir(listaFinal);

    // invertirListaIterativa(listaFinal);
    invertirListaRecursiva(listaFinal, listaFinal.longitud);
    imprimir(listaFinal);

    return 0;
}
