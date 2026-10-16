#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Biblioteca/FuncionesAdicionales.h"
#include "Biblioteca/Nodo.h"

int main(int argc, char *argv[]) {

    struct NodoCurso* listaCursos = nullptr;
    struct NodoEscala* listaEscalas = nullptr;
    struct NodoAlumno* listaAlumno = nullptr;
    int ciclo, anho;

    leerCursos(listaCursos);
    leerEscalas(listaEscalas);
    leerAlumnos(listaAlumno);
    emitirReporte("ArchivosDeReporte/ReporteIncialAlumnos.txt", listaAlumno, true);
    cin >> anho >> ciclo;
    leerMatricula(anho, ciclo, listaAlumno,listaEscalas,listaCursos);
    eliminarAlumnos(anho, ciclo, listaAlumno);
    emitirReporte("ArchivosDeReporte/ReporteFinalAlumnos.txt", listaAlumno, false);

    return 0;
}