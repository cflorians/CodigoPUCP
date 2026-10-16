//
// Created by carlo on 5/10/2025.
//

#ifndef LAB5_FUNCIONESADICIONALES_H
#define LAB5_FUNCIONESADICIONALES_H

void cargarDatos(int *arr, int &cantDatos);
void imprimirArreglo(int *arr, int cantDatos);
int buscarPosNumero(int numeroBuscado, int *arr, int cantDatos);
void hallarMinYMax(int &min, int &max, int *arr, int cantDatos);
void invertirOrden(int *arr, int cantDatos);
void ordenamientoBurbuja(int *arr, int cantDatos);
void ordenamientoPorIndices(int *arr, int cantDatos, int *indOrdenados);
void eliminarDuplicados(int *arr, int cantDatos, int &nuevoTam, int *arrSinDup);

#endif //LAB5_FUNCIONESADICIONALES_H