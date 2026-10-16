//
// Created by anaro on 25/03/2026.
//

#ifndef EJERCICIOSCLASE2_PEDIDOS_H
#define EJERCICIOSCLASE2_PEDIDOS_H
struct Pedido{
    int id;
    char cliente[60];
    char producto[60];
    int cantidad;
    double precio;
};
#endif //EJERCICIOSCLASE2_PEDIDOS_H