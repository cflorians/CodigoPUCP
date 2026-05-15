//
// Created by carlo on 12/1/2025.
//

#ifndef TADS_ALUMNO_H
#define TADS_ALUMNO_H

#include "Curso.h"
#include "Escala.h"

struct Alumno {
    int codAlumno;
    char* nombre;
    struct Escala escAlumno;
    struct Curso cursos[8];
    int cantidadCursos;
    double totalCreditos;
    double totalPago;
};

#endif //TADS_ALUMNO_H