//
// Created by carlo on 10/10/2025.
//

#ifndef REPASOEXAMENPARCIAL_FUNCIONESADICIONALES_H
#define REPASOEXAMENPARCIAL_FUNCIONESADICIONALES_H

void abrirArchivo(ifstream& arch, const char* nombreArch);
void abrirArchivo(ofstream& arch, const char* nombreArch);
void cargarDatosCanales(ifstream& canales, int* codigo, char* letCodigo, double* rating, int& cantCanales);
void cargarDatosEtiquetas(ifstream& etiquetas,int* codEtiquetas, int* duracion, int& cantEtiquetas);
void saltarTexto(ifstream& arch);
void cargarDatosEtiquetasEnCanales(istream& etiquetasEnCanales, int* codCanal, char* letCanal, int* etiqueta, int& cantStreams);
void emitirReporteSimple(ofstream& reporte,  int* codigo, char* letCodigo, double* rating, int& cantCanales,
                                        int* codEtiquetas, int* duracion, int& cantEtiquetas,
                                        int* codCanal, char* letCanal, int* etiqueta, int& cantStreams);
void ordenarPorDuracion(int* etiquetas, int* duracion, int cantEtiquetas);
int buscarReproducciones(int etiquetaActual, int* arrEtiquetas,int* arrDuracionEtiquetas, int cantEtiquetas);
void determinarCantReproducciones(ifstream& arch,int* arrEtiquetaEnCanal,char* arrLetCanalConEtiqueta,int* arrCanalConEtiqueta,int cantStreams,
                                int* arrEtiquetas,int* arrDuracionEtiquetas, int cantEtiquetas, int* arrCantReproducciones,int* arrDuracionReproducciones);
void emitirReporte(ofstream& reporte,double tarifa, int* arrEtiquetas,int* arrDuracionEtiquetas, int cantEtiquetas,char* arrLetCanalConEtiqueta, int* arrEtiquetaEnCanal,int* arrCanalConEtiqueta
                    , int cantStreams, int* arrCantReproducciones,int* arrDuracionReproducciones, int* codigo, char* letCodigo, double* rating, int cantCanales);
void mostrarCanal(ofstream& reporte, int* codigo, char* letCodigo, double* rating, int cantCanales,char* letCodCanal, int* arrEtiquetaEnCanal,int* arrCanalConEtiqueta,
                    int cantStreams, int etiquetaBuscada, int* arrCantReproducciones,int* arrDuracionReproducciones);
double buscarRatingDeCanal(int* codigo, char* letCodigo, double* rating,int cantCanales, char letraABuscar, int codigoABuscar);
void separadorCaracter(ofstream& arch, char caracter);
void mostrarTiempo(ofstream& arch, int duracion);


#endif //REPASOEXAMENPARCIAL_FUNCIONESADICIONALES_H