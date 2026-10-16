#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Bibliotecas/Tesoreria.h"

int main(int argc, char** argv) {

    Tesoreria OTeso;

    OTeso.cargaEscalas();
    OTeso.cargaAlumnos();
    //OTeso.actualizaBoleta();
    OTeso.imprimeBoleta();

    return 0;
}
