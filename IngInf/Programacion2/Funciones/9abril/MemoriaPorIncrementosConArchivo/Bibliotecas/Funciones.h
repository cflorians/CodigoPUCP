//
// Created by carlo on 4/9/2026.
//

#ifndef MEMORIAPORINCREMENTOSCONARCHIVO_FUNCIONES_H
#define MEMORIAPORINCREMENTOSCONARCHIVO_FUNCIONES_H

void cargarDatos(const char* nombArch,int*& codigos,char**& nombres,char***& cursos);
void imprimirDatos(const char* nombArch,int*& codigos,char**& nombres,char***& cursos);
void imprimirCursos(ofstream& arch,char** cursos);
char* leeNombre(ifstream& arch);
char** leeCursos(ifstream& arch);
char* leeCurso(ifstream& arch);
void incrementarEspacios(int*& codigos, char**& nombres, char***& cursos, int& numDatos, int&capacidad);
void incrementarEspacios(char**& cursos,int& numCursos,int& capacidad);

#endif //MEMORIAPORINCREMENTOSCONARCHIVO_FUNCIONES_H
