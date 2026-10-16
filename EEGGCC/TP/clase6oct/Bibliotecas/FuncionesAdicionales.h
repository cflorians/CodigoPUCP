//
// Created by carlo on 6/10/2025.
//

#ifndef CLASE6OCT_FUNCIONESADICIONALES_H
#define CLASE6OCT_FUNCIONESADICIONALES_H

void cargarArreglos(int* arrDni,int* arrFecha,double* arrDouble,int& cantDatos);
void imprimirReporteSimple(int* arrDni,int* arrFecha,double* arrDouble,int cantDatos);
void ordenarPorDni(int* arrDni,int* arrFecha,double* arrDouble,int cantDatos);
void cargarArreglosOrdenado(int* arrDni,int* arrFecha,double* arrDouble,int& cantDatos);
void eliminarDelArreglo(int* arrDni,int* arrFecha,double* arrDouble,int& cantDatos, int dniAborrar);

#endif //CLASE6OCT_FUNCIONESADICIONALES_H