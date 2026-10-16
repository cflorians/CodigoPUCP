//
// Created by carlo on 4/30/2026.
//

#ifndef LISTALIGADAGENERICAORDENADA_FUNCIONES_H
#define LISTALIGADAGENERICAORDENADA_FUNCIONES_H

void crearLista(void*& lista,void* (*leer)(ifstream&), int (*comparar)(const void*, const void*),
                const char* nombArch);
void* leerDato(ifstream& arch);
char* leerCadenaExacta(ifstream& arch, char limit);
void insertarEnOrden(void*& lista,void* dato,int (*comparar)(const void*, const void*));
int compararNombre(const void* a, const void* b);
void imprimirLista(void* lista, void (*imprime)(void*, ofstream&) ,const char* nombArch);
void imprimirDato(void* dato, ofstream& arch);
int compararEdades(const void* a, const void* b);
int compararDni(const void* a, const void* b);
void invertirLista(void*& lista);
void invertirListaRecursivo(void*&lista);

#endif //LISTALIGADAGENERICAORDENADA_FUNCIONES_H
