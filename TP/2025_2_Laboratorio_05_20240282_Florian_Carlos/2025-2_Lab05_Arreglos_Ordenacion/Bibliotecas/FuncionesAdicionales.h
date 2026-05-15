//
// Created by carlo on 6/10/2025.
//

#ifndef INC_2025_2_LAB05_ARREGLOS_ORDENACION_FUNCIONESADICIONALES_H
#define INC_2025_2_LAB05_ARREGLOS_ORDENACION_FUNCIONESADICIONALES_H

void cargarCanales(int* arrCodigo,char* arrLetraCod, double* arrRating, int& cantDatos);
void cargarEtiquetas(int* arrEtiquetas, int* arrDuracionEtiquetas,int& cantEtiquetas);
void cargarEtiquetasEnCanales(int* arrCanalEtiqueta, char* arrLetCanalEtiqueta, int* arrEtiquetaEnCanal, int& cantStreams);
void ordenarEtiquetas(int* arrEtiquetas, int* arrDuracionEtiquetas,int cantEtiquetas);
void emitirReporteSimple(int* arrCodigo,char* arrLetraCod, double* arrRating, int& cantDatos,
                        int* arrEtiquetas, int* arrDuracionEtiquetas,int& cantEtiquetas);
int buscarCanal(int* arrCodigo, char* arrLetCod, int cantCanales, char letCod, int codigo);
void determinarReproducciones(int* arrReproducciones, int* arrCanalEtiqueta, char* arrLetCanalEtiqueta,
                                int* arrEtiquetaEnCanal, int* tiempoReproducciones,
                                int* arrEtiquetas, int* arrDuracionEtiquetas,int cantEtiquetas,
                                int* arrCodigo,char* arrLetraCod, int cantDatos);
int buscarCanal(int* arrCodigo, char* arrLetCod, int cantCanales, char letCod, int codigo, int pos);

#endif //INC_2025_2_LAB05_ARREGLOS_ORDENACION_FUNCIONESADICIONALES_H