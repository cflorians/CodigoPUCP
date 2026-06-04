#include <iostream>
using namespace std;

#include "Bibliotecas/Tesoreria.h"

int main(int argc, char** argv) {
    //Siempre respetando
    Tesoreria objTeso;

    objTeso.cargaEscalas();
    objTeso.cargaAlumnos();
    objTeso.actualizaBoleta();
    objTeso.imprimeBoleta();

    return 0;
}
