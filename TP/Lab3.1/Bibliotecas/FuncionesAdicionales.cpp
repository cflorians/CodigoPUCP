//
// Created by carlo on 21/09/2025.
//

#include "FuncionesAdicionales.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void separadorCaracter(char caracter, ofstream &salida)
{
    salida << setfill(caracter);
    salida << setw(120) << caracter << endl;
    salida << setfill(' ');
}

void procesarMedicos(int &codigo, double &tarifa, ifstream &medicos, ofstream &reporte)
{
    ifstream citas("ArchivosDeDatos/CitasMedicas.txt", ios::in);

    medicos >> codigo;
    reporte << "Codigo del medico: " << codigo << endl;

    reporte << "Nombre del medico: ";
    mostrarNombre(medicos, reporte);
    reporte << endl;

    reporte << "Especialidad: " << setw(5) << ' ';
    mostrarEspecialidad(medicos, reporte);
    reporte << endl;

    medicos >> tarifa;
    reporte << "Tarifa: " << setw(11) << ' ' << tarifa << endl;

    reporte << "PACIENTES ATENDIDOS" << endl;
    separadorCaracter('-', reporte);
    reporte << "Fecha" << setw(15) << "Paciente" << setw(11) << "Inicio" << setw(11) << "Fin" << setw(15)
            << "Duracion" << setw(30) << "% de descuento por Seguro" << setw(20) << "Pago por cita" << endl;
    separadorCaracter('-', reporte);

    //buscar pacientes
    procesarPaciente(codigo, tarifa, citas, reporte);

}

void procesarPaciente(int codigo,int tarifa, ifstream &citas, ofstream &reporte)
{

    int tiempoMax = 2*3600 + 31*60 +25;
    int dia_cita, mes_cita, agno_cita, dni_Paciente, tiempoCita;
    int codActual, codMedicina, cantidadMedicina;
    int hora_i, min_i, seg_i;
    int hora_fin, min_fin, seg_fin;
    char c;
    int hh_dur, min_dur, seg_dur;
    double descuento, pago;

    while (citas >> dia_cita)
    {
        leerFecha(mes_cita, agno_cita, citas);
        citas >> dni_Paciente >> descuento;
        leerHora(hora_i, min_i, seg_i, citas);
        leerHora(hora_fin, min_fin, seg_fin, citas);
        tiempoCita = tiempoTranscurrido(hora_i, min_i, seg_i, hora_fin, min_fin, seg_fin);
        citas >> codActual;
        if (tiempoCita <= tiempoMax and codigo == codActual)
        {
            mostrarFecha(dia_cita, mes_cita, agno_cita, reporte);
            reporte << setw(2) << ' ' << dni_Paciente;

            reporte << setw(4) << ' ';
            mostrarHora(hora_i, min_i, seg_i, reporte);

            reporte << setw(5) << ' ';
            mostrarHora(hora_fin, min_fin, seg_fin, reporte);

            segAhoras(hh_dur, min_dur, seg_dur, tiempoCita);
            reporte << setw(4) << ' ';
            mostrarHora(hh_dur, min_dur, seg_dur, reporte);

            reporte << setw(20) << fixed << setprecision(2) << descuento << '%';

            pago = tarifa - (tarifa * descuento/100);
            reporte << setw(26) << fixed << setprecision(2) << pago << endl;

            reporte << "Medicinas recetadas: " << endl;
            reporte << setw(23) << ' ' << "No." << setw(10) << "Codigo" << setw(18) << "Descripción"
                    << setw(35) << "Cantidad" << setw(15) << "Precio" << setw(10) << "Pago" << endl;


            while (citas.get(c) and c != '\n')
            {
                citas >> codMedicina >> cantidadMedicia;
                procesarMedicina(codMedicina, cantidadMedicina, descuento, reporte);
            }
        }
        else
        {
            irASiguiente(citas);
        }
    }
}

void procesarMedicina(int codMed, int cantidad, double descuento, ofstream &reporte)
{
    int medicinaActual, i=1;
    ifstream medicinas("ArchivosDeDatos/Medicinas.txt", ios::in);


    while (not medicinas.eof())
    {
        medicinas >> medicinaActual;
        if (medicinaActual == codMed)
        {
            reporte << setw(23) << ' ';
            reporte << setfill('0');
            reporte << setw(2) << i;
            reporte << setfill(' ');

            i++;
        }
        else
        {
            irASiguiente(medicinas);
        }
    }
    medicinas.close();
}

void mostrarNombre(istream& medicos,ofstream& reporte)
{
    char c;
    while (medicos.get(c) and c == ' ')
    {
    }
    while (medicos.peek() != '/')
    {
        medicos.get(c);
        if (c >= 'a' and c<='z')
        {
            c -= 'a';
        }
        reporte << c;
    }
}

void mostrarEspecialidad(istream& medicos,ofstream& reporte)
{
    char c;
    while (medicos.peek() == ' ' or medicos.peek() == '/')
    {
        medicos.get(c);
    }
    while (medicos.peek() != ' ')
    {
        medicos.get(c);
        reporte << c;
    }
}

void leerFecha(int &mes, int &agno, ifstream &entrada)
{
    char caracter;
    entrada >> caracter >> mes >> caracter >> agno;
}

void leerHora(int &hora, int &min, int &seg, ifstream &entrada)
{
    char caracter;
    entrada >> hora >> caracter >> min >> caracter >> seg;
}

int tiempoTranscurrido(int hora1, int min1, int seg1, int hora2, int min2, int seg2)
{
    int segundosIniciales, segundosFinales;
    segundosIniciales = hora1*3600 + min1*60 + seg1;
    segundosFinales = hora2*3600 + min2*60 + seg2;
    return segundosFinales - segundosIniciales;
}

void irASiguiente(ifstream &entrada)
{
    while (entrada.peek() != '\n' or entrada.eof())
    {
        entrada.get();
    }
}

void mostrarFecha(int dia, int mes, int agno, ofstream &salida)
{
    salida << setfill('0');
    salida << setw(2) << dia << "/" << setw(2) << mes << "/" << agno;
    salida << setfill(' ');
}

void mostrarHora(int hora, int min, int seg, ofstream &salida)
{
    salida << setfill('0');
    salida << setw(2) << hora << ":" << setw(2) << min << ":" << setw(2) << seg;
    salida << setfill(' ');
}

void segAhoras(int &hora, int &min, int &seg, int total)
{
    hora = total/3600;
    seg = (total%3600)/60;
    min = total%60;
}