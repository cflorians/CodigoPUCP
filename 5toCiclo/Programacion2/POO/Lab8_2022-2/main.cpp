#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Bibliotecas/Farmacia.h"

int main() {

    Farmacia ofarma;

    ofarma.cargaMedico("Archivos/medicos.csv");
    ofarma.leeRecetas("Archivos/recetas.csv", "Archivos/medicamentos.csv");

    return 0;
}
