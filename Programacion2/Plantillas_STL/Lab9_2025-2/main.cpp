#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <vector>
using namespace std;

#include "Bibliotecas/SistemaDeGestion.h"

int main() {

    SistemaDeGestion sistema;

    sistema.cargaCategorias("Archivos/Categorias.csv");
    sistema.cargaComentarios("Archivos/Comentarios.csv");
    sistema.cargaEtiquetas("Archivos/Etiquetas.csv");
    sistema.cargaStreamers("Archivos/Streamers.csv");

    sistema.completarStreamers();
    sistema.mostrarReporte("Reportes/reporte.txt");

    return 0;
}
