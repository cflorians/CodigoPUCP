#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Funciones.h"
#include "Tabla.h"

#define INCREMENTOCOLUM 2
#define INCREMENTOFIL 5

void inicializar_tabla(struct Tabla& tabla) {
    tabla.filas = nullptr;
    tabla.columnas = nullptr;
    tabla.cantidad_filas = 0;
    tabla.cantidad_columnas = 0;
    tabla.capacidad_filas = 0;
    tabla.cantidad_columnas = 0;
}

void insertar_columna(struct Tabla& tabla) {
    if (tabla.cantidad_columnas == tabla.capacidad_columnas) {
        incrementar_columnas(tabla.columnas, tabla.cantidad_columnas, tabla.capacidad_columnas);
    }
}

void incrementar_columnas(void*& colum, int& numColumnas, int& capColumnas) {
    void** aux = nullptr;
    void** columnas = (void**)colum;
    capColumnas += INCREMENTOCOLUM;
    if (columnas == nullptr) {
        columnas = new void*[capColumnas]{};
        numColumnas = 1;
    }
    else {
        aux = new void*[capColumnas]{};
        for (int i = 0; i < numColumnas; i++) aux[i] = columnas[i];
        delete [] columnas;
        columnas = aux;
    }
    colum = columnas;
}