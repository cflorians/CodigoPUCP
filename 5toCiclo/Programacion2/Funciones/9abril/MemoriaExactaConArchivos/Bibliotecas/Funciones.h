//
// Created by carlo on 4/9/2026.
//

#ifndef MEMORIAEXACTACONARCHIVOS_FUNCIONES_H
#define MEMORIAEXACTACONARCHIVOS_FUNCIONES_H

void cargarDatos(const char* nombArch, int*& codigos,char**& nombres);
void cargarDatos(const char* nombArch,int* codigos,char***& cursos);
void imprimirDatos(const char* nombArch,int* codigos, char** nombres,char*** cursos);
char* leerNombre(ifstream& arch);
int buscaAlumno(int* codigos,int codigo);
void colocarCursoEnAlumno(char**& cursos,char* curso, int& cant);
void asignarEspaciosExactos(char**& cursos, int cant);

#endif //MEMORIAEXACTACONARCHIVOS_FUNCIONES_H
