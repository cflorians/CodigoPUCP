#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Bibliotecas/Estructuras.h"
#include "Bibliotecas/FuncionesAdicionales.h"

int main(int argc, char *argv[]) {

    struct Alumno arrAlumnos[100]{};
    int cantAlumnos;

    leerDatosCalificaciones(arrAlumnos, cantAlumnos);
    leerDatosAlumnos(arrAlumnos, cantAlumnos);
    leerDatosFacultades(arrAlumnos, cantAlumnos);

    emitirReporte(arrAlumnos, cantAlumnos);

    return 0;
}