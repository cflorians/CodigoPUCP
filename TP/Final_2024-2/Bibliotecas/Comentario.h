//
// Created by carlo on 11/28/2025.
//

#ifndef FINAL_2024_2_COMENTARIO_H
#define FINAL_2024_2_COMENTARIO_H

#include "Palabra.h"

struct Comentario {
    char* texto;
    char* pre_procesado;
    struct Palabra palabras[20];
    int cantidadPalabras;
    int polaridadTotal;
};

#endif //FINAL_2024_2_COMENTARIO_H