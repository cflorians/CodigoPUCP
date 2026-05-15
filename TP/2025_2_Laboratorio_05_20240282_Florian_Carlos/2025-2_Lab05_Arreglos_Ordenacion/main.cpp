#include <iostream>
#include <iomanip>
using namespace std;
#include "Bibliotecas/FuncionesAdicionales.h"
#define MAX_CANALES 150
#define MAX_ETIQUETAS 150
#define MAX_STREAMS 600

int main(int argc, char *argv[])
{
    int arrCodigo[MAX_CANALES]{}, arrEtiquetas[MAX_ETIQUETAS]{}, arrDuracionEtiquetas[MAX_ETIQUETAS]{};
    double arrRating[MAX_CANALES]{};
    char arrLetraCod[MAX_CANALES]{};
    int arrCanalEtiqueta[MAX_STREAMS]{}, arrEtiquetaEnCanal[MAX_STREAMS]{};
    char arrLetCanalEtiqueta[MAX_CANALES]{};
    int cantCanales, cantEtiquetas, cantStreams;
    int arrReproducciones[MAX_CANALES]{}, tiempoReproducciones[MAX_CANALES]{};
    double tarifa = 0.78;

    //cin >> tarifa;

    cargarCanales(arrCodigo, arrLetraCod, arrRating, cantCanales);
    cargarEtiquetas(arrEtiquetas, arrDuracionEtiquetas, cantEtiquetas);
    cargarEtiquetasEnCanales(arrCanalEtiqueta, arrLetCanalEtiqueta, arrEtiquetaEnCanal, cantStreams);
    ordenarEtiquetas(arrEtiquetas, arrDuracionEtiquetas, cantEtiquetas);
    emitirReporteSimple(arrCodigo, arrLetraCod, arrRating, cantCanales,
                        arrEtiquetas, arrDuracionEtiquetas, cantEtiquetas);

    return 0;
}