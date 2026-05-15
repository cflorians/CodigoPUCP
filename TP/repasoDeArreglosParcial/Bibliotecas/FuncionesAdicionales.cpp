//
// Created by carlo on 10/13/2025.
//
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "FuncionesAdicionales.h"

void abrirArchivos(ifstream& arch, const char* nombreArch) {
    arch.open(nombreArch, ios::in);
    if (!arch.is_open()) {
        cout << "Error al abrir " << nombreArch << endl;
        exit(1);
    }
}
void abrirArchivos(ofstream& arch, const char* nombreArch) {
    arch.open(nombreArch, ios::out);
    if (!arch.is_open()) {
        cout << "Error al abrir " << nombreArch << endl;
        exit(1);
    }
}

//cargar datos
//mostrar arreglo
//ordenar datos
//invertir arreglo
//buscar datos
//cargar ordenado

void cargarDatos(ifstream& arch, int* arrDatos, int& cantDatos) {
    cantDatos = 0;
    while (true) {
        arch >> arrDatos[cantDatos];
        cantDatos++;
        if (arch.eof()) break;
    }
}
void mostrarArreglo(ofstream& arch, int* arrDatos, int cantDatos) {
    int i=0;
    for (i=0; i < cantDatos; i++) {
        arch << arrDatos[i] << " ";
    }
}
void ordenarArreglo(int* arrDatos, int cantDatos) {
    int i=0, j=0, temp;
    for (i=0; i < cantDatos-1; i++) {
        for (j=i+1; j < cantDatos; j++) {
            if (arrDatos[i] > arrDatos[j]) {
                temp = arrDatos[i];
                arrDatos[i] = arrDatos[j];
                arrDatos[j] = temp;
            }
        }
    }
}
void invertirArreglo(int* arrDatos, int cantDatos) {
    int i=0, temp;
    for (i=0; i < cantDatos/2; i++) {
        temp = arrDatos[i];
        arrDatos[i] = arrDatos[cantDatos-1-i];
        arrDatos[cantDatos-1-i] = temp;
    }
}
int buscarNumero(int numero, int* arrDatos, int cantDatos) {
    int pos=0;
    for (pos=0; pos < cantDatos; pos++) {
        if (arrDatos[pos] == numero) {
            return pos;
        }
    }
    return -1;
}

void cargarOrdenado(ifstream& arch, int* arrDatos, int& cantDatos) {
    int num, pos;
    cantDatos = 0;
    arch.clear();
    arch.seekg(0, ios::beg);
    while (arch >> num) {
        pos = buscarPosicion(num, arrDatos, cantDatos);
        generarEspacio(pos, arrDatos, cantDatos);
        arrDatos[pos] = num;
        cantDatos++;
    }
}
int buscarPosicion(int num, int* arrDatos, int cantDatos) {
    int pos=0;
    for (pos=0; pos < cantDatos; pos++) {
        if (num < arrDatos[pos]) {
            return pos;
        }
    }
    return pos;
}
void generarEspacio(int pos, int* arrDatos, int cantDatos) {
    int i;
    for (i=cantDatos; i > pos; i--) {
        arrDatos[i] = arrDatos[i-1];
    }
}