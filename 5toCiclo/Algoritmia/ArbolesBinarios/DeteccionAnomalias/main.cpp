#include <iostream>
using namespace std;

#include "BibliotecaArbolBinarioBusqueda/ArbolBinario.h"
#include "BibliotecaArbolBinarioBusqueda/FuncionesAB.h"

void aplicarNodo(Nodo* paquete, Nodo* sistema, Nodo*& resultado) {
    if (esNodoVacio(paquete)) return;

    int numeroNodo = numeroNodosRecursivo(sistema);
    int numeroHojas = numeroHojasRecursivo(sistema);

    plantarNodoArbolBinario(resultado, nullptr, {paquete->elemento.numero+numeroNodo-numeroHojas}, nullptr);
    aplicarNodo(paquete->izq, sistema->izq, resultado->izq);
    aplicarNodo(paquete->der, sistema->der, resultado->der);
}

ArbolBinario aplicarArbol(ArbolBinario& paquetes, ArbolBinario& sistema) {
    ArbolBinario arbolResultado;
    construir(arbolResultado);
    aplicarNodo(paquetes.raiz, sistema.raiz, arbolResultado.raiz);
    return arbolResultado;
}

int sumaNodos(Nodo* nodo) {
    if (esNodoVacio(nodo)) return 0;
    return sumaNodos(nodo->izq) + sumaNodos(nodo->der) + nodo->elemento.numero;
}

bool determinarAnomalia(const ArbolBinario& arbolResultado) {
    return esABB(arbolResultado.raiz) and sumaNodos(arbolResultado.raiz);
}

int main() {

    ArbolBinario arbolSistema;
    ArbolBinario arbolPaquetes;
    ArbolBinario arbolResultado;

    construir(arbolSistema);
    construir(arbolPaquetes);
    construir(arbolResultado);

    insertar(arbolPaquetes, {5});
    insertar(arbolPaquetes, {3});
    insertar(arbolPaquetes, {9});
    insertar(arbolPaquetes, {6});

    // recorreEnOrden(arbolPaquetes);

    ArbolBinario a1, a2, a3, a4;
    construir(a1);
    construir(a2);
    construir(a3);
    construir(a4);

    plantarArbolBinario(a1, {nullptr}, {2}, {nullptr});
    plantarArbolBinario(a2, {nullptr}, {3}, {nullptr});
    plantarArbolBinario(a3, {nullptr}, {8}, {nullptr});
    plantarArbolBinario(a4, a1, {7}, a2);
    plantarArbolBinario(arbolSistema, a4, {1}, a3);

    // recorreEnOrden(arbolSistema);

    arbolResultado = aplicarArbol(arbolPaquetes, arbolSistema);

    recorreEnOrden(arbolResultado);

    // ======================================
    // Determinamos anomalia

    cout << (determinarAnomalia(arbolResultado) ?
            "Sin eventos sospechosos":"Anomalia detectada") << endl;

    return 0;
}
