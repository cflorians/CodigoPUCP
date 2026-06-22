//
// Created by carlo on 10/24/2025.
//

#ifndef LAB6_2025_1_FUNCIONESADICIONALES_H
#define LAB6_2025_1_FUNCIONESADICIONALES_H

void leerTablaInfracciones(int* arrCodigoInfraccion, double* arrMultasInfraccion, int& cantInfracciones);
void irAsiguienteLinea(ifstream& arch);
int buscarPos(int* arrCodigoInfraccion,int codigo,int cantInfracciones);
void hacerEspacio(int* arrCodigoInfraccion, int cant, int pos);
void hacerEspacio(double* arrCodigoInfraccion, int cant, int pos);
void mostrarArreglo(int* arr, int cant);
void mostrarArreglo(double* arr, int cant);
void verificarCorrectoLlenadoDatos(int* arrCodigoInfraccion,double* arrMultasInfraccion,int cantInfracciones);

#endif //LAB6_2025_1_FUNCIONESADICIONALES_H