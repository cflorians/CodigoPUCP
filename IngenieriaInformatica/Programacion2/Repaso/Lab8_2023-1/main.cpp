#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "Bibliotecas/Tesoreria.h"

int main() {

    Tesoreria caja;

    caja.cargaEscala("Archivos/escalas.csv");
    caja.cargaAlumnos("Archivos/alumnos.csv");
    caja.actualiza(10);
    caja.imprime("Reportes/reporte.txt");

    return 0;
}
