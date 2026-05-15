//
// Created by carlo on 4/17/2026.
//

#ifndef LAB2_2024_1_FUNCIONES_H
#define LAB2_2024_1_FUNCIONES_H

void lecturaDeLibros(const char* nombArch,char***& libros,int**& stock);
void pruebaDeLecturaDeLIbros(const char* nombArch,char*** libros,int** stock);
void atencionDePedidos(const char* nombArch,char*** libros,int** stock,int**& pedidosClientes,
                       char***& pedidosLibros,bool**& pedidosAtendidos);

#endif //LAB2_2024_1_FUNCIONES_H
