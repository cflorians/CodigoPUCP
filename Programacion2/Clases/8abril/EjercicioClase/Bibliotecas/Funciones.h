//
// Created by carlo on 4/8/2026.
//

#ifndef EJERCICIOCLASE_FUNCIONES_H
#define EJERCICIOCLASE_FUNCIONES_H

void cargarDatos(const char* nombArch,int*& codigos,char**& nombres,char***& cursos);
void imprimirDatos(const char* nombArch,int*& codigos,char**& nombres,char***& cursos);
void imprimirCursos(ofstream& arch,char** cursos);
char* leeNombre(ifstream& arch);
char** leeCursos(ifstream& arch);
char* leeCurso(ifstream& arch);

#endif //EJERCICIOCLASE_FUNCIONES_H
