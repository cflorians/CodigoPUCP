
#ifndef LISTAS_FUNCIONESADICIONALES_H
#define LISTAS_FUNCIONESADICIONALES_H

void leerDatos(struct Nodo*& lista);
char* insertarChar(char* cadena);
void insertarEnLista(struct Nodo*& lista, struct Datos datos);
void mostrarLista(const struct Nodo* lista);
void leerDatosOrdenado(struct Nodo*& lista);
void insertarOrdenado(struct Nodo*& lista,struct Datos datos);
void eliminarPorCondicion(struct Nodo*& lista);

#endif //LISTAS_FUNCIONESADICIONALES_H