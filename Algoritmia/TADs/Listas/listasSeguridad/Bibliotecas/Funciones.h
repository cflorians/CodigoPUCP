//
// Created by carlo on 4/20/2026.
//

#ifndef LISTASIMPLEMENTEENLAZADA_FUNCIONES_H
#define LISTASIMPLEMENTEENLAZADA_FUNCIONES_H

void construir(struct Lista& listaTAD);
bool esListaVacia(const struct Lista& listaTAD);
void insertarAlInicio(struct Lista& listaTAD,const struct ElementoLista& elemento);
void insertarAlFinal(struct Lista& listaTAD, const struct ElementoLista& elemento);
struct NodoLista* obtenerUltimoNodo(const struct Lista& listaTAD);
void imprimir(const struct Lista& listaTAD);
void insertarEnOrden(struct Lista& listaTAD, const struct ElementoLista& elemento);
void eliminaNodo(struct Lista& listaTAD, const struct ElementoLista& elemento);
void destruir(struct Lista& listaTAD);
struct NodoLista* obtenerNodoAnterior(const struct Lista& lista, const struct ElementoLista& elemento);
void invertirListaIterativa(struct Lista& lista);
void invertirListaRecursiva(struct Lista& lista, int n);

#endif //LISTASIMPLEMENTEENLAZADA_FUNCIONES_H
