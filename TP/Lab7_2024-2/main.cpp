#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Bibliotecas/FuncionesAdicionales.h"
#define MAX_REPARTIDORES 100
#define MAX_PLATOS 150

int main(int argc, char *argv[]) {

    // 54805724   Vizcardo_Sinche_Maribel     Motocicleta      4826   Santa_Rosa
    // dni         nombre                     vehiculo        codDist  nomDist
    int dniRepartidores[MAX_REPARTIDORES]{}, codDistRepartidores[MAX_REPARTIDORES]{}, cantRepartidores;
    char *nombreRepartidores[MAX_REPARTIDORES]{}, *vehiculoRepartidores[MAX_REPARTIDORES]{}, *nomDistRepartidores[MAX_REPARTIDORES]{};
    // 11283   2_BOLAS_DE_HELADO      14.90   POSTRES    17.72%
    // cod       nombre               precio  categoria   descuento
    int codPlatos[MAX_PLATOS]{}, cantPlatos;
    double precioPlatos[MAX_PLATOS]{}, descuentoPlatos[MAX_PLATOS]{};
    char *nombrePlatos[MAX_PLATOS]{}, *categoriaPlatos[MAX_PLATOS]{};

    leerRepartidores(dniRepartidores, codDistRepartidores, cantRepartidores, nombreRepartidores, vehiculoRepartidores,
                     nomDistRepartidores);
    leerPlatosOfrecidos(codPlatos, precioPlatos, descuentoPlatos, nombrePlatos, categoriaPlatos, cantPlatos);
    verificarAsignacion(dniRepartidores, codDistRepartidores, cantRepartidores, nombreRepartidores, vehiculoRepartidores,
                        nomDistRepartidores, codPlatos, precioPlatos, descuentoPlatos, nombrePlatos, categoriaPlatos, cantPlatos,
                        "ArchivosDeReporte/ReporteDePrueba.txt");

    ordenarPorNombre(dniRepartidores, codDistRepartidores, cantRepartidores, nombreRepartidores, vehiculoRepartidores, nomDistRepartidores);
    verificarAsignacion(dniRepartidores, codDistRepartidores, cantRepartidores, nombreRepartidores, vehiculoRepartidores,
                        nomDistRepartidores, codPlatos, precioPlatos, descuentoPlatos, nombrePlatos, categoriaPlatos, cantPlatos,
                        "ArchivosDeReporte/ReporteOrdenadoDePrueba.txt");

    return 0;
}