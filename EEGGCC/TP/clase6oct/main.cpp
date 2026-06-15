#include <iostream>
#include <iomanip>
using namespace std;
#include "Bibliotecas/FuncionesAdicionales.h"
#define MAX_TAM 50

int main(int argc, char *argv[])
{
    int arrDni[MAX_TAM]{};
    int arrFecha[MAX_TAM]{};
    double arrDouble[MAX_TAM]{};
    int cantDatos, dniAborrar;

    cargarArreglosOrdenado(arrDni, arrFecha, arrDouble, cantDatos);
    imprimirReporteSimple(arrDni, arrFecha, arrDouble, cantDatos);
    //cargarArreglos(arrDni, arrFecha, arrDouble, cantDatos);
    //ordenarPorDni(arrDni, arrFecha, arrDouble, cantDatos);
    //imprimirReporteSimple(arrDni, arrFecha, arrDouble, cantDatos);

    cout << "Escriba dni a borrar: ";
    cin >> dniAborrar;
    eliminarDelArreglo(arrDni, arrFecha, arrDouble, cantDatos, dniAborrar);
    imprimirReporteSimple(arrDni, arrFecha, arrDouble, cantDatos);

    return 0;
}