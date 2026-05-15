#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "Funciones.h"
#include "Estructuras.h"

bool operator >> (ifstream& arch, struct Libro& libro) {
    // IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
    // codigo , titulo               , autor             ,stock, precio
    arch.getline(libro.codigo, 8, ',');
    arch.getline(libro.tiltulo, 80, ',');
    arch.getline(libro.autor, 60, ',');
    arch >> libro.stock;
    arch.get();
    arch >> libro.precio;
    arch.get();
    if (arch.eof()) return false;
    return true;
}

bool operator >> (ifstream& arch, struct Cliente& cliente) {
    // 54393647,Reyes Tang Edward
    arch >> cliente.dni;
    arch.get();
    arch.getline(cliente.nombre, 60, '\n');
    if (arch.eof()) return false;
    cliente.cantDeLibros = 0;
    cliente.pagoTotal = 0;
    return true;
}

bool operator >> (struct LibroSolicitado& libroSolicitado, struct Libro*& arrLibros) {
    for (int i=0; strcmp(arrLibros[i].codigo, "FIN") != 0 ; i++) {
        if (strcmp(arrLibros[i].codigo, libroSolicitado.codigoDelLibro) == 0) {
            if (arrLibros[i].stock == 0) {
                libroSolicitado.atendido = false;
                return false;
            }
            else {
                arrLibros[i].stock--;
                libroSolicitado.precio = arrLibros[i].precio;
                libroSolicitado.atendido = true;
                return true;
            }
        }
    }
    return false;
}

bool operator << (struct Cliente& cliente, struct LibroSolicitado libroSolicitado) {
    int cantLib = cliente.cantDeLibros;
    if (cantLib < 30) {
        cliente.cantDeLibros++;
        cliente.librosSolicitados[cantLib].precio = libroSolicitado.precio;
        strcpy(cliente.librosSolicitados[cantLib].codigoDelLibro, libroSolicitado.codigoDelLibro);
        return true;
    }
    return false;
}

void operator ++ (struct Cliente& cliente) {
    for (int i=0; i < cliente.cantDeLibros; i++) {
        cliente.pagoTotal += cliente.librosSolicitados[i].precio;
    }
}

void operator << (ofstream& arch, struct Libro libro) {
    arch << right << libro.codigo << "  ";
    arch << setw(40) << left << libro.tiltulo;
    arch << setw(30) << libro.autor;
    arch << setw(5) << libro.stock;
    arch << setw(8) << right << fixed << setprecision(2) << libro.precio << endl;
}

void operator << (ofstream& arch, struct Cliente cliente) {
    arch << setw(12) << left << cliente.dni;
    arch << cliente.nombre << endl;
    arch << "Libros entregados: " << endl;
    arch << setw(10) << ' ';
    arch << setw(15) << left << "Pedido No.";
    arch << setw(15) << "Codigo";
    arch << setw(15) << "Precio" << endl;
    for (int i=0; i < cliente.cantDeLibros and cliente.librosSolicitados[i].atendido; i++) {
        arch << right << setw(15) << cliente.librosSolicitados[i].numeroDePedido;
        arch << left << setw(20) << cliente.librosSolicitados[i].codigoDelLibro;
        arch << setw(8) << right << fixed << setprecision(2) << cliente.librosSolicitados[i].precio << endl;
    }
    cout << left << "Total a pagar: " << setw(8) << right << fixed << setprecision(2) << cliente.pagoTotal << endl;
    cout << "Libros no entregados por falta de stock: " << endl;
    for (int i=0; i < cliente.cantDeLibros and not cliente.librosSolicitados[i].atendido; i++) {
        arch << right << setw(15) << cliente.librosSolicitados[i].numeroDePedido;
        arch << left << setw(20) << cliente.librosSolicitados[i].codigoDelLibro << endl;
    }
}