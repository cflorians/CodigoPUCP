//
// Created by Carlos on 10/07/2026.
//

#ifndef ARBOLBINARIO_FUNCIONES_H
#define ARBOLBINARIO_FUNCIONES_H

void construir(Arbol& arbol);
void destruir(Arbol& arbol);
void destruir(Nodo* nodo);

void plantar(Arbol& arbol, const Elemento& elemento ,Nodo* izq, Nodo* der);
void insertar(Arbol& arbol, int num);
void insertar(Nodo*& nodo, const Elemento& elemento);

Nodo* buscarElemento(const Arbol& arbol, const Elemento& elemento);
Nodo* buscarElemento(Nodo* nodo, const Elemento& elemento);
Nodo* buscarElementoIterativo(const Arbol& arbol, const Elemento& elemento);
void imprimePorNivel(const Arbol& arbol);

Nodo* eliminaNodo(Arbol& arbol, int num);
Nodo* eliminaNodo(Nodo *nodo, int num);

Nodo* buscaMinimo(Nodo *nodo);

int cantNiveles(const Arbol& arbol);
int cantNiveles(Nodo* nodo);
int cantNodos(Arbol& arbol);
int cantNodos(Nodo* nodo);
bool balanceado(const Arbol& arbol);
bool balanceado(Nodo *nodo);

void balanceaArbol(Arbol& arbol);
Nodo* construirArbolBalanceado(Elemento* A, int ini, int fin);
void almacenarInOrden(Nodo* nodo, Elemento* A, int& indice);

int obtenerFactorEquilibrio(Nodo* nodo);
void insertarAVL(Arbol& arbol, int num);
Nodo* insertarAVL(Nodo* nodo, const Elemento& elemento);
Nodo* rotarDer(Nodo* y);
Nodo* rotarIzq(Nodo* x);

#endif //ARBOLBINARIO_FUNCIONES_H
