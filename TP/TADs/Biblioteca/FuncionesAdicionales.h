//
// Created by carlo on 12/1/2025.
//

#ifndef TADS_FUNCIONESADICIONALES_H
#define TADS_FUNCIONESADICIONALES_H

void leerCursos(struct NodoCurso*& lista);
char* insertarChar(char* cadena);
void insertarEnLista(struct NodoCurso*& lista, struct Curso nodo);
void leerEscalas(struct NodoEscala*& lista);
void insertarEnLista(struct NodoEscala*& lista, struct Escala nodo);
void leerAlumnos(struct NodoAlumno*& lista);
void insertarEnListaOrdenado(struct NodoAlumno*& lista, struct Alumno nodo);
void emitirReporte(const char* nombArch, const struct NodoAlumno* lista, bool preeliminar);
void separador(ofstream& arch, char separador);
void leerMatricula(int anho, int cicloLeido, struct NodoAlumno*& lista, struct NodoEscala* listaEscalas, struct NodoCurso* listaCursos);
struct NodoAlumno* buscarAlumno(int codigo, struct NodoAlumno* lista);
struct NodoEscala* buscarEscala(char escala, struct NodoEscala* lista);
struct NodoCurso* buscarCurso(int codigo, struct NodoCurso* lista);
void eliminarAlumnos(int anio, int ciclo, struct NodoAlumno*& lista);

#endif //TADS_FUNCIONESADICIONALES_H