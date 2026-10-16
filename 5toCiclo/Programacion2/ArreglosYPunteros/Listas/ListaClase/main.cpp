#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "Bibliotecas/Lista.h"

int main() {

    Lista lista;
    lista.crear("Archivos/personal.csv");
    lista.imprimir("Reporte/reportePersona.txt");

    return 0;
}
