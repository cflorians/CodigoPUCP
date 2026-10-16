//
// Created by carlo on 18/09/2025.
//

#ifndef LAB3_FUNCIONESADICIONALES_H
#define LAB3_FUNCIONESADICIONALES_H
#include <fstream>
using namespace std;

void leerTexto(ifstream &entrada, ofstream &salida);
void saltarEspacios(ifstream &entrada);
void obtenerDnis(int codPais, int &dni, int &edad, ifstream &entrada, ofstream &salida);
void buscarPersona(int dni, int &dia, int &mes, int &agno, ifstream &entrada, ofstream &salida);

#endif //LAB3_FUNCIONESADICIONALES_H