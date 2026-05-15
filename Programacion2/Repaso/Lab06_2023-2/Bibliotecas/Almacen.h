//
// Created by carlo on 5/14/2026.
//

#ifndef LAB06_2023_2_ALMACEN_H
#define LAB06_2023_2_ALMACEN_H
#include "Cliente.h"
#include "Producto.h"


class Almacen {
private:
    Cliente arreglo_clientes[200];
    int cantidad_clientes;
    Producto arreglo_productos[200];
    int cantidad_productos;
public:
    Almacen();
    ~Almacen();
};



#endif //LAB06_2023_2_ALMACEN_H
