#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "Funciones.h"

#define INCREMENTO 5

void cargarDatos(const char* nombArch,int*& codigos,char**& nombres,char***& cursos) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    int capacidad = 0;
    int numDatos = 0;
    int codigo;
    codigos = nullptr;
    nombres = nullptr;
    cursos = nullptr;
    // 20196975,Hijar Pairazaman Jenny Delicia,INF239,FIS248,MEC270,INF245,MEC286
    while (arch >> codigo) {
        arch.get();

        if (numDatos == capacidad) {
            incrementarEspacios(codigos, nombres, cursos, numDatos, capacidad);
        }
        codigos[numDatos - 1] = codigo;
        nombres[numDatos - 1] = leeNombre(arch);
        cursos[numDatos - 1] = leeCursos(arch);

        numDatos++;
    }
}

void incrementarEspacios(int*& codigos, char**& nombres, char***& cursos, int& numDatos, int&capacidad) {
    int* auxCod;
    char** auxNombres, ***auxCursos;
    capacidad += INCREMENTO;

    if (codigos == nullptr) {
        codigos = new int[capacidad]{};
        nombres = new char*[capacidad]{};
        cursos = new char**[capacidad]{};

        numDatos = 1;
    }
    else {
        auxCod = new int[capacidad]{};
        auxNombres = new char*[capacidad]{};
        auxCursos = new char**[capacidad]{};

        for (int i=0; i < numDatos; i++) {
            auxCod[i] = codigos[i];
            auxNombres[i] = nombres[i];
            auxCursos[i] = cursos[i];
        }

        delete codigos;
        delete nombres;
        delete cursos;

        codigos = auxCod;
        nombres = auxNombres;
        cursos = auxCursos;
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
    char aux[60], *nombre;
    arch.getline(aux,60, ',');
    nombre = new char[strlen(aux)+1];
    strcpy(nombre,aux);
    return nombre;
}

char** leeCursos(ifstream& arch) {
    char **cursos, *curso;
    cursos = nullptr;
    int capacidad = 0;
    int numCursos = 0;

    while (true) {
        curso = leeCurso(arch);
        if (numCursos == capacidad) {
            incrementarEspacios(cursos, numCursos, capacidad);
        }
        cursos[numCursos - 1] = curso;
        numCursos++;
        if (arch.get() != ',') break;
    }

    return cursos;
}

void incrementarEspacios(char**& cursos,int& numCursos,int& capacidad) {
    char **auxCursos;
    capacidad += INCREMENTO;

    if (cursos == nullptr) {
        cursos = new char*[capacidad]{};
        numCursos = 1;
    }
    else {
        auxCursos = new char*[capacidad]{};
        for (int i=0; i < numCursos; i++) {
            auxCursos[i] = cursos[i];
        }
        delete cursos;
        cursos = auxCursos;
    }
}

char* leeCurso(ifstream& arch) {
    char* curso, aux[7];

    arch.get(aux, 7 ,',');

    curso = new char[7];
    for (int i=0; i < 7; i++) {
        curso[i] = aux[i];
    }

    return curso;
}