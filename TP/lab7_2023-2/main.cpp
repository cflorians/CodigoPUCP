#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Bibliotecas/FuncionesAdicionales.h"
#define MAX_ALUMNOS 100
#define MAX_CURSOS 50
#define MAX_ESCALAS 30

int main(int argc, char *argv[]) {

    int anioReporte = 2023, cicloReporte = 1;
    int codigoAlumno[MAX_ALUMNOS]{}, cantAlumnos;
    char *nombreAlumno[MAX_ALUMNOS]{}, escalaAlumno[MAX_ALUMNOS]{};
    int codigoCurso[MAX_CURSOS]{}, cantCurso;
    double creditosCurso[MAX_CURSOS]{};
    int anioEscala[MAX_ESCALAS]{}, cicloEscala[MAX_ESCALAS]{}, cantEscalas;
    char escalaValor[MAX_ESCALAS]{};
    double costoCredito[MAX_ESCALAS]{};
    int cantCursosAlumno[MAX_ALUMNOS]{};
    double numCreditosAlumno[MAX_ALUMNOS]{}, montoPagado[MAX_ALUMNOS]{};

    cout << "Ingrese un año para emitir el reporte" << endl;
    cin >> anioReporte;
    cin.ignore();
    cin >> cicloReporte;

    leerDatosAlumnos(codigoAlumno, nombreAlumno, escalaAlumno, cantAlumnos);
    ordenarAlumnos(codigoAlumno, nombreAlumno, escalaAlumno, cantAlumnos);

    leerDatosCursos(codigoCurso, creditosCurso, cantCurso);
    ordenarCursos(codigoCurso, creditosCurso, cantCurso);

    leerDatosEscalas(anioEscala, cicloEscala, escalaValor, costoCredito, cantEscalas);

    procesarMatricula(anioReporte, cicloReporte, cantCursosAlumno, numCreditosAlumno, montoPagado,
                      codigoCurso, creditosCurso, cantCurso, codigoAlumno,
                      escalaAlumno, cantAlumnos, anioEscala, cicloEscala, escalaValor,
                      costoCredito, cantEscalas);

    ordenarPorEscalaYNombre(codigoAlumno, nombreAlumno, cantCursosAlumno,
                            numCreditosAlumno, escalaAlumno, montoPagado, cantAlumnos);
    emitirReporte(anioReporte, cicloReporte, codigoAlumno, nombreAlumno, cantCursosAlumno,
                   numCreditosAlumno, escalaAlumno, montoPagado, cantAlumnos);

    return 0;
}