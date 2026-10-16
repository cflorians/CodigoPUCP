//
// Created by carlo on 5/4/2026.
//

#ifndef COLAS_FUNCIONES_H
#define COLAS_FUNCIONES_H

void construir(struct Cola& cola);
void encolar(struct Cola& cola, const struct Elemento& elemento);
struct Elemento desencolar(struct Cola& cola);
void imprimir(const struct Cola& cola);
void ordenarCola(struct Cola& cola, int n);
void ordenarRecursivo(struct Cola& cola, int n);

#endif //COLAS_FUNCIONES_H
