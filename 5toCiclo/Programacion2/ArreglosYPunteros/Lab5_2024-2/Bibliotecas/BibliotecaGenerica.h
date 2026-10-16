//
// Created by carlo on 5/7/2026.
//

#ifndef LAB5_2024_2_BIBLIOTECAGENERICA_H
#define LAB5_2024_2_BIBLIOTECAGENERICA_H

void crealista(void*& lista, void* (*leer)(ifstream&), const char* nombArch);
void construir(void*& list);
void insertarfinal(void*& list, void* reg);
bool eslistavacia(const void* lista);
void insertar(void* dupla, void*& list);
void cargalista(void* list, int (*comprueba)(const void*, const void*),
                void* (*leer)(ifstream&), const char* nombArch);
void muestralista(const void* list, void (*imprime)(ofstream&,const void*), const char* nombArch);

#endif //LAB5_2024_2_BIBLIOTECAGENERICA_H
