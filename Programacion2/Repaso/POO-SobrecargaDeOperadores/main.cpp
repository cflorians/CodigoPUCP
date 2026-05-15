#include <iostream>
#include <fstream>
using namespace std;

#include "Bibliotecas/Funciones.h"
#include "Bibliotecas/Cadena.h"

int main() {
    
    ifstream arch("Archivo/prueba.txt");
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }

    Cadena cadenas[10];
    int cantNombres = 0;
    char apellido1[50];
    char apellido2[50];
    char nombre[50];
    while (true) {
        arch >> apellido1;
        if (arch.eof()) break;
        while (arch.peek() == ' ') arch.get();
        arch >> apellido2;
        while (arch.peek() == ' ') arch.get();
        arch >> nombre;
        cadenas[cantNombres] = apellido1;
        cadenas[cantNombres].append(" ");
        cadenas[cantNombres].append(apellido2);
        cadenas[cantNombres].append(" ");
        cadenas[cantNombres].append(nombre);
        cantNombres++;
    }

    ordenar(cadenas, cantNombres);

    for (int i = 0; i < cantNombres; i++) {
        cadenas[i].print();
    }

    return 0;
}
