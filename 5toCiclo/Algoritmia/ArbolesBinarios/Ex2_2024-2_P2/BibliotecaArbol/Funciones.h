//
// Created by Carlos on 9/07/2026.
//

#ifndef EX2_2024_2_P2_FUNCIONES_H
#define EX2_2024_2_P2_FUNCIONES_H

void construir(Arbol& arbol);
void plantar(Arbol& arbol, Nodo* izq ,const Elemento& elemento, Nodo* der);
void recorrePreOrden(const Arbol& arbol);
void recorrePreOrden(Nodo* nodo);
void insertar(Arbol& arbol, const Elemento& elemento);
void insertar(Nodo*& nodo, const Elemento& elemento);
int maximo(const Arbol& arbol);
int maximo(Nodo* nodo);

#endif //EX2_2024_2_P2_FUNCIONES_H
