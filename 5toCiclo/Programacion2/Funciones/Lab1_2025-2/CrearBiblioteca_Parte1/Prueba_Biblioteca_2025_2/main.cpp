#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Bibliotecas/Cursos.h"

#include "Bibliotecas/Funciones.h"

int main(int argc, char** argv) {

    // operadores >>
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

    struct Alumnos alumno{};
    alumnosss >> alumno;
    cout << alumno.codigo << endl;

    // operador >
    cout << "Corresponde codigo alumno: " << (alumno > 20240282) << endl;

    cout << "Corresponde codigo curso: " << (curso > "INF262") << endl;

    // operador <=
    struct Alumnos arrAlumno[3] {
        {20240282, "CARLOS"},
        {0, ""}
    };
    struct Alumnos alumnoBuscado;
    alumnoBuscado.codigo = 20240282;
    cout <<  "Posicion del alumno buscado: " << (arrAlumno <= alumnoBuscado)+1 << endl;

    // operador >=
    struct Cursos arrCursos[3]{};
    arrCursos[0].codigo = new char[strlen("INF101") + 1];
    strcpy(arrCursos[0].codigo, "INF101");
    strcpy(arrCursos[0].nombre, "Programacion 1");

    // Simulamos que leímos el segundo curso ("INF263")
    arrCursos[1].codigo = new char[strlen("INF263") + 1];
    strcpy(arrCursos[1].codigo, "INF263");
    strcpy(arrCursos[1].nombre, "Algoritmia");

    cout << "Posicion del curso buscado: " << (arrCursos >= curso)+1 << endl;

    // operador +=
    curso += alumno;

    // operador ++
    ++curso;

    // operador <<
    ofstream reporte("Reportes/reporte.txt", ios::out);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo alumnos.txt" << endl;
        exit(1);
    }

    reporte << curso;

    return 0;
}
