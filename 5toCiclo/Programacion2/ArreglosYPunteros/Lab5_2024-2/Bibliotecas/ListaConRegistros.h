//
// Created by carlo on 5/7/2026.
//

#ifndef LAB5_2024_2_LISTACONREGISTROS_H
#define LAB5_2024_2_LISTACONREGISTROS_H

void* leeregistros(ifstream& arch);
char* leerCadena(ifstream& arch, char limit = ',');
int compruebaregistro(const void* a, const void* b);
void* leeordenes(ifstream& arch);
void imprimeregistros(ofstream& arch, const void* act);

#endif //LAB5_2024_2_LISTACONREGISTROS_H
