#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "Bibliotecas/Funciones.h"

int main(int argc, char** argv) {
    int* codigos; // codigos de los alumnos
    char** nombres; // nombres de los alumnos
    char*** cursos; // cursos de cada alumno

    cargarDatos("Archivos/Alumnos-Cursos.csv", codigos, nombres, cursos);
    imprimirDatos("Reportes/reporte.txt", codigos, nombres, cursos);
    
    
    return 0;
}
