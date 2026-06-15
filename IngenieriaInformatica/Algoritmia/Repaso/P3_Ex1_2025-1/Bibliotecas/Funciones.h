//
// Created by carlo on 5/14/2026.
//

#ifndef P3_EX1_2025_1_FUNCIONES_H
#define P3_EX1_2025_1_FUNCIONES_H

void construir(Pila& pila);
void apilar(Pila& pila, const Elemento& elemento);
Nodo* desapilar(Pila& pila);
Nodo* cima(Pila& pila);
bool esPilaVacia(Pila& pila);
Elemento minimo(Pila& pila, Pila& aux);

#endif //P3_EX1_2025_1_FUNCIONES_H
