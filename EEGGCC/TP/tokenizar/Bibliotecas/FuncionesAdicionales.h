//
// Created by carlo on 12/1/2025.
//

#ifndef TOKENIZAR_FUNCIONESADICIONALES_H
#define TOKENIZAR_FUNCIONESADICIONALES_H

void leerDatos(struct Nodo*& lista);
char* preprocesar(char* cadena);
void insertarEnLista(struct Nodo*& lista, char* coment);
void mostrarLista(const struct Nodo* lista);
void procesar(struct Nodo *&lista);

#endif //TOKENIZAR_FUNCIONESADICIONALES_H