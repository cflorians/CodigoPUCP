//
// Created by carlo on 10/13/2025.
//

#ifndef REPASODEARREGLOSPARCIAL_FUNCIONESADICIONALES_H
#define REPASODEARREGLOSPARCIAL_FUNCIONESADICIONALES_H

void abrirArchivos(ifstream& arch, const char* nombreArch);
void abrirArchivos(ofstream& arch, const char* nombreArch);
void cargarDatos(ifstream& arch, int* arrDatos, int& cantDatos);
void mostrarArreglo(ofstream& arch, int* arrDatos, int cantDatos);
void ordenarArreglo(int* arrDatos, int cantDatos);
void invertirArreglo(int* arrDatos, int cantDatos);
int buscarNumero(int numero, int* arrDatos, int cantDatos);
void cargarOrdenado(ifstream& arch, int* arrDatos, int& cantDatos);
int buscarPosicion(int num, int* arrDatos, int cantDatos);
void generarEspacio(int pos, int* arrDatos, int cantDatos);

#endif //REPASODEARREGLOSPARCIAL_FUNCIONESADICIONALES_H