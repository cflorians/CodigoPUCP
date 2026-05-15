//
// Created by carlo on 5/14/2026.
//

#ifndef P1_LAB3_2023_1_FUNCIONES_H
#define P1_LAB3_2023_1_FUNCIONES_H

void construir(Pila& pila);
void apilar(Pila& pila, const Elemento& elemento);
bool esPilaVacia(Pila& pila);
Nodo* desapilar(Pila& pila);
Nodo* cima(const Pila& pila);
void imprimir(Pila& pila);
void unirPilas(Pila& pila1, Pila& pila2);
void ordenarPila(Pila& pila1, Pila& pila2);
void pasaPila(Pila& pila1, Pila& pila2);

#endif //P1_LAB3_2023_1_FUNCIONES_H
