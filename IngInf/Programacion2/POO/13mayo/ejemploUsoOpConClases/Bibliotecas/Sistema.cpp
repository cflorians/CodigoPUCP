#include <fstream>
#include <iostream>
using namespace std;

#include "Sistema.h"
Sistema::Sistema() {
    vehiculos = nullptr;
    numVehiculos = 0;
}

Sistema::~Sistema() {
    if (vehiculos != nullptr) delete[] vehiculos;
}

void Sistema::operator<<(const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    Vehiculo temp[20];
    int cant = 0;

    while (true) {
        arch >> temp[cant];
        if (arch.eof()) break;
        cant++;
    }

    vehiculos = new Vehiculo[cant];
    for (int i = 0; i < cant; i++) {
        vehiculos[i] = temp[i];
    }
    numVehiculos = cant;
}

ofstream& Sistema::operator>>(const char* nombArch) {
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    for (int i = 0; i < numVehiculos; i++) {
        arch << vehiculos[i];
    }

    return arch;
}

void Sistema::operator<(const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }
    char* marca, *modelo;
    int anno, posVehiculo;

    while (true) {
        marca = leerCadena(arch);
        if (arch.eof()) break;
        modelo = leerCadena(arch);
        arch >> anno;
        arch.get();
        posVehiculo = buscarVehiculo(marca,modelo,anno,vehiculos,numVehiculos);
        while (true) {
            Accesorio accesorio;
            char nombre[8];
            arch.get(nombre, 8, ',');
            accesorio.setNombre(nombre);
            accesorio.setTipo(EXTERIOR);
            if (posVehiculo != -1) {
                
            }
        }
    }
}
