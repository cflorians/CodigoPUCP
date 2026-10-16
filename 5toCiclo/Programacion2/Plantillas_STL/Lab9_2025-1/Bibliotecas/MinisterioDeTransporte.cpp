#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
using namespace std;

#include "Infraccion.h"
#include "Vehiculo.h"
#include "Multa.h"
#include "Empresa.h"

#include "MinisterioDeTransporte.h"

void MinisterioDeTransporte::cargaDeInfracciones(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    Infraccion infraccion;
    while (true) {
        arch >> infraccion; // Debemos hacer el operador
        if (arch.eof()) break;
        tablaInfracciones.push_back(infraccion);
    }
    tablaInfracciones.sort(); // Aqui debemos hacer el operador < para que sepa ordenar
}

void MinisterioDeTransporte::cargaEmpresas(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    Empresa empresa;
    while (true) {
        arch >> empresa;
        if (arch.eof()) break;
        listaEmpresas.push_back(empresa);
    }
    listaEmpresas.sort();
}

void MinisterioDeTransporte::cargaVehiculos(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    Vehiculo vehiculo;
    int dni;
    while (true) {
        arch >> dni;
        if (arch.eof()) break;
        arch.get();
        arch >> vehiculo;
        for (Empresa empresa : listaEmpresas) {
            if (empresa.getDni() == dni) {
                empresa.insertarVehiculo(vehiculo);
            }
        }
    }
}

void MinisterioDeTransporte::cargaInfraccionesCometidas(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    Multa multa;
    // 1/12/2020,G760-721,G2022,N
    while (true) {
        arch >> multa;
        if (arch.eof()) break;
        for (Empresa empresa : listaEmpresas) {
            // insertamos la multa en cada empresa
            
        }
    }

    // ordenamos las multas dentro de cada empresa
    // sort(listaEmpresas.begin(), listaEmpresas.end());
}

void MinisterioDeTransporte::reporteDeEmpresaConInfracciones(const char *nombArch) {
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }
}

void MinisterioDeTransporte::eliminaInfraccionesPagadas() {
}
