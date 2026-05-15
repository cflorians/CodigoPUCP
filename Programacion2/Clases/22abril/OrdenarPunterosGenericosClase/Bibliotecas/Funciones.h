//
// Created by carlo on 4/22/2026.
//

#ifndef ORDENARPUNTEROSGENERICOSCLASE_FUNCIONES_H
#define ORDENARPUNTEROSGENERICOSCLASE_FUNCIONES_H

void cargarAlumnos(void*& alum, const char* nombArch);
void cargarCursos(void* alum, const char* nombArch);
void ordenarPromedios(void* alum);

void colocarCurso(ifstream& arch,void*& alum,int& nd, int& cap);

void imprimirAlumnos(void*& alum, const char* nombArch);
void imprimirAlumno(void* alu, ofstream& arch);
void imprimirCursos(void* alum,ofstream& arch);
void imprimeCurso(void* cur,ofstream& arch);

void incrementarEspacios(void**& alumnos, int& nd, int& capacidad);
void incrementarEspacios(void*& cur,int& nd,int& cap);
bool comparar(void* alum,int codigo);

void* leerRegistro(ifstream& arch);
char* leerCadena(ifstream& arch);
char* leerCadena(ifstream& arch, char limit);

int buscarAlumno(int cod,void** alumnos);
void* leerCurso(ifstream& arch);
void agregarCurso(void* curso, void*& alumCur,int nd);

void calcularPromedios(void* alum);
void promedioDelAlumno(void* alum);
double* promedio(void* alum);
int obtenerNota(void* cursos);

void qsort(void** alumnos, int izq, int der);
bool estamosEnDesorden(void* alumI, void* alumJ);
void cambiar(void*& alumI, void*& alumJ);

#endif //ORDENARPUNTEROSGENERICOSCLASE_FUNCIONES_H
