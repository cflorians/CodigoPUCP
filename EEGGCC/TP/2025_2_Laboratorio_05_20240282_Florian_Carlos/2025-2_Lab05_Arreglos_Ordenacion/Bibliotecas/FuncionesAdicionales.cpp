//
// Created by carlo on 6/10/2025.
//
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

#include "FuncionesAdicionales.h"

void cargarCanales(int* arrCodigo,char* arrLetraCod, double* arrRating, int& cantDatos)
{
    int n;
    char c;
    ifstream arch("ArchivosDeDatos/Canales.txt", ios::in);
    if (not arch.is_open())
    {
        cout << "Error al abrir archivo de Canales.txt" << endl;
        exit(1);
    }
    //19/06/2022     X5514     xQcOW     2.5
    cantDatos = 0;
    while (arch >> n)
    {
        arch >> c >> n >> c >> n;
        while (arch.peek() == ' ') arch.get();
        arch >> arrLetraCod[cantDatos];
        arch >> arrCodigo[cantDatos];
        while (arch.peek() == ' ') arch.get();
        while (arch.peek() != ' ') arch.get();
        arch >> arrRating[cantDatos];
        cantDatos++;
    }
}

void cargarEtiquetas(int* arrEtiquetas, int* arrDuracionEtiquetas,int& cantEtiquetas)
{
    int mm, ss;
    char c;
    ifstream arch("ArchivosDeDatos/Etiquetas.txt", ios::in);
    if (not arch.is_open())
    {
        cout << "Error al abrir archivo de Etiquetas.txt" << endl;
        exit(1);
    }
    //803100    dropsenabled   01:27
    cantEtiquetas = 0;
    while (arch >> arrEtiquetas[cantEtiquetas])
    {
        while (arch.peek() == ' ') arch.get();
        while (arch.peek() != ' ') arch.get();
        arch >> mm >> c >> ss;
        arrDuracionEtiquetas[cantEtiquetas] = mm*60+ss;
        cantEtiquetas++;
    }
}

void cargarEtiquetasEnCanales(int* arrCanalEtiqueta, char* arrLetCanalEtiqueta, int* arrEtiquetaEnCanal, int& cantStreams)
{
    ifstream arch("ArchivosDeDatos/EtiquetasEnCanales.txt", ios::in);
    if (not arch.is_open())
    {
        cout << "Error al abrir archivo de EtiquetasEnCanales.txt" << endl;
        exit(1);
    }
    //P7271    113141
    cantStreams = 0;
    while (true)
    {
        arch >> arrLetCanalEtiqueta[cantStreams] >> arrCanalEtiqueta[cantStreams] >> arrEtiquetaEnCanal[cantStreams];
        if (arch.eof()) break;
        cantStreams++;
    }
}

void ordenarEtiquetas(int* arrEtiquetas, int* arrDuracionEtiquetas,int cantStreams)
{
    int i=0, j=0, temp;
    for (i=0; i<cantStreams-1; i++)
    {
        for (j=i+1; j<cantStreams; j++)
        {
            if (arrDuracionEtiquetas[i] > arrDuracionEtiquetas[j])
            {
                temp = arrDuracionEtiquetas[i];
                arrDuracionEtiquetas[i] = arrDuracionEtiquetas[j];
                arrDuracionEtiquetas[j] = temp;

                temp = arrEtiquetas[i];
                arrEtiquetas[i] = arrEtiquetas[j];
                arrEtiquetas[j] = temp;
            }
        }
    }
}

void emitirReporteSimple(int* arrCodigo,char* arrLetraCod, double* arrRating, int& cantDatos,
                        int* arrEtiquetas, int* arrDuracionEtiquetas,int& cantEtiquetas)
{
    int i=0;
    ofstream reporte("ArchivosDeReporte/ReporteSimple.txt", ios::out);

    reporte << "CODIGO CANAL" << setw(10) << "RATING" << endl;
    for (i=0; i<cantDatos; i++)
    {
        reporte << arrLetraCod[i] << arrCodigo[i] << setw(15) << fixed << setprecision(2) << arrRating[i] << endl;
    }

    reporte << endl << "ETIQUETAS" << setw(13) << "DURACION" <<endl;
    for (i=0; i<cantEtiquetas; i++)
    {
        reporte << arrEtiquetas[i] << setw(11) << arrDuracionEtiquetas[i] << " seg" << endl;
    }
}

void determinarReproducciones(int* arrReproducciones, int* arrCanalEtiqueta, char* arrLetCanalEtiqueta,
                                int* arrEtiquetaEnCanal, int* tiempoReproducciones,
                                int* arrEtiquetas, int* arrDuracionEtiquetas,int cantEtiquetas,
                                int* arrCodigo,char* arrLetraCod, int cantDatos)
{
    int n, codigoActual, etiquetaActual, reproducciones, i=0, pos, tiempo;
    char c, letraCodigoActual;
    ifstream arch("ArchivosDeDatos/ReproduccionesDeEtiquetas.txt", ios::in);
    if (not arch.is_open())
    {
        cout << "Error al abrir archivo de ReproduccionesDeEtiquetas.txt" << endl;
        exit(1);
    }

    //28/02/2025  E6696      888106      244
    //fecha       codigo     etiqueta    reproducciones
    while (arch >> n)
    {
        arch >> c >> n >> c >> n;

        while (arch.peek() == ' ') arch.get();

        arch >> letraCodigoActual >> codigoActual >> etiquetaActual >> reproducciones;

        for (i=0; i<cantDatos; i++)
        {
            if (arrLetCanalEtiqueta[i] == letraCodigoActual and arrCanalEtiqueta[i] == codigoActual and etiquetaActual == arrEtiquetaEnCanal[i])
            {
                pos = buscarCanal(arrCodigo, arrLetraCod, cantDatos, letraCodigoActual, codigoActual);
                arrReproducciones[pos] += reproducciones;
            }
        }
    }
}

int buscarCanal(int* arrCodigo, char* arrLetCod, int cantCanales, char letCod, int codigo)
{
    int pos=0;
    for (pos=0; pos<cantCanales; pos++)
    {
        if (arrLetCod[pos] == letCod and codigo == arrCodigo[pos])
        {
            return pos;
        }
    }
}