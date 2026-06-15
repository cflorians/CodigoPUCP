#include <iostream>
using namespace std;

#include "Bibliotecas/BibliotecaGenerica.h"
#include "Bibliotecas/ListaConEnteros.h"
#include "Bibliotecas/ListaConRegistros.h"

int main(int argc, char** argv) {
    void* lista;

    crealista(lista, leenumeros, "Archivos/numeros1.txt");
    cargalista(lista, compruebanumero, leeregnumeros, "Archivos/numeros2.txt");
    muestralista(lista, imprimenumeros, "Reportes/repnum.txt");

    crealista(lista, leeregistros, "Archivos/Repartidores.csv");
    cargalista(lista, compruebaregistro, leeordenes, "Archivos/Ordenes.csv");
    muestralista(lista, imprimeregistros, "Reportes/repregistros.txt");
    
    return 0;
}
