#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Bibliotecas/FuncionesAdicionales.h"
#include "Bibliotecas/Estructuras.h"

int main(int argc, char* argv[]) {

    struct TablaDeInfracciones arrTablaDeInfracciones[150]{};
    struct EmpresasRegistradas arrEmpresasRegistradas[50]{};
    int cantInfracciones, cantEmpresas;

    leerInfracciones(arrTablaDeInfracciones, cantInfracciones);
    leerEmpresas(arrEmpresasRegistradas, cantEmpresas);
    leerPlacas(arrEmpresasRegistradas, cantEmpresas);


    return 0;
}