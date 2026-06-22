//
// Created by carlo on 5/7/2026.
//

#ifndef LAB5_2024_2_LISTACONENTEROS_H
#define LAB5_2024_2_LISTACONENTEROS_H

void* leenumeros(ifstream& arch);
int compruebanumero(const void* dat, const void* reg);
void* leeregnumeros(ifstream& arch);
void imprimenumeros(ofstream& arch, const void* actual);

#endif //LAB5_2024_2_LISTACONENTEROS_H
