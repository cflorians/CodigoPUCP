//
// Created by carlo on 4/27/2026.
//

#ifndef EJERCICIOPILA_FUNCIONES_H
#define EJERCICIOPILA_FUNCIONES_H

void construir(struct Pila& pila);
void apilar(struct Pila& pila, struct Elemento elemento);
struct Nodo* cima(const struct Pila& pila);
void imprimirPila(const struct Pila& pila);
void notacionPostFija(struct Pila& pila);
struct Nodo* desapilar(struct Pila& pila);
bool esOperador(char* c);
int opera(char* c,int operando1,int operando2);

#endif //EJERCICIOPILA_FUNCIONES_H
