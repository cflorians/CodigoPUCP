//
// Created by carlo on 28/09/2025.
//
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "FuncionesAdicionales.h"

void procesarMedicos(int* arrCodMed,double* arrTarifaMed,int& cantMed)
{
    char c;

    ifstream arch("ArchivosDeDatos/Medicos.txt", ios::in);
    if (not arch.is_open())
    {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }

    cantMed = 0;

    while (true)
    {
        arch >> arrCodMed[cantMed];
        if (arch.eof()) break;

        arch >> c;
        ignorarCaracteresHasta(arch, '/');
        arch >> c;
        ignorarCaracteresHasta(arch, ' ');

        arch >> arrTarifaMed[cantMed];

        cantMed++;
    }
}

void procesarMedicamentos(int* arrMedicinas,double*  arrPrecioMedicinas,int& cantMedicinas)
{
    char c;

    ifstream arch("ArchivosDeDatos/Medicinas.txt", ios::in);
    if (not arch.is_open())
    {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }

    cantMedicinas = 0;

    while (true)
    {
        arch >> arrMedicinas[cantMedicinas];
        if (arch.eof()) break;

        arch >> c;
        ignorarCaracteresHasta(arch, ' ');

        arch >> arrPrecioMedicinas[cantMedicinas];

        cantMedicinas++;
    }
}

void ignorarCaracteresHasta(ifstream& arch,char limite)
{
    while (arch.get() != limite);
}

void mostrarEncabezado()
{
    ofstream reporte("ArchivosDeReporte/Reporte.txt", ios::out);
    if (not reporte.is_open())
    {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }

    reporte << setw(80) <<"EMPRESA DE SALUD S.A." << endl;
    separadorCaracter(140, '=', reporte);
    reporte << setw(82) <<"REGISTRO DE CITAS MEDICAS" << endl;
    separadorCaracter(140, '=', reporte);
}

void separadorCaracter(int ancho, char c, ofstream& salida)
{
    salida << setfill(c);
    salida << setw(ancho) << c << endl;
    salida << setfill(' ');
}

void procesarCitaMedica(int* arrCodMed,double* arrTarifaMed, int numMedico)
{
    ofstream reporte("ArchivosDeReporte/Reporte.txt", ios::app);
    if (not reporte.is_open())
    {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }

    reporte << "Codigo del medico: " << arrCodMed[numMedico] << endl;
    reporte << "Nombre del medico: ";
    buscarNombreMedico(numMedico, reporte);
    reporte << "Especialidad:" << setw(6) << ' ';
    buscarEspecialidadMedico(numMedico, reporte);
    reporte << "Tarifa: " << setw(11) << ' ' << arrTarifaMed[numMedico] << endl;
    separadorCaracter(140, '-', reporte);
}

void buscarNombreMedico(int numMedico, ofstream& salida)
{
    int i=0;
    char c;

    ifstream arch("ArchivosDeDatos/Medicos.txt", ios::in);
    if (not arch.is_open())
    {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }

    for (i = 0; i<numMedico; i++)
    {
        ignorarCaracteresHasta(arch, '\n');
    }

    ignorarCaracteresHasta(arch, '/');
    while (arch.peek() != '/')
    {
        arch.get(c);
        salida << c;
    }
    salida << endl;
    arch.get();
}

void buscarEspecialidadMedico(int numMedico, ofstream& salida)
{
    int i=0;
    char c;

    ifstream arch("ArchivosDeDatos/Medicos.txt", ios::in);
    if (not arch.is_open())
    {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }

    for (i = 0; i<numMedico; i++)
    {
        ignorarCaracteresHasta(arch, '\n');
    }

    ignorarCaracteresHasta(arch, '/');
    arch.get();
    ignorarCaracteresHasta(arch, '/');

    while (arch.peek() == ' ')
    {
        arch.get();
    }

    while (arch.peek() != ' ')
    {
        arch.get(c);
        salida << c;
    }
    salida << endl;
}

void procesarCitaPaciente(int* arrCodMed,int* arrMedicinas, double* arrPrecioMedicinas, int numMedico, int cantMedicinas)
{
    //fecha dni descuento horaInicio horaFin medicoResponsable medicamento cantidad
    int dia, mes, anio, dni, codMedicoActual, medicamentos;
    double descuento, precioMedicina;
    int hhIni, mmIni, ssIni;
    int hhFin, mmFin, ssFin;
    int codMedicina, cantidad;
    char c;

    ifstream arch("ArchivosDeDatos/CitasMedicas.txt", ios::in);
    if (not arch.is_open())
    {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    ofstream reporte("ArchivosDeReporte/Reporte.txt", ios::app);
    if (not reporte.is_open())
    {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }

    while (true)
    {
        arch >> dia >> c >> mes >> c >> anio;
        arch >> dni;
        arch >> descuento;
        arch >> hhIni >> c >> mmIni >> c >> ssIni;
        arch >> hhFin >> c >> mmFin >> c >> ssFin;
        arch >> codMedicoActual;

        if (codMedicoActual == arrCodMed[numMedico])
        {
            reporte << "Fecha" << setw(15) << "Paciente" << setw(15) << "Inicio" << setw(12) << "Fin" << setw(15) << "Duracion"
                    << setw(25) << "% de descuento por seguro" << setw(18) << "Pago por cita" << endl;
            separadorCaracter(140, '-', reporte);
            mostrarFecha(dia, mes, anio, reporte);
            reporte << setw(10) << dni;
            reporte << setw(2) << ' ';
            mostrarHora(hhIni, mmIni, ssIni, reporte);
            reporte << setw(2) << ' ';
            mostrarHora(hhFin, mmFin, ssFin, reporte);


            reporte << "Medicinas Recetadas:" << endl;

            while (arch.peek() != '\n')
            {
                arch >> codMedicina >> cantidad;


                buscarPrecioMedicina(arrMedicinas, arrPrecioMedicinas, codMedicina, cantMedicinas, precioMedicina);

            }

            break;
        }
        else
        {
            ignorarCaracteresHasta(arch, '\n');
        }
    }
}

void buscarPrecioMedicina(int* arrMedicinas, double* arrPrecioMedicinas, int medicinaBuscada, int cantMedicinas, double& precioMedicina)
{
    int i=0, j=0;
    char c;
    ifstream arch("ArchivosDeDatos/Medicinas.txt", ios::in);
    ofstream reporte("ArchivosDeReporte/Reporte.txt", ios::app);

    for (i = 0; i<cantMedicinas; i++)
    {
        if (arrMedicinas[i] == medicinaBuscada)
        {
            precioMedicina=arrPrecioMedicinas[i];
            break;
        }
    }

    for (j = 0; j<i; j++)
    {
        ignorarCaracteresHasta(arch, '\n');
    }

    while (arch.peek() != ' ') arch.get();

    while (arch.get() == ' ');

    while (arch.peek() != ' ')
    {
        arch.get(c);
        if (c == '_')
        {
            c = ' ';
        }
        reporte << c;
    }
    reporte << endl;
}

void mostrarFecha(int dia,int mes,int anio,ofstream& reporte)
{
    reporte << setfill('0');
    reporte << setw(2) << dia << '/' << setw(2) << mes << '/' << anio;
    reporte << setfill(' ');
}

void mostrarHora(int hh, int mm, int ss,ofstream& reporte)
{
    reporte << setfill('0');
    reporte << setw(2) << hh << ':' << setw(2) << mm << ':' << setw(2) << ss;
    reporte << setfill(' ');
}