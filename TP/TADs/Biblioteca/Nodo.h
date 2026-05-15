//
// Created by carlo on 12/1/2025.
//

#ifndef TADS_NODO_H
#define TADS_NODO_H

#include "Curso.h"
#include "Escala.h"
#include "Alumno.h"

struct NodoCurso {
    struct Curso dato;
    struct NodoCurso* next;
};

struct NodoEscala {
    struct Escala dato;
    struct NodoEscala* next;
};

struct NodoAlumno {
    struct Alumno dato;
    struct NodoAlumno* next;
};

#endif //TADS_NODO_H