#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Bibliotecas/Arbol.h"

int main() {

    Arbol arbol;

    //arbol.crearArbol("Archivos/datos.txt");
    arbol.crearArbol("Archivos/personal.csv");
    //arbol.recorrerEnOrden("Reporte/ReporteINT.txt");
    arbol.recorrerEnOrden("Reporte/ReportePersonal.txt");

    return 0;
}
