#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "FuncionesAdicionales.h"

void leerRepartidores(int* dniRepartidor, int* codDistRepartidor, int& cantRepartidores, char** nombreRepartidor, char** vehiculoRepartidor, char** nomDistRepartidor) {
    // 54805724   Vizcardo_Sinche_Maribel     Motocicleta      4826   Santa_Rosa
    // dni         nombre                     vehiculo        codDist  nomDist
    int dni, codigo;
    char nombre[100]{}, vehiculo[20]{}, nomDist[50]{};

    ifstream arch("ArchivosDeDatos/lab7_Repartidores.txt", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir archivo de repartidores." << endl;
        exit(1);
    }

    cantRepartidores = 0;
    while (arch >> dni) {
        arch >> nombre >> vehiculo >> codigo >> nomDist;

        eliminarGuiones(nombre);
        eliminarGuiones(nomDist);

        toMayus(vehiculo);

        dniRepartidor[cantRepartidores] = dni;
        codDistRepartidor[cantRepartidores] = codigo;
        nombreRepartidor[cantRepartidores] = asiginarChar(nombre);
        vehiculoRepartidor[cantRepartidores] = asiginarChar(vehiculo);
        nomDistRepartidor[cantRepartidores] = asiginarChar(nomDist);

        // cout << dniRepartidor[cantRepartidores] << "---" << nombreRepartidor[cantRepartidores] << "---" << vehiculoRepartidor[cantRepartidores]
        //      << "---" << codDistRepartidor[cantRepartidores] << "---" << nomDistRepartidor[cantRepartidores] << endl;

        cantRepartidores++;
    }
}

void eliminarGuiones(char* cadena) {
    for (int i=0; cadena[i] ; i++) {
        if (cadena[i] == '_') cadena[i] = ' ';
    }
}
void toMayus(char* cadena) {
    for (int i=0; cadena[i] ; i++) {
        if ('a' <= cadena[i] and cadena[i] <= 'z') cadena[i] -= 'a' - 'A';
    }
}

char* asiginarChar(char* cadena) {
    char *nueva;
    nueva = new char [strlen(cadena) + 1];
    strcpy(nueva, cadena);
    return nueva;
}

void leerPlatosOfrecidos(int* codigoPlato, double* precioPlato, double* descuentoPlato, char** nombrePlato, char** categoriaPlato, int& cantPlatos) {
    // 11283   2_BOLAS_DE_HELADO      14.90   POSTRES    17.72%
    // cod       nombre               precio  categoria   descuento
    int cod;
    double precio;
    char nombre[50]{}, categoria[20]{}, descuento[10]{};

    ifstream arch("ArchivosDeDatos/lab7_PlatosOfrecidos.txt", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir archivo de platos ofrecidos." << endl;
        exit(1);
    }

    cantPlatos = 0;
    while (arch >> cod) {
        descuentoPlato[cantPlatos] = 0;
        arch >> nombre >> precio >> categoria;
        if (arch.peek() != '\n') {
            arch >> descuento;
            descuentoPlato[cantPlatos] = atod(descuento)/100;
        }

        eliminarGuiones(nombre);

        codigoPlato[cantPlatos] = cod;
        precioPlato[cantPlatos] = precio;
        nombrePlato[cantPlatos] = asiginarChar(nombre);
        categoriaPlato[cantPlatos] = asiginarChar(categoria);

        // cout << codigoPlato[cantPlatos] << "---" << nombrePlato[cantPlatos] << "---" << precioPlato[cantPlatos] << "---" <<
        //         categoriaPlato[cantPlatos] << "---" << descuentoPlato[cantPlatos] << endl;

        cantPlatos++;
    }
}

double atod(char* cadena) {
    double parteDecimal=0;
    int parteInt=0;
    bool decimales = false;
    for (int i=0; cadena[i] != '%' ; i++) {
        if (cadena[i] == '.') decimales = true;
        if (not decimales and cadena[i] != '.') parteInt = parteInt*10 + cadena[i] - '0';
        if (decimales and cadena[i] != '.') parteDecimal = parteDecimal*10 + cadena[i] - '0';
    }
    do {
        parteDecimal /= 10;
    }   while (parteDecimal > 1);
    return parteInt+parteDecimal;
}

