#include <iostream>
using namespace std;

#include "Bibliotecas/MinisterioDeTransporte.h"

int main(int argc, char** argv) {
    
    MinisterioDeTransporte ministerioDeTransporte;

    ministerioDeTransporte < "Archivos/TablaDeInfracciones.csv";
    ministerioDeTransporte <= "Archivos/EmpresasRegistradas.csv";
    ministerioDeTransporte <<= "Archivos/InfraccionesCometidas.csv";
    ministerioDeTransporte >> "Reportes/ReporteParaElMinisterio.txt";
    
    return 0;
}
