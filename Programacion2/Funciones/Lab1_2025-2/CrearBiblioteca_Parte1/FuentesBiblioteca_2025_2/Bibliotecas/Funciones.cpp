#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


#include "Funciones.h"

#include "Cursos.h"
#include "Alumnos.h"

void operator >> (ifstream& arch, struct Cursos& curso) {
    // INF263,Algoritmia,3.75,20240282,INGA_FLORES_CESAR_ADOLFO
    char buffer[10];

    arch.getline(buffer, 10, ',');
    arch.getline(curso.nombre, 50, ',');
    arch >> curso.creditos;
    arch.get();
    arch >> curso.codDocente;
    arch.get();
    arch.getline(curso.nomDocente, 50, '\n');

    curso.codigo = new char[strlen(buffer) + 1];
    strcpy(curso.codigo, buffer);
}

void operator >> (ifstream& arch, struct Alumnos& alumno) {
    // 20240282,GORDILLO/CASTRO/RONAL,P
    arch >> alumno.codigo;
    arch.get();
    arch.getline(alumno.nombre, 50, ',');
    arch >> alumno.modalidad;
}

bool operator > (struct Alumnos alumnos, int codAlumno) {
    return alumnos.codigo == codAlumno;
}

bool operator > (struct Cursos cursos, const char* codCurso) {
    return strcmp(cursos.codigo, codCurso) == 0;
}

void operator += (struct Cursos& curso, struct Alumnos alumno) {
    int cantAlumnos = curso.cantAlumnos;
    curso.alumnos[cantAlumnos] = alumno;
    curso.cantAlumnos++;
}

int operator <= (struct Alumnos* arrAlumnos, struct Alumnos alumno) {
    for (int i = 0; arrAlumnos[i].codigo != 0; i++) {
        if (arrAlumnos[i].codigo == alumno.codigo) return i;
    }
    return -1;
}

int operator >= (struct Cursos* arrCursos, struct Cursos curso) {
    for (int i = 0; arrCursos[i].codigo != nullptr; i++) {
        if (strcmp(arrCursos[i].codigo, curso.codigo) == 0) return i;
    }
    return -1;
}

void operator ++ (struct Cursos& curso) {
    double porcentaje;
    curso.cantPresencial = 0;
    curso.cantSemi = 0;
    curso.cantVirtual = 0;
    for (int i=0; i<curso.cantAlumnos; i++) {
        if (curso.alumnos[i].modalidad == 'P')  curso.cantPresencial++;
        if (curso.alumnos[i].modalidad == 'S')  curso.cantSemi++;
        if (curso.alumnos[i].modalidad == 'V')  curso.cantVirtual++;
    }

    porcentaje = (double)curso.cantPresencial/curso.cantAlumnos;

    if (porcentaje >= 0.5) strcpy(curso.tipoFinal, "La clase se dicatará en el aula");
    else strcpy(curso.tipoFinal, "La clase se dicatará 100% virtual");
}

void operator << (ofstream& arch, struct Cursos curso) {
    arch << setw(10) << left << curso.codigo;
    arch << curso.nombre << endl;
    arch << curso.nomDocente << endl;
    arch << setw(26) << left << "Alumnos presenciales:" << curso.cantPresencial << endl;
    arch << setw(26) << left << "Alumnos semipresenciales:" << curso.cantSemi << endl;
    arch << setw(26) << left << "Alumnos virtuales:" << curso.cantVirtual << endl;
    arch << curso.tipoFinal << endl;
}
