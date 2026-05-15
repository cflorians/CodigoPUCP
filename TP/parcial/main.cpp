#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Bibliotecas/FuncionesAdicionales.h"

int main(int argc, char *argv[]) {

    ifstream canales, categorias, idiomas, streams;
    ofstream reporte;

    abrirArchivos(canales, "ArchivosDeDatos/Canales.txt");
    abrirArchivos(categorias, "ArchivosDeDatos/Categorias.txt");
    abrirArchivos(idiomas, "ArchivosDeDatos/Idiomas.txt");
    abrirArchivos(streams, "ArchivosDeDatos/Streams.txt");
    abrirArchivos(reporte, "ArchivosDeReporte/Reporte.txt");

    mostrarTitulo(reporte);
    procesarStreams(streams, canales, categorias, idiomas, reporte);


    return 0;
}