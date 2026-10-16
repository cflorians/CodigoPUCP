#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Funciones.h"

void cargarDatos(const char* nombArch, int*& codigos,char**& nombres) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    int numDatos = 0;
    int buffCod[30];
    char* buffNombre[30];

    while (true) {
        arch >> buffCod[numDatos];
        arch.get();

        if (arch.eof()) break;

        buffNombre[numDatos] = leerNombre(arch);

        numDatos++;
    }

    codigos = new int[numDatos + 1]{};
    nombres = new char*[numDatos + 1]{};
    for (int i = 0; i < numDatos; i++) {
        codigos[i] = buffCod[i];
        nombres[i] = buffNombre[i];
    }
}

char* leerNombre(ifstream& arch) {
    char auxNombre[60], *nombre;
    arch.getline(auxNombre, 60, '\n');
    nombre = new char[strlen(auxNombre)+1];
    strcpy(nombre, auxNombre);
    return nombre;
}

void cargarDatos(const char* nombArch,int* codigos,char***& cursos) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }
    int codigo, posicion;
    int numDat = 0;
    while (codigos[numDat]) numDat++;

    int numCursosAlumno[numDat+1]{};

    cursos = new char**[numDat + 1]{};
    for (int i = 0; i < numDat; i++) {
        cursos[i] = new char*[80]{};
    }

    char curso[7];

    while (true) {
        arch >> codigo;
        arch.get();

        if (arch.eof()) break;

        arch.getline(curso, 7, '\n');

        posicion = buscaAlumno(codigos, codigo);
        if (posicion != -1) {
            colocarCursoEnAlumno(cursos[posicion], curso, numCursosAlumno[posicion]);
        }
        else {
            cout << "Alumno " << codigo << " no encontrado" << endl;
        }
    }
    for (int i=0; i < numDat; i++) {
        asignarEspaciosExactos(cursos[i], numCursosAlumno[i]);
    }
}

void asignarEspaciosExactos(char**& cursos, int cant) {
    char** aux;
    if (cant != 0) {
        aux = new char*[cant + 1]{};
        for (int i = 0; i < cant; i++) {
            aux[i] = cursos[i];
        }
        delete [] cursos;
        cursos = aux;
    }
    else {
        delete cursos;
        cursos = nullptr;
    }
}

int buscaAlumno(int* codigos,int codigo) {
    for (int i = 0; codigos[i] ; i++) {
        if (codigos[i] == codigo) return i;
    }
    return -1;
}

void colocarCursoEnAlumno(char**& cursos,char* curso, int& cant) {
    cursos[cant] = new char[strlen(curso)+1];
    strcpy(cursos[cant], curso);
    cant++;
}

void imprimirDatos(const char* nombArch,int* codigos, char** nombres,char*** cursos) {
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    for (int i = 0; codigos[i]; i++) {
        arch << codigos[i] << ' ' << nombres[i] << endl;
        if (cursos[i] != nullptr) {
            for (int j = 0; cursos[i][j]; j++) {
                arch << cursos[i][j] << endl;
            }
        }
    }
}