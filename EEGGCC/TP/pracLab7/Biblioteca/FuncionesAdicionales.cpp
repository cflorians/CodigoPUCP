#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "FuncionesAdicionales.h"

void toMayus(char *cadena) {
    for (int i = 0; cadena[i] ; i++) {
        if (cadena[i] <= 'z' and 'a'<= cadena[i]) cadena[i] -= 'a' - 'A';
    }
}

void ordenarPorNombre(char **cadena, int cantNombres) {
    for (int i = 0; i < cantNombres-1 ; i++) {
        for (int j=i+1; j < cantNombres ; j++) {
            if (strcmp(cadena[i],cadena[j]) > 0) {
                char *temp = cadena[i];
                cadena[i] = cadena[j];
                cadena[j] = temp;
            }
        }
    }
}

void concatenar(char* destino, const char* fuente) {
    int len = strlen(destino), i;

    for (i = 0; fuente[i] ; i++) {
        destino[len+i] = fuente[i];
    }
    destino[len + i] = 0;
}
