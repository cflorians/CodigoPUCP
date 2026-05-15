#include <iostream>
using namespace std;

#include "Bibliotecas/MinisterioDeTransporte.h"

int main(int argc, char** argv) {
    
    MinisterioDeTransporte ministerio;

    ministerio < "Archivos/TablaDeInfracciones.csv";
    ministerio <= "Archivos/EmpresasRegistradas.csv";
    ministerio <<= "Archivos/InfraccionesCometidas.csv";
    ministerio >> "Reportes/ReporteParaElMinisterio.txt";
    
    return 0;
}
