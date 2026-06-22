//
// Created by carlo on 5/7/2026.
//

#ifndef LAB4_2025_1_BIBLIOTECAGENERICA_H
#define LAB4_2025_1_BIBLIOTECAGENERICA_H

void crearLista(void*& lista, void* (*leenum)(ifstream&), int (*clasifica)(const void*),
                const char* nombArch);
void generaLista(void*& list);
void insertarLista(void*& list, void* dat, int (*comparar)(const void*));
int clasificaEntero(const void* num);
void* leerNumero(ifstream& arch);
void imprimeLista(void* list,void (*imprimeDato)(ofstream&, const void*), const char* nombArch);
void imprimenum(ofstream& arch, const void* reg);
void* leeregistro(ifstream& arch);
char* leerCadena(ifstream& arch, char limit);
int clasificaregistro(const void* reg);
void imprimeregistro(ofstream& arch, const void* reg);

#endif //LAB4_2025_1_BIBLIOTECAGENERICA_H
