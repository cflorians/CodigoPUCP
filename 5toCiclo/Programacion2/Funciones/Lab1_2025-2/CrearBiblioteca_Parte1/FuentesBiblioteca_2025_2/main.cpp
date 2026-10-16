#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "Bibliotecas/Cursos.h"

#include "Bibliotecas/Funciones.h"

int main(int argc, char** argv) {

    ifstream arch("Archivos/cursos.txt", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo cursos.txt" << endl;
        exit(1);
    }

    struct Cursos curso{};
    arch >> curso;
    cout << curso.codigo << endl;

    ifstream alumnosss("Archivos/alumnos.txt", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo alumnos.txt" << endl;
        exit(1);
    }

    struct Alumnos alumno;
    alumnosss >> alumno;
    cout << alumno.nombre << endl;

    ofstream reporte("Reportes/reporte.txt", ios::out);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo alumnos.txt" << endl;
        exit(1);
    }

    curso += alumno;

    ++curso;

    reporte << curso;

    return 0;
}
