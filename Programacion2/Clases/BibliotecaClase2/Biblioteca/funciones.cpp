//
// Created by anaro on 23/03/2026.
//

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "ListaPedidos.h"
#include "funciones.h"

//leer un pedido del archivo
void operator >>(ifstream& arch, Pedido& pedido)
{
    static int idPedido = 0;
    idPedido++;
    pedido.id = idPedido;

    arch.getline(pedido.cliente, 60, ',');
    if (arch.eof()) return;
    arch.getline(pedido.producto, 60, ',');
    arch >> pedido.cantidad;
    arch.get(); //lee la coma
    arch >> pedido.precio;
    arch.get(); //lee el salto de línea
}

//Leer todos los pedidos
void operator >>(ListaPedidos& lista, const char* nombArch)
{
    ifstream arch(nombArch, ios::in);

    if (!arch.is_open())
    {
        cout << "No se pudo abrir " << nombArch << endl;
        exit(1);
    }

    Pedido pedido;
    int np = 0;

    while (true)
    {
        arch >> pedido; //utilizamos la sobrecarga de un pedido
        if (arch.eof()) break;

        lista.pedidos[np] = pedido;
        np++;
    }

    lista.cantPedidos = np;
}

//Escribir un pedido en archivo
void operator <<(ofstream& arch, const Pedido& pedido)
{
    arch << setw(5) << pedido.id << " "
        << left << setw(25) << pedido.cliente
        << setw(20) << pedido.producto
        << right << setw(5) << pedido.cantidad
        << setw(10) << fixed << setprecision(2) << pedido.precio << endl;
}

//Guardar lista de pedidos
void operator <<(const char* nombArch, const ListaPedidos& lista)
{
    ofstream arch(nombArch, ios::out);

    if (!arch.is_open())
    {
        cout << "No se pudo crear " << nombArch << endl;
        exit(1);
    }

    arch << "LISTA DE PEDIDOS" << endl << endl;

    for (int i = 0; i < lista.cantPedidos; i++)
        arch << lista.pedidos[i];
}

//funcion con parametros con valores por defecto, ver la cabecera en funciones.h
void aumentarPrecios(ListaPedidos& lista, double porcentaje)
{
    lista += porcentaje;
}

//Actualizar precios, todos los pedidos actualizan su precio
void operator +=(ListaPedidos& lista, double porcentaje)
{
    for (int i = 0; i < lista.cantPedidos; i++)
        lista.pedidos[i].precio *= (1 + porcentaje / 100);
}

//Comparar pedidos por campo cliente, compara dos cadenas usando strcmp
bool operator>(const Pedido& p1, const Pedido& p2)
{
    return strcmp(p1.cliente, p2.cliente) > 0;
}

//Ordenar la lista
// void operator ++(ListaPedidos& lista)
// {   //metodo eficiente de ordenamiento, con complejidad n(logn)
//     mergeSort(lista.pedidos, 0, lista.cantPedidos - 1);
// }

void mergeSort(Pedido* arreglo, int inicio, int fin)
{
    //caso base
    if (inicio == fin) return;

    //centro
    int centro = (inicio + fin) / 2;
    mergeSort(arreglo, inicio, centro); //izquierda
    mergeSort(arreglo, centro + 1, fin); //derecha
    merge(arreglo, inicio, centro, fin); // juntas
}

void merge(Pedido* arreglo, int inicio, int centro, int fin)
{
    int size = fin - inicio + 1;
    Pedido temp[size];
    for (int i = 0; i < size; i++)
        temp[i] = arreglo[inicio + i];

    int izquierda = 0;
    int derecha = centro - inicio + 1;

    for (int indice = 0; indice < size; indice++)
    {
        if (derecha <= fin - inicio) //condición que verifica elementos a la derecha
            if (izquierda <= centro - inicio) // condición que verifica elementos a la izquierda
                if (temp[izquierda] > temp[derecha])
                    arreglo[indice + inicio] = temp[derecha++];
                else
                    arreglo[indice + inicio] = temp[izquierda++];
            else
                arreglo[indice + inicio] = temp[derecha++]; //lo que sobró de derecha
        else
            arreglo[indice + inicio] = temp[izquierda++]; //lo que sobró de izquierda
    }
}

//Intercambiar pedidos, por si necesito intercambiar datos
void operator ==(Pedido& p1, Pedido& p2)
{
    Pedido aux;

    aux = p1;
    p1 = p2;
    p2 = aux;
}

double operator + (Pedido pedido1, Pedido pedido2) {
    return pedido1.precio + pedido2.precio;
}

double operator ++ (ListaPedidos lista) {
    double precioTotal = 0;
    for (int i = 0; i < lista.cantPedidos; i++) {
        precioTotal += lista.pedidos[i].precio;
    }
    return precioTotal;
}