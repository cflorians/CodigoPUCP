//
// Created by carlo on 4/29/2026.
//

#ifndef LISTALIGADAGENERICAORDENADA_FUNCIONES_H
#define LISTALIGADAGENERICAORDENADA_FUNCIONES_H

void crearLista(void*& lista, void*(*leer)(ifstream&),
                int(*comparar)(const void*, const void*),
                const char* nombArch);
void* leerDato(ifstream& arch);
char* leerCadena(ifstream& arch, char limit);
void insertar(void*& lista, void* dato, int(*comparar)(const void*, const void*));

#endif //LISTALIGADAGENERICAORDENADA_FUNCIONES_H
