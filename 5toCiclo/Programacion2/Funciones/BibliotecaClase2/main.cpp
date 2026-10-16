/*
 * Archivo: main.cpp
 * Autor: Ana C. Roncal N.
 * Creado el 23 de 03 del 2026 a las 10:24
 */

#include <iostream>
#include <fstream>
using namespace std;
#include "Biblioteca/ListaPedidos.h"
#include "Biblioteca/funciones.h"


int main(int argc, char** argv)
{
    ListaPedidos lista;

    //Leer todos los pedidos
    lista >> "Archivos/pedidos.csv";

    double porcentaje = 20.0;
    if (porcentaje > 0.0)
        aumentarPrecios(lista, porcentaje);
    else
        aumentarPrecios(lista);

    //usando el operador de ordenamiento
    ++lista; //ordena por nombre del cliente

    "Reportes/reporte.txt" << lista;

    cout<<"Proceso terminado"<<endl;

    ofstream arch("Reportes/reporte2.txt", ios::out);

    if (!arch.is_open())
    {
        cout << "No se pudo crear " << endl;
        exit(1);
    }

    Pedido pedido1={20,"ANITA", "HP", 3, 10.10};
    Pedido pedido2={22,"MIGUEL", "MAC", 4, 100.10};
    //usando el operador de igualdad

    pedido1 == pedido2;
    arch << pedido1;
    arch << pedido2;

    cout << pedido1 + pedido2 << endl;

    cout << ++lista;

    return 0;
}