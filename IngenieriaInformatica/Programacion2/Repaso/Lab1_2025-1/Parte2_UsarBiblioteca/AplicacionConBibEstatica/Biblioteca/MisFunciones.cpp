#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "CadenaDeCaracteres.h"
#include "Funciones.h"
#include "MisFunciones.h"

void leerArchivo(ifstream& arch,int*& dni, struct CadenaDeCaracteres*& conductor, struct CadenaDeCaracteres*& placa) {
    int cantDatos = 0;
    int codigo;
    struct CadenaDeCaracteres nombreTemp[5];
    struct CadenaDeCaracteres nombreJunto;
    struct CadenaDeCaracteres placaTemp;
    int i=0;

    int dnis[125];
    struct CadenaDeCaracteres conductores[125];
    struct CadenaDeCaracteres placas[125];

    //12270502    CUEVA         FUENTES     CINTHIA   DELIA    129    P7T-999
    // DNI        NOMBRE                                      CODIGO   PLACA
    while (arch >> dnis[cantDatos]) {
        consumirEspacios(arch);
        for (i = 0; isalpha(arch.peek()) ;i++) {
            arch >> nombreTemp[i];
            consumirEspacios(arch);
        }
        juntarNombre(nombreJunto, nombreTemp, i);
        formatearNombre(nombreJunto);

        arch >> codigo;
        consumirEspacios(arch);
        arch >> placaTemp;

        !conductores[cantDatos];
        !placas[cantDatos];
        conductores[cantDatos] <= nombreJunto;
        placas[cantDatos] <= placaTemp;

        cantDatos++;
    }

    dni = new int [cantDatos+1]{};
    conductor = new CadenaDeCaracteres[cantDatos]{};
    placa = new CadenaDeCaracteres[cantDatos]{};
    for (i = 0; i < cantDatos; i++) {
        dni[i] = dnis[i];
        conductor[i] <= conductores[i];
        placa[i] <= placas[i];
    }
    dni[cantDatos] = 0;
}

void consumirEspacios(ifstream& arch) {
    while (arch.peek() == ' ') arch.get();
}

void juntarNombre(struct CadenaDeCaracteres& nombreJunto, struct CadenaDeCaracteres* temp, int cantidad) {
    !nombreJunto;
    nombreJunto <= temp[0];
    for (int i = 1; i < cantidad; i++) {
        nombreJunto += "_";
        nombreJunto += temp[i];
    }
}

void formatearNombre(struct CadenaDeCaracteres& nombre) {
    for (int i=0; i < nombre.longitud; i++) {

        if (nombre.cadena[i] == '_') i++;
        if (nombre.cadena[i - 1] == '_' or i == 0) nombre.cadena[i] = toupper(nombre.cadena[i]);
        else nombre.cadena[i] = tolower(nombre.cadena[i]);
    }
}

void emitirReporte(ofstream& arch,int* dni, struct CadenaDeCaracteres* conductor, struct CadenaDeCaracteres* placa) {
    arch << setw(50) << "REPORTE INFRACTORES DE TRANSITO" << endl;
    separador(arch, '=');
    arch << left << setw(10) << "DNI" << left << setw(39) <<"INFRACTOR" << "PLACA" << endl;
    separador(arch, '-');
    for (int i=0; dni[i]; i++) {
        arch << setw(10)<< dni[i];
        arch << conductor[i];
        arch << setw(39 - conductor[i].longitud) << " ";
        arch << placa[i];
        arch << endl;
    }
}

void separador(ofstream& arch, char separador) {
    arch << setfill(separador);
    arch << setw(70) << separador << endl;
    arch << setfill(' ');
}

while (true) {
    //
}