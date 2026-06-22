#include <fstream>
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;
#include "Funciones.h"

#define INCREMENTO 5;

enum reg{CODIGO, NOMBRE, CURSOS, PROM};

void cargarAlumnos(void*& alum, const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    void **alumnos = nullptr;
    void *reg = nullptr;
    int capacidad = 0;
    int nd = 0; // número de datos;

    // 20196975,Hijar Pairazaman Jenny Delicia
    while (true) {
        reg = leerRegistro(arch);
        if (arch.eof()) break;
        if (nd == capacidad) incrementarEspacios(alumnos, nd, capacidad);
        alumnos[nd-1] = reg;
        nd++;
    }

    alum = alumnos;
}

void imprimirAlumnos(void*& alum, const char* nombArch) {
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    arch.precision(2);
    arch << fixed;
    void** alumnos;
    alumnos = (void**)alum;
    for (int i=0; alumnos[i]; i++) {
        imprimirAlumno(alumnos[i], arch);
    }
}

void imprimirAlumno(void* alu,ofstream& arch) {
    //ALUMNO
    // PASO 1: Convertir void* a void**
    void **alumno = (void**)alu;

    // PASO 2: Extraer cada acmpo con su tipo especifico
    int* codigo = (int*)alumno[CODIGO];
    char* nombre = (char*)alumno[NOMBRE];

    // PASO 3: Usar los valores
    arch << left << setw(10) << *codigo << nombre << endl;

    // PASO 4: verificar si hay datos adicionales
    // aca curso
    if (alumno[CURSOS] != nullptr) imprimirCursos(alumno[CURSOS], arch);
    // aca prom
    if (alumno[PROM] != nullptr) {
        double* promedio = (double*)alumno[PROM];
        arch << "   Promedio: " << *promedio << endl;
    }
}

void incrementarEspacios(void**& alumnos, int& nd, int& capacidad) {
    void** aux;
    capacidad += INCREMENTO;

    if (alumnos == nullptr) {
        alumnos = new void*[capacidad]{}; // importante las llaves
        nd = 1;
    }
    else {
        aux = new void*[capacidad]{}; // importantes las llaves
        for (int i = 0; i < nd; i++) aux[i] = alumnos[i];
        delete alumnos;
        alumnos = aux;
    }
}

void* leerRegistro(ifstream& arch) {
    void** reg = nullptr;
    int cod;
    int* codigo;
    char* nombre;

    arch >> cod;
    if (arch.eof()) return nullptr;
    arch.get();
    nombre = leerCadena(arch);
    codigo = new int;
    *codigo = cod;

    reg = new void*[4] {};
    reg[CODIGO] = codigo;
    reg[NOMBRE] = nombre;
    reg[CURSOS] = nullptr;
    reg[PROM] = nullptr;

    return reg;
}

char* leerCadena(ifstream& arch) {
    char nomb[100];
    char* nombre;
    arch.getline(nomb,100,'\n');
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre,nomb);
    return nombre;
}
char* leerCadena(ifstream& arch, char limit) {
    char nomb[100];
    char* nombre;
    arch.getline(nomb,100,limit);
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre,nomb);
    return nombre;
}

void cargarCursos(void* alum, const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    void** alumnos = (void**)alum;
    int numDat = 0, cod, pos;
    while (alumnos[numDat]) numDat++; // aca obtenemos la candidad de alumnos que tenemos
    int nd[numDat+1]{}, cap[numDat+1]{};

    while (true) {
        arch >> cod;
        if (arch.eof()) break;
        arch.get();

        pos = buscarAlumno(cod, alumnos);
        if (pos != -1 ) {
            colocarCurso(arch, alumnos[pos], nd[pos], cap[pos]);
        }
        else while (arch.get() != '\n');
    }
}

int buscarAlumno(int cod,void** alumnos) {
    for (int i=0; alumnos[i]; i++) {
        if (comparar(alumnos[i], cod)) return i;
    }
    return -1;
}

bool comparar(void* alum,int codigo) {
    void** alumno = (void**)alum;
    int* cod = (int*)alumno[CODIGO];
    return *cod == codigo;
}

