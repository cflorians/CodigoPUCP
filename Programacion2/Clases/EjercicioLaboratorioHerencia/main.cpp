#include <iostream>
using namespace std;

#include "Bibliotecas/Tesoreria.h"

int main(int argc, char** argv) {

    Tesoreria caja;

    caja.cargaescalas("Archivos/escalas.csv");
    caja.cargaalumnos("Archivos/Alumnos.csv");
    caja.actualiza(20);
    caja.imprime("Reportes/reporte.txt");

    return 0;
}
