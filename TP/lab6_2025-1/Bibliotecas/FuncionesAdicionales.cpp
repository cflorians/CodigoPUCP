#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "FuncionesAdicionales.h"

void leerTablaInfracciones(int* arrCodigoInfraccion, double* arrMultasInfraccion, int& cantInfracciones) {
    ifstream arch("ArchivosDeDatos/TablaDeInfracciones_Lab06.txt", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }

    int codigo, pos;
    double precio;

    cantInfracciones = 0;
    while (arch >> codigo >> precio) {
        pos = buscarPos(arrCodigoInfraccion, codigo, cantInfracciones);
        hacerEspacio(arrCodigoInfraccion, cantInfracciones, pos);
        hacerEspacio(arrMultasInfraccion, cantInfracciones, pos);
        cantInfracciones++;
        arrCodigoInfraccion[pos] = codigo;
        arrMultasInfraccion[pos] = precio;
        irAsiguienteLinea(arch);
    }
}
void verificarCorrectoLlenadoDatos(int* arrCodigoInfraccion,double* arrMultasInfraccion,int cantInfracciones) {
    ofstream reporte("ArchivosDeReporte/PruebaTablaInf.txt", ios::out);
    reporte << "CODIGO" << setw(10) << "MULTA" << endl;
    for (int i = 0; i < cantInfracciones; i++) {
        reporte << arrCodigoInfraccion[i] << setw(13) << fixed << setprecision(2) << arrMultasInfraccion[i] << endl;
    }

}



void leerInfraccionesCometidas(int* arrDni, int* arrMasMultaAntigua, int* arrUltimaPendiente, int& cantDni,
                                double* arrTotalMultas, double* arrTotalPagadas, double* arrTotalPendientes) {
    ifstream arch("ArchivosDeDatos/InfraccionesCometidas_Lab06.txt", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }

    // 23/7/2023      P474-593      89941095     2060   P     22/8/2023
    // fecha cometió    placa         dni       codigo         fecha pago
    int n, letraPlaca, placa1, placa2, dni, codigoInf, dd, mm, aa;
    char c, condicionPago;
    bool pagada;

    while (true) {
        condicionPago = '0';
        pagada = false;
        arch >> n >> c >> n >> c >> n;
        arch >> ws >> letraPlaca >> placa1 >> placa2 >> dni >> codigoInf;
        arch >> ws;
        if (arch.get(condicionPago) and condicionPago == 'P') {
            pagada = true;
        }
    }

}

int buscarPos(int* arrCodigoInfraccion,int codigo,int cantInfracciones) {
    int i;
    for (i = 0; i < cantInfracciones; i++) {
        if (arrCodigoInfraccion[i] > codigo) {
            return i;
        }
    }
    return cantInfracciones;
}
void hacerEspacio(int* arrCodigoInfraccion, int cant, int pos) {
    for (int i = cant; i > pos; i--) {
        arrCodigoInfraccion[i] = arrCodigoInfraccion[i-1];
    }
}
void hacerEspacio(double* arrCodigoInfraccion, int cant, int pos) {
    for (int i = cant; i > pos; i--) {
        arrCodigoInfraccion[i] = arrCodigoInfraccion[i-1];
    }
}

void mostrarArreglo(int* arr, int cant) {
    for (int i = 0; i < cant; i++) {
        cout << arr[i] << " ";
    }
}
void mostrarArreglo(double* arr, int cant) {
    for (int i = 0; i < cant; i++) {
        cout << arr[i] << " ";
    }
}
void irAsiguienteLinea(ifstream& arch) {
    while (arch.get() != '\n');
}