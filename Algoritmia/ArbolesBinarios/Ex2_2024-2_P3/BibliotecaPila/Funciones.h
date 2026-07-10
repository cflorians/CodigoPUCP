//
// Created by carlo on 4/27/2026.
//

#ifndef EJERCICIOPILA_FUNCIONES_H
#define EJERCICIOPILA_FUNCIONES_H

void construir(struct Pila& pila);
void apilar(struct Pila& pila, struct ElementoPila elemento);
struct NodoPila* cima(const struct Pila& pila);
void imprimir(const struct Pila& pila);
struct NodoPila* desapilar(struct Pila& pila);

#endif //EJERCICIOPILA_FUNCIONES_H
