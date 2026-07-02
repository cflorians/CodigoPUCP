//
// Created by Carlos on 1/07/2026.
//

#ifndef LAB4_2024_2_P2_FUNCIONES_H
#define LAB4_2024_2_P2_FUNCIONES_H
#include "Arbol.h"
#include "Pila.h"

void construir(Arbol& arbol);
void ingresaLote(Arbol& arbol, const Elemento& elemento);
void ingresaRecursivo(Nodo*& nodo, const Elemento& elemento);
void imprimeNodo(Nodo* nodo);
void imprimir(const Arbol& arbol);
bool esPilaVacia(const Pila& pila);
void push(Pila& pila, Nodo* nodo);
Nodo* pop(Pila& pila);

#endif //LAB4_2024_2_P2_FUNCIONES_H
