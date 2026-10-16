#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "Nodo.h"
using namespace std;
#include "Curso.h"
#include "Escala.h"
#include "Alumno.h"
#include "FuncionesAdicionales.h"

void leerCursos(struct NodoCurso*& lista) {
    ifstream arch("ArchivosDeDatos/Cursos.csv", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir cursos.csv" << endl;
        exit(1);
    }

    struct Curso curso;
    char nombre[70];
    // 109263,Algoritmia,4.25
    while (true) {
        arch >> curso.codCurso;
        arch.ignore();
        arch.getline(nombre, 70,',');
        curso.nombre = insertarChar(nombre);
        arch >> curso.creditos;

        if (arch.eof()) break;

        insertarEnLista(lista, curso);
    }

    // struct NodoCurso* ptr = lista;
    // while (ptr) {
    //     cout << ptr->dato.nombre << endl;
    //     ptr = ptr->next;
    // }
}

char* insertarChar(char* cadena) {
    char* nueva = new char [strlen(cadena)+1];
    strcpy(nueva, cadena);
    return nueva;
}

void insertarEnLista(struct NodoCurso*& lista, struct Curso nodo) {
    struct NodoCurso* ptr = new struct NodoCurso;
    ptr->dato = nodo;
    ptr->next = lista;
    lista = ptr;
}

void leerEscalas(struct NodoEscala*& lista) {
    ifstream arch("ArchivosDeDatos/Escalas.csv", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir escalas.csv" << endl;
        exit(1);
    }

    struct Escala escala;
    // 2021-2,C,288.65
    char c;
    while (true) {
        arch >> escala.anho >> c >> escala.ciclo;
        arch.ignore();
        arch >> escala.escala;
        arch.ignore();
        arch >> escala.valorCred;

        if (arch.eof()) break;

        insertarEnLista(lista, escala);
    }

    // struct NodoEscala* ptr = lista;
    // while (ptr) {
    //     cout << ptr->dato.anho << '-' << ptr->dato.ciclo << endl;
    //     ptr = ptr->next;
    // }
}

void insertarEnLista(struct NodoEscala*& lista, struct Escala nodo) {
    struct NodoEscala* ptr = new struct NodoEscala;
    ptr->dato = nodo;
    ptr->next = lista;
    lista = ptr;
}

void leerAlumnos(struct NodoAlumno*& lista) {
    ifstream arch("ArchivosDeDatos/Alumnos.csv", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir alumnos.csv" << endl;
        exit(1);
    }

    struct Alumno alumno;
    // 20227341,Diaz Antezano Magali Silvana,D
    char nombre[50];
    while (true) {
        arch >> alumno.codAlumno;
        arch.ignore();
        arch.getline(nombre, 50, ',');
        alumno.nombre = insertarChar(nombre);
        arch >> alumno.escAlumno.escala;

        alumno.escAlumno.anho = 0;
        alumno.escAlumno.ciclo = 0;
        alumno.escAlumno.valorCred = 0;
        alumno.cantidadCursos = 0;
        alumno.totalCreditos = 0;
        alumno.totalPago = 0;

        if (arch.eof()) break;

        insertarEnListaOrdenado(lista, alumno);
    }

    // struct NodoAlumno* ptr = lista;
    // while (ptr) {
    //     cout << ptr->dato.escAlumno.escala << " " << ptr->dato.nombre << endl;
    //     ptr = ptr->next;
    // }
}

void insertarEnListaOrdenado(struct NodoAlumno*& lista, struct Alumno nodo) {
    struct NodoAlumno* ptr = lista;
    struct NodoAlumno* ant = nullptr;
    struct NodoAlumno* nuevo = new struct NodoAlumno;

    nuevo->dato = nodo;

    while (ptr) {
        if (nuevo->dato.escAlumno.escala < ptr->dato.escAlumno.escala) break;
        else if (nuevo->dato.escAlumno.escala == ptr->dato.escAlumno.escala and strcmp(nuevo->dato.nombre, ptr->dato.nombre) < 0) break;

        ant = ptr;
        ptr = ptr->next;
    }

    if (ant == nullptr) {
        nuevo->next = lista;
        lista = nuevo;
    }
    else {
        nuevo->next = ptr;
        ant->next = nuevo;
    }
}

