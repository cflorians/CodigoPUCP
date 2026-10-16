#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "FuncionesAuxiliares.h"

void abrirArchivo(ifstream& arch, const char* nombre) {
    arch.open(nombre, ios::in);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << nombre << endl;
        exit(1);
    }
}
void mostrarArreglo(int* arr, int cant) {
    for (int i = 0; i < cant; i++) {
        cout << arr[i] << " ";
    }
}

// INSERSION ORDENADA
int buscarPos(int* arr, int cant, int num) {
    int pos;
    for  (pos = 0; pos < cant; pos++) {
        if (arr[pos] > num) {
            return pos;
        }
    }
    return cant;
}
void crearEspacio(int* arr, int& cant, int pos) {
    for (int i=cant; i>pos; i--) {
        arr[i] = arr[i-1];
    }
    cant++;
}

// BUSQUEDA BINARIA
int busquedaBinaria(int* arr, int cant, int objetivo) {
    int mitad, inicio, fin;
    inicio = 0;
    fin = cant - 1;
    for (int i = 0; i < cant; i++) {
        //hallamos la mitad del arreglo
        mitad = (inicio + fin) / 2;
        if (arr[mitad] == objetivo) {
            return mitad;
        }
        else if (arr[mitad] < objetivo) {
            inicio = mitad+1;
        }
        else if (arr[mitad] > objetivo) {
            fin = mitad-1;
        }
    }
    return -1;
}

// ELIMINACION
void eliminarPorIndice(int* arr, int& cant, int pos) {
    for (int i=pos; i<cant; i++) {
        arr[i] = arr[i+1];
    }
    cant--;
}