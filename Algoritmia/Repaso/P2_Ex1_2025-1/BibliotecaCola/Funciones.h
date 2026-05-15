//
// Created by carlo on 5/15/2026.
//

#ifndef P2_EX1_2025_1_FUNCIONES_H
#define P2_EX1_2025_1_FUNCIONES_H

void construirCola(Cola& cola);
void encolar(Cola& cola, const Elemento& elemento);
Nodo* desencolar(Cola& cola);
double calcularPromedio(Cola& cola);
int sumarYRotar(Cola& cola,int n);
void imprimirCola(Cola& cola);

#endif //P2_EX1_2025_1_FUNCIONES_H
