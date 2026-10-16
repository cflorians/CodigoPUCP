#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "Funciones.h"

void cargarDatos(const char* nombArch,int*& codigos,char**& nombres,char***& cursos) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    int codigo;
    int numDatos = 0;
    int buffCodigo[50]{};
    char* buffNombre[50]{};
    char** buffCurso[50]{};

    while (arch >> codigo) {
        arch.get();
        buffCodigo[numDatos] = codigo;

        buffNombre[numDatos] = leeNombre(arch);

        buffCurso[numDatos] = leeCursos(arch);

        numDatos++;
    }
    codigos = new int[numDatos]{}; // ojo aca depende de la lectura, si no funciona probar con numDatos+1
    nombres = new char*[numDatos]{};
    cursos = new char**[numDatos]{};
    for (int i = 0; i < numDatos; i++) {
        codigos[i] = buffCodigo[i];
        nombres[i] = buffNombre[i];
        cursos[i] = buffCurso[i];
    }
}

void imprimirDatos(const char* nombArch,int*& codigos,char**& nombres,char***& cursos) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    for (int i = 0; codigos[i] ; i++) {
        arch << left << setw(10) << codigos[i] << nombres[i] << endl;
        imprimirCursos(arch, cursos[i]);
    }
}

void imprimirCursos(ofstream& arch,char** cursos) {
    for (int i=0; cursos[i] ; i++) {
        arch << setw(10) << cursos[i] << endl;
    }
    arch << endl;
}

char* leeNombre(ifstream& arch) {
    char* nombre, auxiliar[50]{};
    arch.getline(auxiliar, 50, ',');
    nombre = new char[strlen(auxiliar)+1];
    strcpy(nombre, auxiliar);
    return nombre;
}

char** leeCursos(ifstream& arch) {
    char** cursos, *buffCurso[60], *cur;
    int numCursos = 0;
    while (true) {
        cur = leeCurso(arch);
        buffCurso[numCursos] = cur;
        numCursos++;
        if (arch.get() !=',') break;
    }
    cursos = new char*[numCursos + 1]{};
    for (int i=0; i < numCursos; i++) {
        cursos[i] = buffCurso[i];
    }
    return cursos;
}

char* leeCurso(ifstream& arch) {
    char* curso = new char[7]{};
    arch.get(curso, 7);
    return curso;
}