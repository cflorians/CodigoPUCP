#include <iostream>
using namespace std;
#include "Bibliotecas/Funciones.h"

int main(int argc, char** argv) {
    
    void *alumnos;
    cargarAlumnos(alumnos, "Archivos/Alumnos.csv");
    imprimirAlumnos(alumnos, "Reportes/PruebaAlumnos.txt");

    cargarCursos(alumnos, "Archivos/CursosNotas.csv");
    imprimirAlumnos(alumnos, "Reportes/PruebaAlumnosCursos.txt");

    calcularPromedios(alumnos);
    imprimirAlumnos(alumnos, "Reportes/PruebaPromedios.txt");

    ordenarPromedios(alumnos);
    imprimirAlumnos(alumnos, "Reportes/PruebaOrdenado.txt");

    return 0;
}
