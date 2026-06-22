#include <iostream>
using namespace std;

#include "Bibliotecas/ArbolBinario.h"
#include "Bibliotecas/FuncionesAB.h"

void insertarValorNodoArbolBinario(Nodo*& nodo, int num, int valor) {
    // con el if bajamos hasta encontrar un nodo vacio e insertamos
    if (esNodoVacio(nodo)) {
        Elemento elemento;
        // asigno los valores
        elemento.numero = num;
        elemento.valor = valor;
        // planto
        plantarNodoArbolBinario(nodo, nullptr, elemento, nullptr);
        return;
    }
    insertarValorNodoArbolBinario(nodo->izq, num, 0);
    insertarValorNodoArbolBinario(nodo->der, num, 1);
}

void insertarValorArbolBinario(ArbolBinario& cromosoma, int num){
    // enviar un 0 o un 1 es indistinto, porque la pauta se marca dentro de la funcion
    insertarValorNodoArbolBinario(cromosoma.raiz, num, 0);
}

int numeroCombinacionesNodo(Nodo *nodo,int limite,int acumuladorPesos) {
    acumuladorPesos += (nodo->elemento.numero*nodo->elemento.valor);
    if (nodo->izq == nullptr and nodo->der == nullptr) {
        if (acumuladorPesos == limite) {
            return 1;
        }
        else {
            return (numeroCombinacionesNodo(nodo->izq, limite, acumuladorPesos)+
                numeroCombinacionesNodo(nodo->der, limite, acumuladorPesos));
        }
    }

}

int numeroCombinaciones(ArbolBinario& cromosoma,int limite) {
    int acumuladorPesos = 0;
    return numeroCombinacionesNodo(cromosoma.raiz, limite, acumuladorPesos);
}

int main() {
    const int cantidad_paquetes = 5;
    int paquetes[cantidad_paquetes]{10, 50, 20, 30, 40}; // [10, 50]

    ArbolBinario cromosoma; // donde crearemos la estuctura arbol-cromosoma
    construir(cromosoma);

    // PARTE a) construir el arbol cromosoma a partir de un arreglo paquetes[];
    Elemento elemento;
    elemento.numero = 0;
    elemento.valor = 0;

    plantarArbolBinario(cromosoma, {nullptr}, elemento, {nullptr});

    for (int i=0; i < cantidad_paquetes; i++) {
        insertarValorArbolBinario(cromosoma, paquetes[i]); // [10] -> [50] -> ...
    }

    recorrePostOrden(cromosoma);

    // PARTE b) Limitante peso = 70;
    int limite = 70;
    cout << "Número de combincaciones" << numeroCombinaciones(cromosoma, limite) << endl;

    return 0;
}
