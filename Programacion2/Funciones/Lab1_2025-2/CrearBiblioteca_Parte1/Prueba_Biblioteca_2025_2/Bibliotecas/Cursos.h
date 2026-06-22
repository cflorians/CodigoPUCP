//
// Created by carlo on 4/5/2026.
//

#ifndef FUENTESBIBLIOTECA_2025_2_CURSOS_H
#define FUENTESBIBLIOTECA_2025_2_CURSOS_H

#include "Alumnos.h"

struct Cursos {
    char* codigo;
    char nombre[50];
    double creditos;
    int codDocente;
    char nomDocente[50];
    struct Alumnos alumnos[100];
    int cantAlumnos;
    int cantPresencial;
    int cantSemi;
    int cantVirtual;
    char tipoFinal[50];
};

#endif //FUENTESBIBLIOTECA_2025_2_CURSOS_H
