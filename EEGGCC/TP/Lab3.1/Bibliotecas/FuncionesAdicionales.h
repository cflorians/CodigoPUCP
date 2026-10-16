//
// Created by carlo on 21/09/2025.
//

#ifndef LAB3_1_FUNCIONESADICIONALES_H
#define LAB3_1_FUNCIONESADICIONALES_H
#include <fstream>
using namespace std;

void separadorCaracter(char caracter, ofstream &salida);
void leerFecha(int &mes, int &agno, ifstream &entrada);
void leerHora(int &hora, int &min, int &seg, ifstream &entrada);
int tiempoTranscurrido(int hora1, int min1, int seg1, int hora2, int min2, int seg2);
void irASiguiente(ifstream &entrada);
void mostrarNombre(istream& medicos,ofstream& reporte);
void procesarMedicos(int &codigo, double &tarifa, ifstream &medicos, ofstream &reporte);
void mostrarEspecialidad(istream& medicos,ofstream& reporte);
void procesarPaciente(int codigo,int tarifa, ifstream &citas, ofstream &reporte);
void mostrarFecha(int dia, int mes, int agno, ofstream &salida);
void mostrarHora(int hora, int min, int seg, ofstream &salida);
void segAhoras(int &hora, int &min, int &seg, int total);
void procesarMedicina(int codMed, int cantidad, double descuento, ofstream &reporte);

#endif //LAB3_1_FUNCIONESADICIONALES_H