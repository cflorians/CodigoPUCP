#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
#include "MinisterioDeTransporte.h"


MinisterioDeTransporte::MinisterioDeTransporte() {
    infracciones = nullptr;
    numInf = 0;
    numEmp = 0;
}
MinisterioDeTransporte::~MinisterioDeTransporte() {
    if (infracciones) delete [] infracciones;
    numInf = 0;
    numEmp = 0;
}
void MinisterioDeTransporte::operator<(const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }
    // 3001,214.55,Leve,Dejar mal estacionado el vehiculo en lugares permitidos.
    Infraccion temp[150];
    int cantDatos = 0;
    while (true) {
        arch >> temp[cantDatos];
        if (arch.eof()) break;
        cantDatos++;
    }
    infracciones = new Infraccion[cantDatos];
    for (int i = 0; i < cantDatos; i++) {
        infracciones[i] = temp[i];
    }
    numInf = cantDatos;
}

void MinisterioDeTransporte::operator<=(const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }
    int cantEmpresas = 0;

    while (true) {
        arch >> empresas[cantEmpresas];
        if (arch.eof()) break;
        cantEmpresas++;
    }
    numEmp = cantEmpresas;
}

void MinisterioDeTransporte::operator<<=(const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }
    Multa aux;
    int posInfraccion, posEmpresa;
    char placa[20];

    while (true) {
        arch >> aux;
        if (arch.eof()) break;
        posInfraccion = buscarInfraccion(aux.getCodigoInfraccion());
        if (posInfraccion != -1) {
            aux.setMulta(infracciones[posInfraccion].getMulta());
            aux.getPlaca(placa);
            posEmpresa = buscarEmpresa(placa);
            if (posEmpresa != -1) {
                empresas[posEmpresa] += aux;
            }
        }
    }
}

int MinisterioDeTransporte::buscarInfraccion(int cod) const     {
    for (int i=0; i<numInf; i++) {
        if (infracciones[i].getCodigo() == cod) return i;
    }
    return -1;
}

int MinisterioDeTransporte::buscarEmpresa(const char* placa) const {
    for (int i=0; i<numEmp; i++) {
        for (int j=0; j<empresas[i].getNumPlacas(); j++) {
            char placaEmpresa[20];
            empresas[i].getPlacaI(placaEmpresa, j);
            if (strcmp(placaEmpresa, placa) == 0) return i;
        }
    }
    return -1;
}

void MinisterioDeTransporte::operator>>(const char* nombArch) const {
    ofstream arch(nombArch, ios::out);

    arch << "MINISTERIO DE TRANSPORTE" << endl;
    separador(arch, '=');
    arch << "TABLA DE INFRACCIONES" << endl;
    separador(arch, '-');
    arch << "CODIGO      MULTA        GRAVEDAD      DESCRIPCION"<< endl;
    for (int i=0; i<numInf; i++) {
        arch << infracciones[i];
    }
    separador(arch, '=');
    arch << "RELACION DE EMPRESAS CON INFRACCIONES DE TRANSITO" << endl;
    separador(arch, '-');
    arch << "DNI        NOMBRE         PLACAS DE SUS VEHICULOS" << endl;
    for (int i=0; i<numEmp; i++) {
        arch << empresas[i];
    }

}

void separador(ofstream& arch, char sep) {
    arch << setfill(sep);
    arch << setw(140) << sep << endl;
    arch << setfill(' ');
}

