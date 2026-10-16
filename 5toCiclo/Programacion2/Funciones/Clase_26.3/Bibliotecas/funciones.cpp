//
// Created by carlo on 3/26/2026.
//

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

#include "ListaPedidos.h"
#include "Pedido.h"

#include "funciones.h"


// leer todos los pedidos del archivo
void operator >> (ListaPedidos &lista, const char* nombreArchivo) {
    ifstream arch(nombreArchivo, ios::in);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << nombreArchivo << endl;
        exit(1);
    }

    Pedido pedido{};
    int np = 0;
    while (true) {
        arch >> pedido; // utilizamos la sobrecarga de un pedido
        lista.pedidos[np] = pedido;
        np++;
        if (arch.eof()) break;
    }
    lista.cantPedidos = np;
}

// leer solamente un pedido
void operator >> (ifstream& arch, Pedido& pedido) {
    static int idpedido = 10000;
    idpedido++;
    pedido.id = idpedido;

    arch.getline(pedido.cliente, 60 , ',');
    if (arch.eof()) return;
    arch.getline(pedido.producto, 60 , ',');
    arch >> pedido.cantidad;
    arch.get(); // lee la coma
    arch >> pedido.precio;
    arch.get(); // lee el salto de linea
}

void operator << (const char* nombreArch, ListaPedidos lista) {
    ofstream reporte(nombreArch, ios::out);

    for (int i = 0; i < lista.cantPedidos; i++) {
        reporte << lista.pedidos[i].id << "  " <<lista.pedidos[i].cliente << "  "
                << lista.pedidos[i].producto << "  " << lista.pedidos[i].cantidad
                << "  " << lista.pedidos[i].precio << endl;
    }
}