#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Bibliotecas/FuncionesAdicionales.h"
#define MAX_PACIENTES 100
#define MAX_MEDICINAS 250

int main(int argc, char *argv[]) {
    ifstream citas, medicinas, medicos, pacientes;
    ofstream reporte;
    //61061535   [ROCIO YOLANDA ACUNA YINO]   15055   2015   2.60
    //dni              nombre              distrito nacimiento descuento
    int dniPaciente[MAX_PACIENTES]{}, distritoPaciente[MAX_PACIENTES]{}, nacimientoPaciente[MAX_PACIENTES]{}, cantPacientes;
    double descuentoPaciente[MAX_PACIENTES]{};
    //60509 AMPICILINA_125MG_SUSP_90ML   58.65
    //codigoMedicina   desc              precio
    int codMedicinas[MAX_MEDICINAS]{}, cantMedicinas;
    double precioMedicina[MAX_MEDICINAS]{};

    abrirArchivo(citas, "ArchivosDeDatos/CitasMedicas.txt");
    abrirArchivo(medicinas, "ArchivosDeDatos/Medicinas.txt");
    abrirArchivo(medicos, "ArchivosDeDatos/Medicos.txt");
    abrirArchivo(pacientes, "ArchivosDeDatos/Pacientes.txt");
    abrirArchivo(reporte, "ArchivosDeReporte/Reporte.txt");

    cargarDatosPacientes(pacientes, dniPaciente, distritoPaciente, nacimientoPaciente, descuentoPaciente, cantPacientes);
    cargarDatosMedicinas(medicinas, codMedicinas, precioMedicina, cantMedicinas);

    emitirReporteSimple(reporte, dniPaciente, distritoPaciente, nacimientoPaciente, descuentoPaciente, cantPacientes, codMedicinas, precioMedicina, cantMedicinas);


    return 0;
}