void emitirReporte(const char* nombArch, const struct NodoAlumno* lista, bool preeliminar) {
    ofstream reporte(nombArch, ios::out);

    double cantidadAlumnos=0;
    double totalPagadoTodos=0;

    reporte << setw(65) << "INSTITUICION EDUCATIVA TP" << endl;
    if (preeliminar) {
        reporte << setw(68) << "DETALLE PREELIMINAR DE ALUMNOS" << endl;
    }
    else {
        reporte << setw(10) << "DETALLE DE PAGOS REALIZADO POR CICLO" << endl;
        reporte << setw(10) << "CICLO: 2023-1" << endl;
    }
    separador(reporte, '=');
    while (lista) {
        reporte << "ALUMNO: " << lista->dato.codAlumno << " - " << lista->dato.nombre << setw(55-strlen(lista->dato.nombre))
                << "ESCALA: " << lista->dato.escAlumno.escala << setw(25) << "Valor Credito: " <<lista->dato.escAlumno.valorCred << endl;
        if (not preeliminar) {
            double totalCreditos = 0;
            double totalMontoPagado = 0;
            separador(reporte, '-');
            reporte << "CURSO MATRICULADO                    CREDITOS          MONTO PAGADO" << endl;
            for (int i=0; i < lista->dato.cantidadCursos; i++) {
                reporte << lista->dato.cursos[i].codCurso << " " << lista->dato.cursos[i].nombre << setw(10)
                        << lista->dato.cursos[i].creditos << setw(15) << lista->dato.cursos[i].creditos * lista->dato.escAlumno.valorCred << endl;
                totalCreditos += lista->dato.cursos[i].creditos;
                totalMontoPagado += lista->dato.cursos[i].creditos * lista->dato.escAlumno.valorCred;
            }
            separador(reporte, '-');
            reporte << "TOTAL CREDITOS: " << totalCreditos << "     TOTAL MONTO PAGADO: " << totalMontoPagado << endl;
            cantidadAlumnos++;
            totalPagadoTodos += totalMontoPagado;
        }
        separador(reporte, '=');

        lista = lista->next;
    }
    reporte << "RESUMEN:" << endl;
    reporte << "CANTIDAD TOTAL DE ALUMNOS: " << cantidadAlumnos << setw(30) << "MONTO TOTAL PAGADO: " << totalPagadoTodos << endl;
}

void separador(ofstream& arch, char separador) {
    arch << setfill(separador);
    arch << setw(107) << separador << endl;
    arch << setfill(' ');
}

void leerMatricula(int anhoLeido, int cicloLeido, struct NodoAlumno*& lista, struct NodoEscala* listaEscalas, struct NodoCurso* listaCursos) {
    ifstream arch("ArchivosDeDatos/Matricula.txt", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir Matricula.txt" << endl;
        exit(1);
    }

    // 2023-2    20231938    481203    375219    231286    231292
    int anio, ciclo;
    char c;
    int codigo, curso;
    struct NodoAlumno* ptrAlumno;
    struct NodoEscala* ptrEscala;
    struct NodoCurso* ptrCurso;
    while (true) {
        arch >> anio >> c >> ciclo >> codigo;

        if (anio == anhoLeido and ciclo == cicloLeido) {
            while (arch.peek() != '\n') {
                arch >> curso;

                ptrAlumno = buscarAlumno(codigo,lista);
                if (ptrAlumno != nullptr) {
                    ptrEscala = buscarEscala(ptrAlumno->dato.escAlumno.escala,listaEscalas);
                    ptrCurso = buscarCurso(curso,listaCursos);
                    if (ptrEscala!=nullptr and ptrCurso!=nullptr) {
                        ptrAlumno->dato.escAlumno.anho = anio;
                        ptrAlumno->dato.escAlumno.ciclo = ciclo;
                        ptrAlumno->dato.escAlumno.valorCred = ptrEscala->dato.valorCred;
                        ptrAlumno->dato.cursos[ptrAlumno->dato.cantidadCursos].codCurso = curso;
                        ptrAlumno->dato.cursos[ptrAlumno->dato.cantidadCursos].nombre = insertarChar(ptrCurso->dato.nombre);
                        ptrAlumno->dato.cursos[ptrAlumno->dato.cantidadCursos].creditos = ptrCurso->dato.creditos;
                        ptrAlumno->dato.totalCreditos+=ptrCurso->dato.creditos;
                        ptrAlumno->dato.totalPago += ptrCurso->dato.creditos*ptrEscala->dato.valorCred;
                        ptrAlumno->dato.cantidadCursos++;
                    }
                }
            }
        }
        else {
            arch.ignore(1000, '\n');
        }

        if (arch.eof()) break;
    }
}

struct NodoAlumno* buscarAlumno(int codigo, struct NodoAlumno* lista) {
    struct NodoAlumno* ptr = lista;

    while (ptr) {
        if (ptr->dato.codAlumno == codigo) return ptr;
        ptr = ptr->next;
    }
    return nullptr;
}

struct NodoEscala* buscarEscala(char escala, struct NodoEscala* lista) {
    struct NodoEscala* ptr = lista;

    while (ptr) {
        if (ptr->dato.escala == escala) return ptr;
        ptr = ptr->next;
    }
    return nullptr;
}

struct NodoCurso* buscarCurso(int codigo, struct NodoCurso* lista) {
    struct NodoCurso* ptr = lista;

    while (ptr) {
        if (ptr->dato.codCurso == codigo) return ptr;
        ptr = ptr->next;
    }
    return nullptr;
}

void eliminarAlumnos(int anio, int ciclo, struct NodoAlumno*& lista) {
    struct NodoAlumno* ptr = lista;
    struct NodoAlumno* ant = nullptr;
    struct NodoAlumno* eliminado;

    while (ptr) {
        if (lista->dato.escAlumno.anho != anio or lista->dato.escAlumno.ciclo != ciclo) {
            if (ant == nullptr) {
                eliminado = ptr;
                ptr = ptr->next;
                eliminado->next = nullptr;
                lista = ptr;
            }
            else {
                eliminado = ptr;
                ant->next = ptr->next;
                ptr = ptr->next;
                eliminado->next = nullptr;
            }
        }
        else {
            ant = ptr;
            ptr = ptr->next;
        }
    }
}