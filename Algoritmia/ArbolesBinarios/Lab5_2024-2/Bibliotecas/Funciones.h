//
// Created by Carlos on 26/06/2026.
//

#ifndef LAB5_2024_2_FUNCIONES_H
#define LAB5_2024_2_FUNCIONES_H

void construir(Arbol& arbol);
void insertaDiaTurno(Nodo*& nodo, const Elemento& elemento);
void imprimeNodo(Nodo* nodo);
void imprime(Nodo* nodo);
int cantNiveles(Nodo* nodo);
bool estaBalanceado(Nodo* nodo);
void insertaEnMitades(Elemento A[], Nodo*& nodo, int ini, int fin, int tipo);
void insertaCantidades(Nodo*& nodo, const Elemento& elemento);

#endif //LAB5_2024_2_FUNCIONES_H
