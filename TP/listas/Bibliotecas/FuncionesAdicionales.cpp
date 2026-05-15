#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <list>
using namespace std;

#include "FuncionesAdicionales.h"
#include "Estructuras.h"


void leerDatosOrdenado(struct Nodo*& lista) {
    ifstream arch("ArchivosDeDatos/datos.csv", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo de datos.csv" << endl;
        exit(1);
    }

    struct Datos leido;
    char nombre[20];
    while (arch >> leido.dni) {
        arch.ignore();
        arch.getline(nombre, 20, ',');
        leido.nombre = insertarChar(nombre);
        arch >> leido.sueldo;

        insertarOrdenado(lista, leido);
    }
}

void insertarOrdenado(struct Nodo*& lista,struct Datos datos) {
    struct Nodo* p = lista;
    struct Nodo* ant = nullptr;
    struct Nodo* nuevo = new struct Nodo;

    nuevo->datos = datos;

    while (p != nullptr) {
        if (datos.sueldo < p->datos.sueldo) break;
        ant = p;
        p = p->next;
    }

    if (ant == nullptr) {
        nuevo->next = lista;
        lista = nuevo;
    }
    else {
        nuevo->next = p;
        ant->next = nuevo;
    }
}

void mostrarLista(const struct Nodo* lista) {
    cout << "NOMBRE             DNI           SUELDO" << endl;
    while (lista) {
        cout << lista->datos.nombre << "  " << lista->datos.dni << "  " << lista->datos.sueldo << endl;
        lista = lista->next;
    }
}

char* insertarChar(char* cadena) {
    char* nuevo = new char[strlen(cadena) + 1];
    strcpy(nuevo, cadena);
    return nuevo;
}

void eliminarPorCondicion(struct Nodo*& lista) {
    struct Nodo* p = lista;
    struct Nodo* ant = nullptr;
    struct Nodo* eliminado;

    while (p != nullptr) {
        if (p->datos.sueldo > 2000) {
            eliminado = p;
            if (ant == nullptr) {
                lista = p->next;
                p = p->next;
            }
            else {
                ant->next = p->next;
                p = p->next;
            }
            delete[] eliminado->datos.nombre;
            delete eliminado;
        }
        else {
            ant = p;
            p = p->next;
        }
    }
}