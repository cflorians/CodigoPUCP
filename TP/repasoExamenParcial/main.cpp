#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Bibliotecas/FuncionesAdicionales.h"
#define MAX_CANALES 150
#define MAX_ETIQUETAS 110
#define MAX_STREAMS 600

int main(int argc, char *argv[]) {

    //19/06/2022     X5514     xQcOW     2.5    canales
    int arrCodCanal[MAX_CANALES]{}, cantCanales;
    double arrRating[MAX_CANALES]{};
    char arrLetraCodCanal[MAX_CANALES]{};
    //803100    dropsenabled   01:27            etiquetas
    int arrEtiquetas[MAX_ETIQUETAS]{}, arrDuracionEtiquetas[MAX_ETIQUETAS]{}, cantEtiquetas;
    //P7271    113141                           etiquetas en canales
    int arrEtiquetaEnCanal[MAX_STREAMS]{}, arrCanalConEtiqueta[MAX_STREAMS]{}, cantStreams;
    char arrLetCanalConEtiqueta[MAX_STREAMS]{};
    //de reproducciones de etiquetas
    int arrCantReproducciones[MAX_STREAMS]{}, arrDuracionReproducciones[MAX_STREAMS]{};
    double tarifa=0.78;

    ifstream canales, etiquetas, etiquetasCanales, reproduccionesEtiquetas;
    ofstream reporte, reporteSimple;

    abrirArchivo(canales, "ArchivosDeDatos/Canales.txt");
    abrirArchivo(etiquetas, "ArchivosDeDatos/Etiquetas.txt");
    abrirArchivo(etiquetasCanales, "ArchivosDeDatos/EtiquetasEnCanales.txt");
    abrirArchivo(reproduccionesEtiquetas, "ArchivosDeDatos/ReproduccionesDeEtiquetas.txt");
    abrirArchivo(reporteSimple, "ArchivosDeReporte/ReporteSimple.txt");
    abrirArchivo(reporte, "ArchivosDeReporte/Reporte.txt");

    //cin >> tarifa;

    cargarDatosCanales(canales, arrCodCanal, arrLetraCodCanal, arrRating, cantCanales);
    cargarDatosEtiquetas(etiquetas, arrEtiquetas, arrDuracionEtiquetas, cantEtiquetas);
    cargarDatosEtiquetasEnCanales(etiquetasCanales, arrEtiquetaEnCanal, arrLetCanalConEtiqueta, arrCanalConEtiqueta, cantStreams);

    emitirReporteSimple(reporteSimple,  arrCodCanal, arrLetraCodCanal, arrRating, cantCanales, arrEtiquetas, arrDuracionEtiquetas,
                        cantEtiquetas, arrEtiquetaEnCanal, arrLetCanalConEtiqueta, arrCanalConEtiqueta, cantStreams);

    ordenarPorDuracion(arrEtiquetas, arrDuracionEtiquetas, cantEtiquetas);

    determinarCantReproducciones(reproduccionesEtiquetas, arrEtiquetaEnCanal, arrLetCanalConEtiqueta, arrCanalConEtiqueta, cantStreams,
                                 arrEtiquetas, arrDuracionEtiquetas,  cantEtiquetas,  arrCantReproducciones, arrDuracionReproducciones);

    emitirReporte(reporte, tarifa, arrEtiquetas, arrDuracionEtiquetas, cantEtiquetas,  arrLetCanalConEtiqueta, arrEtiquetaEnCanal, arrCanalConEtiqueta, cantStreams,
                arrCantReproducciones, arrDuracionReproducciones,  arrCodCanal, arrLetraCodCanal, arrRating, cantCanales);

    return 0;
}
