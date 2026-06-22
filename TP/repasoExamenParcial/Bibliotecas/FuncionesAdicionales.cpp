//
// Created by carlo on 10/10/2025.
//
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "FuncionesAdicionales.h"

void abrirArchivo(ifstream& arch, const char* nombreArch) {
    arch.open(nombreArch, ios::in);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << nombreArch << endl;
        exit(1);
    }
}

void abrirArchivo(ofstream& arch, const char* nombreArch) {
    arch.open(nombreArch, ios::out);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << nombreArch << endl;
        exit(1);
    }
}

void cargarDatosCanales(ifstream& canales, int* codigo, char* letCodigo, double* rating, int& cantCanales) {
    //19/06/2022     X5514     xQcOW     2.5
    int n;
    char c;
    cantCanales = 0;
    while (canales >> n) {
        canales >> c >> n >> c >> n;
        canales >> ws >> letCodigo[cantCanales] >> codigo[cantCanales];
        saltarTexto(canales);
        canales >> rating[cantCanales];
        cantCanales++;
    }
}

void cargarDatosEtiquetas(ifstream& etiquetas,int* codEtiquetas, int* duracion, int& cantEtiquetas) {
    //803100    dropsenabled   01:27
    int min, seg;
    char c;
    cantEtiquetas = 0;
    while (etiquetas >> codEtiquetas[cantEtiquetas]) {
        saltarTexto(etiquetas);
        etiquetas >> min >> c >> seg;
        duracion[cantEtiquetas] = min*60 + seg;
        cantEtiquetas++;
    }
}

void saltarTexto(ifstream& arch) {
    arch >> ws;
    while (arch.get()!=' ');
}

void cargarDatosEtiquetasEnCanales(istream& etiquetasEnCanales, int* codCanal, char* letCanal, int* etiqueta, int& cantStreams) {
    //P7271    113141
    cantStreams = 0;
    while (true) {
        etiquetasEnCanales >> letCanal[cantStreams] >> codCanal[cantStreams] >> etiqueta[cantStreams];
        if (etiquetasEnCanales.peek() == EOF) break;
        cantStreams++;
    }
}

void emitirReporteSimple(ofstream& reporte,  int* codigo, char* letCodigo, double* rating, int& cantCanales,
                                        int* codEtiquetas, int* duracion, int& cantEtiquetas,
                                        int* codCanal, char* letCanal, int* etiqueta, int& cantStreams) {
    int i=0;

    reporte << "CODIGO DEL CANAL" << setw(10) << "RATING" << endl;
    for (i=0; i<cantCanales; i++) {
        reporte << letCodigo[i] << codigo[i] << setw(20) << rating[i] << endl;
    }

    reporte << endl << "ETIQUETAS" << setw(10) << "DURACION" << endl;
    for (i=0; i<cantEtiquetas; i++) {
        reporte << codEtiquetas[i] << setw(11) << duracion[i] << endl;
    }

    reporte << endl << "ETIQUETA EN CANAL" << setw(10) << "CANAL" << endl;
    for (i=0; i<cantStreams; i++) {
        reporte << etiqueta[i] << setw(17) << letCanal[i] << codCanal[i] << endl;
    }
}

void ordenarPorDuracion(int* etiquetas, int* duracion, int cantEtiquetas) {
    int i=0, j=0, temp;
    for (i=0; i<cantEtiquetas; i++) {
        for (j=i+1; j<cantEtiquetas; j++) {
            if (duracion[i] > duracion[j]) {
                temp = duracion[i];
                duracion[i] = duracion[j];
                duracion[j] = temp;

                temp = etiquetas[i];
                etiquetas[i] = etiquetas[j];
                etiquetas[j] = temp;
            }
        }
    }
}

void determinarCantReproducciones(ifstream& arch,int* arrEtiquetaEnCanal,char* arrLetCanalConEtiqueta,int* arrCanalConEtiqueta,int cantStreams,
                                int* arrEtiquetas,int* arrDuracionEtiquetas, int cantEtiquetas, int* arrCantReproducciones,int* arrDuracionReproducciones) {
    //cargar datos a arreglo auxiliar para manejar los datos del archivo
    //28/02/2025  E6696      888106      244
    int n, etiqueta[750]{}, reproducciones[750]{}, canal[750]{}, cantReproduccionesEnEtiquetas=0, i=0, j=0, pos, etiquetaActual;
    char c, letCanal[750]{};
    while (arch >> n) {
        arch >> c >> n >> c >> n;
        arch >> ws >> letCanal[cantReproduccionesEnEtiquetas] >> canal[cantReproduccionesEnEtiquetas];
        arch >> etiqueta[cantReproduccionesEnEtiquetas] >> reproducciones[cantReproduccionesEnEtiquetas];
        cantReproduccionesEnEtiquetas++;
    }
    //aca ya tengo el archivo en 2 arreglos que necesito
    //ahora para cada par de canal-etiqueta buscamos su cantidad de reproducciones en los arreglos auxiliares
    for (i=0; i<cantStreams; i++) {
        for (j=0; j<cantReproduccionesEnEtiquetas; j++) {
            if (arrLetCanalConEtiqueta[i] == letCanal[j] and arrCanalConEtiqueta[i] == canal[j] and arrEtiquetaEnCanal[i] == etiqueta[j]) {
                arrCantReproducciones[i] = reproducciones[j];
                etiquetaActual = arrEtiquetaEnCanal[i];
                arrDuracionReproducciones[i] = buscarReproducciones(etiquetaActual, arrEtiquetas, arrDuracionEtiquetas, cantEtiquetas);
            }
        }
    }
}