void verificarAsignacion(int* dniRepartidores,int* codDistRepartidores,int cantRepartidores,char** nombreRepartidores,char** vehiculoRepartidores,
                         char** nomDistRepartidores,int* codPlatos,double* precioPlatos,double* descuentoPlatos,char** nombrePlatos,char** categoriaPlatos,
                         int cantPlatos, const char* archivo) {
    ofstream reporte(archivo, ios::out);

    reporte << "DNI" << setw(40) << "NOMBRE" << setw(39) << "VEHICULO" << setw(36) << "DISTRITO Y NOMBRE DE DISTRITO" << endl;
    for (int i = 0; i < cantRepartidores; i++) {
        reporte << dniRepartidores[i] << setw(50) << nombreRepartidores[i] << setw(25) << vehiculoRepartidores[i] << setw(10) << codDistRepartidores[i]
                << setw(25) << nomDistRepartidores[i] << endl;
    }

    reporte << endl <<"CODIGO" << setw(35) << "PLATO" << setw(26) << "PRECIO" << setw(14) << "CATEGORIA" << setw(11) << "DESCUENTO" << endl;
    for (int i = 0; i < cantPlatos; i++) {
        reporte << codPlatos[i] << setw(50) << nombrePlatos[i] << setw(11) << precioPlatos[i] << setw(15) << categoriaPlatos[i]
                << setw(10) << descuentoPlatos[i] << endl;
    }

}

void ordenarPorNombre(int* dniRepartidor, int* codDistRepartidor, int cantRepartidores, char** nombreRepartidor, char** vehiculoRepartidor, char** nomDistRepartidor) {
    for (int i = 0; i < cantRepartidores-1; i++) {
        for (int j = i+1; j < cantRepartidores; j++) {
            if (strcmp(nombreRepartidor[i], nombreRepartidor[j]) > 0) {
                // nombreRepartidor[i] mayor que nombreRepartidor[j]
                // por lo que debemos intercambiar el orden
                intercambiarDatos(dniRepartidor, i, j);
                intercambiarDatos(codDistRepartidor, i, j);
                intercambiarDatos(nombreRepartidor, i, j);
                intercambiarDatos(vehiculoRepartidor, i, j);
                intercambiarDatos(nomDistRepartidor, i, j);
            }
        }
    }
}

void intercambiarDatos(int* arr1, int pos1, int pos2) {
    int temp= arr1[pos1];
    arr1[pos1] = arr1[pos2];
    arr1[pos2] = temp;
}

void intercambiarDatos(char** arr, int pos1, int pos2) {
    char* temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

void leerRepartos(int* codDistRepartidor, char** vehiculoRepartidor, int* totalPlatosRepartidor, double* montoTotalPorPlato,
                  double* descuentoPorPlatos, double* descuentoPorCliente, double* pagoARepartidor, double* totalIngresadoRepartidor,
                  double* montoVendidoPlato, double* decuentoPlato,double* descuentoAlCliente, double* totalIngresadoPlato, int cantRepartidores) {
    // 358019        93231760    7752           Bicicleta          S        19.47%       8   11471   7   77572
    // numPedido-  dniCliente- distCliente   vehiculoDeseado   condDesc    descuento    cant Plato
    int n, distrito, cantPlatos, codPlato;
    double descuento;
    char vehiculo[20]{}, descConPorcentaje[10]{}, condDesc;

    ifstream arch("ArchivosDeDatos/lab7_RepartosARealizar.txt", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir archivo de platos ofrecidos." << endl;
        exit(1);
    }

    while (arch >> n) {
        arch >> n >> distrito >> vehiculo >> condDesc;
        if (condDesc == 'S') {
            arch >> descConPorcentaje;
            descuento = atod(descConPorcentaje);
        }
        while (arch.peek()!='\n') {
            arch >> cantPlatos >> codPlato;

        }
    }
}