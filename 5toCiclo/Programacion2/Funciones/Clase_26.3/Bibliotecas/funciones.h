//
// Created by carlo on 3/26/2026.
//

#ifndef CLASE_26_3_FUNCIONES_H
#define CLASE_26_3_FUNCIONES_H

void operator >> (ListaPedidos &lista, const char* nombreArchivo);
void operator >> (ifstream& arch, Pedido &pedido);
void operator << (const char* nombreArch, ListaPedidos lista);

#endif //CLASE_26_3_FUNCIONES_H