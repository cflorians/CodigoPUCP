#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Bibliotecas/FuncionesAdicionales.h"
#define MAX_MEDICOS 50
#define MAX_MEDICINAS 250

int main(int argc, char *argv[])
{

    int arrCodMed[MAX_MEDICOS]{}, arrMedicinas[MAX_MEDICINAS]{};
    int i=0;
    double arrTarifaMed[MAX_MEDICOS]{}, arrPrecioMedicinas[MAX_MEDICINAS]{};
    int cantMed, cantMedicinas, numMedico = 0;

    ofstream reporte("ArchivosDeReporte/Reporte.txt", ios::out);

    procesarMedicos(arrCodMed, arrTarifaMed, cantMed);
    procesarMedicamentos(arrMedicinas, arrPrecioMedicinas, cantMedicinas);

    mostrarEncabezado();
    while (i < cantMed)
    {
        procesarCitaMedica(arrCodMed, arrTarifaMed, numMedico);
        procesarCitaPaciente(arrCodMed,arrMedicinas, arrPrecioMedicinas, numMedico, cantMedicinas);
        numMedico++;
    }




    // reporte << "CODIGO DE MEDICO" << setw(10) << "TARIFA" << endl;
    // for (int i = 0; i < cantMed; i++)
    // {
    //     reporte << arrCodMed[i] << setw(21) << arrTarifaMed[i] << endl;
    // }
    //
    // reporte << "MEDICAMENTO" << setw(10) << "PRECIO" << endl;
    // for (int i = 0; i < cantMedicinas; i++)
    // {
    //     reporte << arrMedicinas[i] << setw(17) << arrPrecioMedicinas[i] << endl;
    // }
    return 0;
}