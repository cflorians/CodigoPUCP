//
// Created by Carlos on 5/21/2026.
//

#ifndef P3_FUNCIONES_H
#define P3_FUNCIONES_H

void construir(Lista& lista);
bool estaVacia(const Lista& lista);
void insertarInicio(Lista& lista, const Elemento& elemento);
void insertarFinal(Lista& lista, const Elemento& elemento);
void imprimir(const Lista& lista);
int fuerza(const Lista& lista);
void insertarOrdenado(Lista& lista, Nodo* nodo);
Nodo* quitarNodo(Lista& lista);
void distribuirGuerreros(Lista& lista, Lista& bowser, Lista& peach, Lista& donkey);
void fusionarListas(Lista& lista1, Lista& lista2);
void batalla(Lista& lista1, Lista& lista2, Lista& lista3, int n);

#endif //P3_FUNCIONES_H
