#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Funciones.h"

char* leerCadena(ifstream& arch, char limit) {
    char *cadenaExacta, cadena[100];
    arch.getline(cadena, 100, limit);
    cadenaExacta = new char[strlen(cadena) + 1];
    strcpy(cadenaExacta, cadena);
    return cadenaExacta;
}