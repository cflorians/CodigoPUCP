#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
using namespace std;

#include "Bibliotecas/Infraccion.h"
#include "Bibliotecas/Vehiculo.h"
#include "Bibliotecas/Multa.h"
#include "Bibliotecas/Empresa.h"
#include "Bibliotecas/MinisterioDeTransporte.h"

int main() {

    MinisterioDeTransporte mt;

    mt.cargaDeInfracciones("Archivos/TablaDeInfracciones.csv");
    mt.cargaEmpresas("Archivos/EmpresasRegistradas.csv");
    mt.cargaVehiculos("Archivos/VehiculosRegistrados.csv");
    // mt.cargaInfraccionesCometidas("Archivos/InfraccionesCometidas.csv");
    // mt.reporteDeEmpresaConInfracciones("Reportes/reporte1.txt");
    // mt.eliminaInfraccionesPagadas();
    // mt.reporteDeEmpresaConInfracciones("Reportes/reporte2.txt");

    return 0;
}
