//
// Created by anaro on 23/03/2026.
//

#ifndef EJERCICIOSCLASE2_FUNCIONES_H
#define EJERCICIOSCLASE2_FUNCIONES_H

void operator >>(ifstream &arch, Pedido &pedido);
void operator >>(ListaPedidos &lista,const char *nombArch);
void operator <<(ofstream &arch,const Pedido &pedido);
void operator <<(const char *nombArch,const ListaPedidos &lista);
void operator +=(ListaPedidos &lista,double porcentaje);
bool operator>(const Pedido &p1,const Pedido &p2);
//void operator ++(ListaPedidos &lista);
void aumentarPrecios(ListaPedidos & lista, double porcentaje = 10);
void mergeSort(Pedido * lista, int inicio, int fin);
void merge(Pedido * lista, int inicio, int centro, int fin);
void operator ==(Pedido &p1, Pedido &p2);
double operator + (Pedido pedido1, Pedido pedido2);
double operator ++ (ListaPedidos lista);

#endif //EJERCICIOSCLASE2_FUNCIONES_H