//
// Created by carlo on 4/26/2026.
//

#ifndef LAB2_2025_1_FUNCIONES_H
#define LAB2_2025_1_FUNCIONES_H

void inicializarLista(struct Lista& lista);
void insertarEnLista(struct Lista& lista, const struct Cuadriga& elementos);
struct Nodo* obtenerUltimoNodo(struct Lista& lista);
void imprimirLista(const struct Lista& lista);
void reordenarLista(struct Lista& lista);
void pregunta1();

void pregunta2();
void buscarVetas(int x,int y,int n,int m,int mina[][7],int combustible, int dirX, int dirY);

#endif //LAB2_2025_1_FUNCIONES_H
