//
// Created by carlo on 11/2/2025.
//

#ifndef LAB7_2023_2_FUNCIONESADICIONALES_H
#define LAB7_2023_2_FUNCIONESADICIONALES_H

void leerDatosAlumnos(int* codigoAlumno, char** nombreAlumno, char* escalaAlumno, int& cantAlumnos);
void quitarGuiones(char* cadena);
void toMayus(char* cadena);
char* insertarNombre(char* cadena);
void leerDatosCursos(int* codigoCurso, double* creditosCurso, int& cantCursos);
void leerDatosEscalas(int *anioEscala, int* cicloEscala, char* escalaValor, double* costoCredito, int& cantEscalas);
void procesarMatricula(int anio, int ciclo, int* cantCursosAlumno, double* numCreditosAlumno, double* montoPagado,
                       int* codigoCurso, double* creditosCurso, int& cantCursos, int* codigoAlumno,
                       char* escalaAlumno, int cantAlumnos, int *anioEscala, int* cicloEscala, char* escalaValor,
                       double* costoCredito, int cantEscalas);
int buscarValorCredito(char escalaAlumno, int anio, int ciclo, int* anioEscalas, int* cicloEscalas,
                       char* escalaValor, int cantEscalas);
int buscarAlumno(int codigoBuscado, int* codigoAlumno, int cantAlumnos);
int buscarCurso(int cursoBuscado, int* codigoCurso, int cantCursos);
void ordenarAlumnos(int* codigoAlumno, char** nombreAlumno, char* escalaAlumno, int cantAlumnos);
void ordenarCursos(int* codigoCurso, double* creditosCurso, int cantCursos);
void emitirReporte(int anio, int ciclo, int* codigoAlumno, char** nombreAlumno, int* cantCursosAlumno,
                   double* numCreditosAlumno, char* escalaAlumno, double* montoPagado,int cantAlumnos);
void emitirEncabezado(ofstream& reporte, int anio, int ciclo);
void separadorCaracter(ofstream& reporte, char separador);
void ordenarPorEscalaYNombre(int* codigoAlumno, char** nombreAlumno, int* cantCursosAlumno,
                             double* numCreditosAlumno, char* escalaAlumno, double* montoPagado,int cantAlumnos);

#endif //LAB7_2023_2_FUNCIONESADICIONALES_H