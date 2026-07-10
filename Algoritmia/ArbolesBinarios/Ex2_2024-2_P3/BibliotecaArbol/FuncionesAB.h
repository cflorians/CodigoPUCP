//
// Created by Carlos on 8/06/2026.
//

#ifndef AB_FUNCIONESAB_H
#define AB_FUNCIONESAB_H

// FUNCIONES DE ARBOL BINARIO DE BUSQUEDA
void insertar(ArbolBinario& arbol, const Elemento& elemento);
void insertarRecursivo(Nodo*& raiz, const Elemento& elemento);
bool buscarRecursivo(Nodo* nodo, const Elemento& elemento);
int comparaElementos(int a, int b);
bool buscar(ArbolBinario& arbol, const Elemento& elemento);
Nodo* eliminar(Nodo*& raiz, int valor);
Nodo* encuentraMinimo(Nodo* nodo);

// ===========================================================
// FUNCIONES DE ARBOL BINARIO
void construir(ArbolBinario& arbol);
bool esArbolVacio(const ArbolBinario& arbol);
bool esNodoVacio(const Nodo *nodo);

void plantarArbolBinario(ArbolBinario& arbol, const ArbolBinario& izq,
                         const Elemento& elem, const ArbolBinario& der);
void plantarNodoArbolBinario(Nodo*& nodo, Nodo* izq, const Elemento& elem, Nodo* der);

void imprimeNodo(const Nodo *nodo);

void recorrePreOrden(const ArbolBinario& arbol);
void recorrePreOrdenRecursivo(const Nodo* nodo);
void recorreEnOrden(const ArbolBinario& arbol);
void recorreEnOrdenRecursivo(const Nodo* nodo);
void recorrePostOrden(const ArbolBinario& arbol);
void recorrePostOrdenRecursivo(const Nodo* nodo);

int numeroHojas(const ArbolBinario& arbol);
int numeroHojasRecursivo(Nodo *nodo);
int numeroNodos(const ArbolBinario& arbol);
int numeroNodosRecursivo(Nodo *nodo);

int altura(const ArbolBinario& arbol);
int alturaRecursivo(Nodo *nodo);
int maximo(int a, int b);

bool esEquilibrado(const ArbolBinario& arbol);
bool esEquilibradoRecursivo(Nodo *nodo);

void destruir(ArbolBinario& arbol);
void destruirRecursivo(Nodo*& nodo);

Nodo* buscaElemento(const ArbolBinario& arbol, const Elemento& elemento);
Nodo* buscaElementoRecursivo(Nodo* nodo, const Elemento& elemento);

#endif //AB_FUNCIONESAB_H
