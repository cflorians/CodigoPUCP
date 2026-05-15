#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Estructuras.h"

#include "FuncionesAdicionales.h"

void leerEmpleados(struct Persona *empleados, int& cantEmpleados) {
    ifstream arch("ArchivosDeDatos/datos.csv", ios::in);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo de datos" << endl;
        exit(1);
    }

    int dni;
    char nombre[20];
    double sueldo;

    // 12345678,Ana Perez,2500.55
    cantEmpleados = 0;
    while (arch >> dni) {
        arch.ignore();
        arch.getline(nombre, 20, ',');
        arch >> sueldo;

        toMayus(nombre);

        empleados[cantEmpleados].dni = dni;
        empleados[cantEmpleados].nombre = insertarCadena(nombre);
        empleados[cantEmpleados].sueldo = sueldo;

        cantEmpleados++;
    }
}

void toMayus(char* cadena) {
    for (int i=0; cadena[i]; i++) {
        if ('a' <= cadena[i] and cadena[i] <= 'z') cadena[i] -= 'a' - 'A';
    }
}

char* insertarCadena(char* cadena) {
    char* nueva = new char[strlen(cadena) + 1];
    strcpy(nueva, cadena);
    return nueva;
}

void ordenarPorDni(struct Persona *empleados, int cantEmpleados) {
    struct Persona auxiliar;
    for (int i = 0; i < cantEmpleados-1; i++) {
        for (int j = i+1; j < cantEmpleados; j++) {
            if (empleados[i].dni > empleados[j].dni) {
                auxiliar = empleados[i];
                empleados[i] = empleados[j];
                empleados[j] = auxiliar;
            }
        }
    }
}

void ordenarPorSueldo(struct Persona *empleados, int cantEmpleados) {
    struct Persona auxiliar;
    for (int i = 0; i < cantEmpleados-1; i++) {
        for (int j = i+1; j < cantEmpleados; j++) {
            if (empleados[i].sueldo > empleados[j].sueldo) {
                auxiliar = empleados[i];
                empleados[i] = empleados[j];
                empleados[j] = auxiliar;
            }
        }
    }
}

void mostrar(const struct Persona *empleados, int cantEmpleados) {
    cout << setw(5) << "DNI" << setw(15) << "NOMBRE" << setw(20) << "SUELDO" << endl;
    for (int i = 0; i < cantEmpleados; i++) {
        cout << empleados[i].dni << setw(5) << " " << empleados[i].nombre << setw(27 - strlen(empleados[i].nombre))
             << fixed << setprecision(2) <<empleados[i].sueldo << endl;
    }
}