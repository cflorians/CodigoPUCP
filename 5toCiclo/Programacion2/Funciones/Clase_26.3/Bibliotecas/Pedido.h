//
// Created by carlo on 3/26/2026.
//

#ifndef CLASE_26_3_PEDIDO_H
#define CLASE_26_3_PEDIDO_H

struct Pedido {
    int id;
    char cliente[60];
    char producto[60];
    int cantidad;
    double precio;
};

#endif //CLASE_26_3_PEDIDO_H