int buscarReproducciones(int etiquetaActual, int* arrEtiquetas,int* arrDuracionEtiquetas, int cantEtiquetas) {
    int i=0;
    for (i=0; i<cantEtiquetas; i++) {
        if (etiquetaActual == arrEtiquetas[i]) {
            return arrDuracionEtiquetas[i];
        }
    }
}

void emitirReporte(ofstream& reporte,double tarifa, int* arrEtiquetas,int* arrDuracionEtiquetas, int cantEtiquetas,char* arrLetCanalConEtiqueta, int* arrEtiquetaEnCanal,int* arrCanalConEtiqueta
                    , int cantStreams, int* arrCantReproducciones,int* arrDuracionReproducciones, int* codigo, char* letCodigo, double* rating, int cantCanales) {
    int i=0, etiquetaBuscada;
    reporte << setw(33) << ' ' << "PLATAFORMA TP_TWITCH" << endl;
    reporte << setw(8) << ' ' << "TARIFA POR DURACION DE LAS ETIQUETAS: " << tarifa << " POR CADA MINUTO Y FRACCION"<< endl;
    separadorCaracter(reporte, '=');
    for (i=0; i < cantEtiquetas; i++) {
        reporte << "ETIQUETA No. " << i+1 << endl;
        reporte << setw(4) << ' ' <<  "CODIGO: " << arrEtiquetas[i] << endl;
        reporte << setw(4) << ' ' << "DURACION: ";
        mostrarTiempo(reporte, arrDuracionEtiquetas[i]);
        reporte << endl;
        separadorCaracter(reporte, '-');
        reporte << setw(4) << ' ' <<"CANALES DONDE SE REPRODUCE:" << endl;
        reporte << setw(25) << "RATING DE" << setw(22) << "NUMERO TOTAL" << setw(23) << "TIEMPO TOTAL DE" << endl;
        reporte << "No." << setw(8) << "CODIGO" << setw(13) << "CALIDAD" << setw(25) << "DE REPRODUCCIONES" << setw(20) << "REPRODUCCIONES" << endl;
        mostrarCanal(reporte, codigo, letCodigo, rating, cantCanales, arrLetCanalConEtiqueta, arrEtiquetaEnCanal,arrCanalConEtiqueta, cantStreams,
                        arrEtiquetas[i], arrCantReproducciones, arrDuracionReproducciones);
        separadorCaracter(reporte, '-');
        reporte << "RESUMEN DE ETIQUETA: " << endl;
        separadorCaracter(reporte, '=');
        //buscar los canales donde se reproduce cada etiqueta y obtener su rating, reproduciones y el total de tiempo
        //hacer resumen de la etiqueta con: total reproducciones, tiempo total, porcentaje promedio por rating, ingresos por reproducciones
    }
}

void mostrarCanal(ofstream& reporte, int* codigo, char* letCodigo, double* rating, int cantCanales,char* letCodCanal, int* arrEtiquetaEnCanal,int* arrCanalConEtiqueta,
                    int cantStreams, int etiquetaBuscada, int* arrCantReproducciones,int* arrDuracionReproducciones) {
    int i=0, contadorStreams=1, etiquetaActual, reproducciones;
    double ratingDelCanal;
    for (i=0; i < cantStreams; i++) {
        etiquetaActual = arrCanalConEtiqueta[i];
        if (etiquetaActual == etiquetaBuscada) {
            reporte << setw(2) << contadorStreams << ')' << setw(4) << letCodCanal[i] << arrEtiquetaEnCanal[i];
            ratingDelCanal = buscarRatingDeCanal(codigo, letCodigo, rating, cantCanales, letCodCanal[i], arrEtiquetaEnCanal[i]);
            reporte << setw(11) << fixed << setprecision(2) << ratingDelCanal << endl;
            //buscar reproducciones
            contadorStreams++;
        }
    }
}

int buscarReproduccionesConCanal(int* codigo, char* letCodigo, int* etiquetas) {

}

double buscarRatingDeCanal(int* codigo, char* letCodigo, double* rating,int cantCanales, char letraABuscar, int codigoABuscar) {
    int i=0;
    for (i=0; i < cantCanales; i++) {
        if (letraABuscar == letCodigo[i] and codigo[i] == codigoABuscar) {
            return rating[i];
        }
    }
    return -1;
}

void separadorCaracter(ofstream& arch, char caracter) {
    arch << setfill(caracter);
    arch << setw(85) << caracter << endl;
    arch << setfill(' ');
}

void mostrarTiempo(ofstream& arch, int duracion) {
    int min, seg;
    min = duracion/60;
    seg = duracion%60;
    arch << setfill('0');
    arch << setw(2) <<min << ":" << setw(2) << seg;
}