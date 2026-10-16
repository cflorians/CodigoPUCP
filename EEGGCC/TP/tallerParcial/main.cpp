#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "BIbliotecas/FuncionesAdicionales.h"

#define MAX_LIBROS 300
#define MAX_VENTAS 100

int main(int argc, char *argv[]) {
    ifstream clientes, libros, ventas;
    ofstream reporteSimple, reporte;
    int codigoLibro[MAX_LIBROS]{}, cantLibros;
    double precioLibro[MAX_LIBROS]{};
    //99377    29/04/2024    6398790    92240876    18    6384129    15129661    21
    //codLibreria fecha      codLibro     dni    clasificacion  codLibro dni    clasificacion
    int fechaVenta[MAX_VENTAS]{}, ;

    abrirArchivos(clientes, "ArchivosDeDatos/Clientes.txt");
    abrirArchivos(libros, "ArchivosDeDatos/libros.txt");
    abrirArchivos(ventas, "ArchivosDeDatos/Ventas.txt");
    abrirArchivos(reporteSimple, "ArchivosDeReporte/ReporteSimple.txt");
    abrirArchivos(reporte, "ArchivosDeReporte/Reporte.txt");

    cargarDatosLibros(libros, codigoLibro, precioLibro, cantLibros);
    generarReporteSimple(reporteSimple, codigoLibro, precioLibro, cantLibros);



    return 0;
}
