//
// Created by carlo on 5/14/2026.
//

#ifndef LAB06_2023_2_CLIENTE_H
#define LAB06_2023_2_CLIENTE_H
#include <iosfwd>

#include "Pedido.h"
#include "ProductoEntregado.h"


class Cliente {
private:
    int dni;
    char* nombre;
    int telefono;
    ProductoEntregado productos_entregados[200];
    int cantidad_productos_entregados;
    double monto_total;
public:
    Cliente();
    ~Cliente();

    void setDni(int);
    int getDni() const;

    void setNombre(char*);
    void getNombre(char*) const;

    void setTelefono(int);
    int getTelefono() const;

    void setMontoTotal(double);
    double getMontoTotal() const;

    void operator += (Pedido&);
};

bool operator >> (ifstream& arch, Cliente& cliente);

#endif //LAB06_2023_2_CLIENTE_H
