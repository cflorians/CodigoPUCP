//
// Created by carlo on 10/24/2025.
//

#ifndef LAB6_PRACTICA_FUNCIONESAUXILIARES_H
#define LAB6_PRACTICA_FUNCIONESAUXILIARES_H

void abrirArchivo(ifstream& arch, const char* nombre);
void mostrarArreglo(int* arr, int cant);
int buscarPos(int* arr, int cant, int num);
void crearEspacio(int* arr, int& cant, int pos);

int busquedaBinaria(int* arr, int cant, int objetivo);

void eliminarPorIndice(int* arr, int& cant, int pos);

#endif //LAB6_PRACTICA_FUNCIONESAUXILIARES_H