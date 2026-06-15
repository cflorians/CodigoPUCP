#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Bibliotecas/Funciones.h"

int main(int argc, char** argv) {
    
    char ***libros, ***pedidosLibros;
    int **stock, **pedidosClientes;
    bool **pedidosAtendidos;

    lecturaDeLibros("ArchivosDeDatos/Libros.csv", libros, stock);
    pruebaDeLecturaDeLIbros("ArchivosDeReporte/ReporteDeLibrosInicial.txt", libros, stock);

    atencionDePedidos("ArchivosDeDatos/Pedidos.txt", libros, stock, pedidosClientes,
                      pedidosLibros, pedidosAtendidos);
    // pruebaLecturaDeLibros("ArchivosDeReporte/ReporteDeLibrosFinal", libros, stock);
    //
    // reporteDeEntregaDePedidos("ArchivosDeReporte/ReporteDeEntregaDePedidos", pedidosClientes,
    //                           pedidosLibros, pedidosAtendidos);
    
    return 0;
}
