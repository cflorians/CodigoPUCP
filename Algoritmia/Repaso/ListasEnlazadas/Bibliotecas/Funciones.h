//
// Created by carlo on 4/30/2026.
//

#ifndef LISTASENLAZADAS_FUNCIONES_H
#define LISTASENLAZADAS_FUNCIONES_H

void insertarAlFinal(struct Lista& lista, struct Dato dato);
void imprimirLista(const struct Lista& lista);
void eliminarRepetidos(struct Lista& lista);

void moverMayorAInicio(struct Lista& lista);
void hallarMayor(const struct Lista& lista, struct Nodo*& mayor, struct Nodo*& antMayor);

void reordenarLista(struct Lista& lista);

#endif //LISTASENLAZADAS_FUNCIONES_H
