//
// Created by carlo on 4/27/2026.
//

#ifndef EJERCICIOPILA_FUNCIONES_H
#define EJERCICIOPILA_FUNCIONES_H

void construir(struct Pila& pila);
void apilar(struct Pila& pila, struct ElementoPila elemento);
struct NodoPila* cima(const struct Pila& pila);
void imprimir(const struct Pila& pila);
void notacionPostFija(struct Pila& pila);
struct NodoPila* desapilar(struct Pila& pila);
bool esOperador(char* c);
int opera(char* c,int operando1,int operando2);
void pasaPila(struct Pila& pila1, struct Pila& pila2);
void pasaPilaRecursiva(struct Pila& pila1, struct Pila& pila2);

#endif //EJERCICIOPILA_FUNCIONES_H