void colocarCurso(ifstream& arch,void*& alum,int& nd, int& cap) {
    void** alumno = (void**)alum;
    void* curso = leerCurso(arch);

    if (nd == cap) {
        incrementarEspacios(alumno[CURSOS], nd, cap);
    }
    agregarCurso(curso, alumno[CURSOS], nd);
    nd++;
}

void incrementarEspacios(void*& cur,int& nd,int& cap) {
    void** cursos = (void**)cur;
    void** aux;
    cap += INCREMENTO;
    if (cursos == nullptr) {
        cursos = new void*[cap]{};
        nd++;
    }
    else {
        aux = new void*[cap]{};
        for (int i = 0; i < nd; i++) aux[i] = cursos[i];
        delete cursos;
        cursos = aux;
    }
    cur = cursos;
}

void* leerCurso(ifstream& arch) {
    char* codigo;
    int* nota = new int;
    codigo = leerCadena(arch, ',');
    arch >> *nota;

    void** reg = new void*[2]{};
    reg[0] = codigo;
    reg[1] = nota;

    return reg;
}

void agregarCurso(void* curso, void*& alumCur,int nd) {
    void** alumnoCursos = (void**)alumCur;
    alumnoCursos[nd-1] = curso;
    // alumCur = alumnoCursos;
}

void imprimirCursos(void* alum,ofstream& arch) {
    void** curso = (void**)alum;
    for (int i=0; curso[i]; i++) {
        imprimeCurso(curso[i], arch);
    }
}

void imprimeCurso(void* cur,ofstream& arch) {
    void** curso = (void**)cur;
    char* codigo = (char*)curso[0];
    int* nota = (int*)curso[1];
    arch << "   " << left << setw(10) << codigo
         << right << setw(5) << *nota << endl;
}

void calcularPromedios(void* alum) {
    void** alumnos = (void**)alum;
    for (int i =0; alumnos[i]; i++) {
        promedioDelAlumno(alumnos[i]);
    }
}

void promedioDelAlumno(void* alum) {
    void** alumno = (void**)alum;
    if (alumno[CURSOS]) {
        alumno[PROM] = promedio(alumno[CURSOS]);
    }
}

double* promedio(void* alum) {
    void** cursos = (void**)alum;
    int suma=0, numDat = 0;
    double* prom = new double;
    for (int i=0; cursos[i]; i++) {
        suma += obtenerNota(cursos[i]);
        numDat++;
    }
    *prom = (double)suma/numDat;
    return prom;
}

int obtenerNota(void* cursos) {
    void** curso = (void**)cursos;
    int* ptrNota = (int*)curso[1];
    return *ptrNota;
}

void ordenarPromedios(void* alum) {
    // Contar los elementos (el array termina con nullptr)
    void** alumnos = (void**)alum;
    int numDat = 0;
    while (alumnos[numDat]) numDat++;

    // Llamar al QuickSort recursivo
    qsort(alumnos, 0, numDat-1);
}

void qsort(void** alumnos, int izq, int der) {
    int limite;
    if (izq >= der) return;
    cambiar(alumnos[izq], alumnos[(izq+der)/2]);
    limite = izq;
    for (int i=izq+1; i<=der; i++) {
        if (estamosEnDesorden(alumnos[i], alumnos[izq])) {
            cambiar(alumnos[++limite], alumnos[i]);
        }
    }
    cambiar(alumnos[izq], alumnos[limite]);
    qsort(alumnos, izq, limite-1);
    qsort(alumnos, limite+1, der);
}

bool estamosEnDesorden(void* alumI, void* alumJ) {
    // quiero ordenar por el nombre del alumno
    void** alumnoI = (void**)alumI;
    void** alumnoJ = (void**)alumJ;
    // char* nombreI = (char*)alumnoI[NOMBRE];
    // char* nombreJ = (char*)alumnoJ[NOMBRE];
    // return strcmp(nombreI, nombreJ) < 0;
    double* promI = (double*)alumnoI[PROM];
    double* promJ = (double*)alumnoJ[PROM];
    return *promI < *promJ;
}

void cambiar(void*& alumI, void*& alumJ) {
    void* aux;
    aux = alumI;
    alumI = alumJ;
    alumJ = aux;
    // solo intercambiamos los punteros, no los datos
}