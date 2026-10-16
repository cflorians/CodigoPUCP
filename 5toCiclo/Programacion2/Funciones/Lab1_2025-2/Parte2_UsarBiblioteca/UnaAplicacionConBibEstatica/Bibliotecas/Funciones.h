//
// Created by carlo on 4/5/2026.
//

#ifndef FUENTESBIBLIOTECA_2025_2_FUNCIONES_H
#define FUENTESBIBLIOTECA_2025_2_FUNCIONES_H

void operator >> (ifstream& arch, struct Cursos& curso);
void operator >> (ifstream& arch, struct Alumnos& alumno);

bool operator > (struct Alumnos alumnos, int codAlumno);
bool operator > (struct Cursos cursos, const char* codCurso);

void operator += (struct Cursos& curso, struct Alumnos alumno);

int operator <= (struct Alumnos* arrAlumnos, struct Alumnos alumno);
int operator >= (struct Cursos* arrCursos, struct Cursos curso);

void operator ++ (struct Cursos& curso);

void operator << (ofstream& arch, struct Cursos curso);

#endif //FUENTESBIBLIOTECA_2025_2_FUNCIONES_H
