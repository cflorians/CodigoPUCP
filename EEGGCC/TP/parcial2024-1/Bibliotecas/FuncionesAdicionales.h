//
// Created by carlo on 10/13/2025.
//

#ifndef PARCIAL2024_1_FUNCIONESADICIONALES_H
#define PARCIAL2024_1_FUNCIONESADICIONALES_H

void abrirArchivo(ifstream& arch, const char* nombre);
void abrirArchivo(ofstream& arch, const char* nombre);
void saltarTextoHasta(ifstream& arch, char limitador);
void cargarDatosPacientes(ifstream& arch, int* dni, int* distrito, int* nacimiento, double* descuento, int& cantPacientes);
void cargarDatosMedicinas(ifstream& arch, int* medicina, double* precio, int& cantMedicinas);
void emitirReporteSimple(ofstream& arch, int* dni, int* distrito, int* nacimiento, double* descuento, int cantPacientes, int* medicina, double* precio, int cantMedicinas);

#endif //PARCIAL2024_1_FUNCIONESADICIONALES_H