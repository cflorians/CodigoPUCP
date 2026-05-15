#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "Estructuras.h"
using namespace std;
#include "FuncionesAdicionales.h"

void leerInfracciones(struct TablaDeInfracciones *arrTablaDeInfracciones, int& cantInfracciones) {
    ifstream arch("ArchivosDeDatos/TablaDeInfracciones_Lab08.csv", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo de infracciones" << endl;
        exit(1);
    }

    char codigo[10];
    double multa;
    char descripcion[200];

    // L3001,214.55,Dejar mal estacionado el vehiculo en lugares permitidos.
    cantInfracciones = 0;
    while (true) {
        arch.getline(codigo, 10, ',');
        arch >> multa;
        arch.ignore();
        arch.getline(descripcion, 200, '\n');

        toMayus(descripcion);

        arrTablaDeInfracciones[cantInfracciones].codigo = insertarChar(codigo);
        arrTablaDeInfracciones[cantInfracciones].descripcion = insertarChar(descripcion);
        arrTablaDeInfracciones[cantInfracciones].multa = multa;
        cantInfracciones++;
        if (arch.peek() == EOF) break;
    }
}

char* insertarChar(char* cadena) {
    char* nueva = new char[strlen(cadena) + 1];
    strcpy(nueva, cadena);
    return nueva;
}

void toMayus(char* cadena) {
    for (int i = 0; cadena[i] ; i++) {
        if ('a' <= cadena[i] and cadena[i] <= 'z') cadena[i] -= 'a'-'A';
    }
}

void leerEmpresas(struct EmpresasRegistradas *arrEmpresasRegistradas, int& cantEmpresas) {
    ifstream arch("ArchivosDeDatos/EmpresasRegistradas_Lab08.csv", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo de empresas" << endl;
        exit(1);
    }

    int dni;
    char nombre[50];
    char distrito[30];

    // 79672079,contreras chang johana cinthia,Chorrillos
    cantEmpresas = 0;
    while (arch >> dni) {
        arch.ignore();
        arch.getline(nombre, 50, ',');
        arch.getline(distrito, 30, '\n');

        toMayus(nombre);
        toMayus(distrito);

        arrEmpresasRegistradas[cantEmpresas].distrito = insertarChar(distrito);
        arrEmpresasRegistradas[cantEmpresas].nombre = insertarChar(nombre);
        arrEmpresasRegistradas[cantEmpresas].dni = dni;
        cantEmpresas++;
    }
}

void leerPlacas(struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresas) {
    ifstream arch("ArchivosDeDatos/PlacasRegistradas_Lab08.txt", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo de placas" << endl;
        exit(1);
    }

    char placa[10];
    int dni, pos, posPlaca;

    // 12443643      M421-807
    while (arch >> dni >> placa) {
        pos = buscarPlaca(dni, arrEmpresasRegistradas, cantEmpresas);
        if (pos != -1) {
            posPlaca = arrEmpresasRegistradas[pos].numPlacas;
            arrEmpresasRegistradas[pos].placas[posPlaca] = insertarChar(placa);
            arrEmpresasRegistradas[pos].numPlacas++;
        }
    }
}

int buscarPlaca(int dniBuscado,const struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresas) {
    for (int i = 0; i < cantEmpresas; i++) {
        if (arrEmpresasRegistradas[i].dni == dniBuscado) return i;
    }
    return -1;
}

void leerInfraccionesCometidas(struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresas,
                                struct TablaDeInfracciones *arrTablaDeInfracciones, int cantInfracciones) {
    ifstream arch("ArchivosDeDatos/InfraccionesCometidas_Lab08.csv", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo de infracciones" << endl;
        exit(1);
    }

    // 23/7/2023,P474-593,G2060,P,22/8/2023
    int dd, mm ,aa, ddp, mmp, aap;
    char placa[10];
    char codigo[10];
    char condPago, c;

    while (arch >> dd >> c >> mm >> c >> aa) {
        condPago = 'N';
        arch.ignore();
        arch.getline(placa, 10, ',');
        arch.getline(codigo, 10, ',');
        arch.get(condPago);
        if (condPago == 'P') {
            arch.ignore();
            arch >> ddp >> c >> mmp >> c >> aap;
        }

        for (int i=0; i < cantEmpresas; i++) {
            for (int j=0; j < arrEmpresasRegistradas[i].numPlacas; j++) {
                if (placa == arrEmpresasRegistradas[i].placas[j]) {
                    asignarFecha(arrEmpresasRegistradas, dd, mm, aa, i);
                    arrEmpresasRegistradas[i].totalMultas += buscarMulta(codigo, arrTablaDeInfracciones, cantInfracciones);
                    arrEmpresasRegistradas[i].
                }
            }
        }
    }
}

void asignarFecha(struct EmpresasRegistradas *arrEmpresasRegistradas, int dd, int mm, int aa, int pos) {
    arrEmpresasRegistradas[pos].fechaDeInfraccion.dd = dd;
    arrEmpresasRegistradas[pos].fechaDeInfraccion.mm = mm;
    arrEmpresasRegistradas[pos].fechaDeInfraccion.aa = aa;
    arrEmpresasRegistradas[pos].fechaDeInfraccion.fecha = aa*10000 + mm*100 + dd;
}

double buscarMulta(char* codigo, struct TablaDeInfracciones *arrTablaDeInfracciones, int cantInfracciones) {
    for (int i = 0; i < cantInfracciones; i++) {
        if (strcmp(codigo, arrTablaDeInfracciones[i].codigo)) return arrTablaDeInfracciones[i].multa;
    }
    return -1;
}