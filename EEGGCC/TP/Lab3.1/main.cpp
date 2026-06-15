#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Bibliotecas/FuncionesAdicionales.h"

int main(int argc, char *argv[])
{
    int tiempoMax = 2*3600 + 31*60 +25;
    int dia_cita, mes_cita, agno_cita, dni_Paciente, tiempoCita;
    int codMedico;
    int hora_i, min_i, seg_i;
    int hora_fin, min_fin, seg_fin;
    double descuento, tarifa;
    char caracter;

    ofstream reporte("ArchivosDeReporte/Reporte.txt", ios::out);
    ifstream citasMedicas("ArchivosDeDatos/CitasMedicas.txt", ios::in);
    ifstream medicos("ArchivosDeDatos/Medicos.txt", ios::in);

    //mostrar encabezado
    reporte << setw(70) << "EMPRESA DE SALUD S.A." << endl;
    separadorCaracter('=', reporte);
    reporte << setw(71) << "REGISTRO CITAS MEDICAS" << endl;
    separadorCaracter('=', reporte);

    //procesar medico
    procesarMedicos(codMedico, tarifa, medicos, reporte);

    /*
    while (citasMedicas >> dia_cita)
    {
        leerFecha(mes_cita, agno_cita, citasMedicas);
        citasMedicas >> dni_Paciente >> descuento;
        leerHora(hora_i, min_i, seg_i, citasMedicas);
        leerHora(hora_fin, min_fin, seg_fin, citasMedicas);
        tiempoCita = tiempoTranscurrido(hora_i, min_i, seg_i, hora_fin, min_fin, seg_fin);
        citasMedicas >> codMedico;
        if (tiempoCita <= tiempoMax)
        {

        }
        else
        {
            irASiguiente(citasMedicas);
        }
    }
    */
    return 0;
}