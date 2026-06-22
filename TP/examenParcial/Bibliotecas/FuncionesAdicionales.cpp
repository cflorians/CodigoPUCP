#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

#include "FuncionesAdicionales.h"

void abrirArch(ifstream& arch, const char* nombreArchivo) {
    arch.open(nombreArchivo, ios::in);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
}
void abrirArch(ofstream& arch, const char* nombreArchivo) {
    arch.open(nombreArchivo, ios::out);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
}

void emitirTitulo(ofstream& arch) {
    arch << setw(85) << "EMPRESA DE REPARTO A DOMICILIO TP S.A." << endl;
    arch << setw(75) << "CLIENTES POR ATENDER" << endl;
    separadorCaracter(arch, '=');
}

void separadorCaracter(ofstream& arch, char caracter) {
    arch << setfill(caracter);
    arch << setw(140) << caracter << endl;
    arch << setfill(' ');
}

void procesarCliente(ifstream& clientes,ifstream& platos,ifstream& repartidores,ifstream& repartos, ofstream& reporte, double& totalRecaudado,double& totalAPagar) {
    int dniCliente, codDist, longTexto;
    char tipoVehiculo, tieneDescuento;
    double descuento;
    //90367684   CORONEL CHUMPITAZ HELI]   8594   Villa_Maria_del_Triunfo   M   S   13.04%
    while (true) {
        clientes >> dniCliente;
        reporte << "CLIENTE: " << dniCliente << " - ";
        copiarTextoHasta(clientes, reporte, ']', longTexto);
        clientes >> codDist;
        reporte << setw(45-longTexto) << "DISTRITO:  ";
        copiarTextoHasta(clientes, reporte, ' ', longTexto);
        clientes >> ws >> tipoVehiculo;
        clientes >> ws >> tieneDescuento;
        reporte << setw(25-longTexto) << " ";
        mostrarTipoVehiculo(reporte, tipoVehiculo, longTexto);
        descuento = 0;
        if (tieneDescuento == 'S' or tieneDescuento == 's') {
            clientes >> descuento;
            clientes.get();
        }
        reporte << setw(25-longTexto) << "DESCUENTO: " << setw(6) << fixed << setprecision(2) << descuento << "%";
        reporte << endl;
        separadorCaracter(reporte, '-');
        if (clientes.eof()) break;
        procesarRepartos(platos, repartidores, repartos, reporte, dniCliente);
    }
    separadorCaracter(reporte,'=');
    reporte << "TOTAL RECAUDADO POR LOS PEDIDOS SOLICITADOS " << totalRecaudado << endl;
    reporte << "TOTAL A PAGAR A LOS REPARTIDORES " << totalRecaudado << endl;
    separadorCaracter(reporte,'=');
}

void procesarRepartos(ifstream& platos,ifstream& repartidores,ifstream& repartos, ofstream& reporte, int dniCliente) {
    //804501   71422479   3   39475   1   15760
    //numPedido   dni cantPlatos codPlato (repite)
    int dni, numPedido, cantPlatos, codPlato, cantPedidos=1;
    repartos.clear();
    repartos.seekg(0, ios::beg);

    while (repartos >> numPedido) {
        repartos >> dni;
        if (dni == dniCliente) {
            reporte << numPedido << endl;
            while (repartos >> cantPlatos) {
                repartos >> codPlato;

                buscarPlato(platos, reporte, codPlato, cantPlatos);
                if (repartos.peek() == '\n') break;
            }
        }
        else {
            while (repartos.get() != '\n');
        }
        if (repartos.eof()) break;
    }
}

void buscarPlato(ifstream& platos, ofstream& reporte, int codPlato,int cantPlatos) {
    //31796 ANTICUCHO DE CORAZON AL PLATO}   31.90   43   19.94%
    //codigo    descripcion                  precio cant  descuento
    int codigo, cant, longTexto;
    double precio, descuento, valor, subtotal, cantDescontada;
    bool platoNoEncontrado = true;
    platos.clear();
    platos.seekg(0, ios::beg);
    platos >> valor;
    while (true) {
        codigo = valor;
        if (codigo == codPlato) {
            reporte << codigo << '-';
            copiarTextoHasta(platos, reporte, '}', longTexto);
            platos >> precio >> cant;
            platoNoEncontrado = false;
            platos >> valor;
            descuento = 0;
            if (valor <= 100) {
                descuento = valor;
                platos.get();
            }
            cantDescontada = (precio*cantPlatos*(descuento/100));
            subtotal = precio*cantPlatos - cantDescontada;
            reporte << setw(10) << cantPlatos << setw(10) << precio << setw(10) << subtotal << setw(10)
                    << fixed << setprecision(2) << descuento << "% - " << fixed << setprecision(2) << cantDescontada << endl;
        }
        else {
            while (platos.get() != '\n');
            platos >> valor;
        }
        if (platos.eof() or platoNoEncontrado) break;
    }
}

void copiarTextoHasta(ifstream& arch, ofstream& salida, char limitador, int& longTexto) {
    char c;
    longTexto = 0;
    arch >> ws;
    while (arch.get(c) and c!=limitador) {
        if (c == '_') c = ' ';
        salida << c;
        longTexto++;
    }
}

void mostrarTipoVehiculo(ofstream& reporte,char tipoVehiculo, int& longTexto) {
    reporte << "TIPO DE VEHICULO: ";
    if (tipoVehiculo == 'M') {
        reporte << "Motocicleta";
        longTexto = 11;
    }
    else if (tipoVehiculo == 'B') {
        reporte << "Bicicleta";
        longTexto = 9;
    }
}
