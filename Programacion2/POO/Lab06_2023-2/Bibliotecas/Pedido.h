//
// Created by carlo on 5/14/2026.
//

#ifndef LAB06_2023_2_PEDIDO_H
#define LAB06_2023_2_PEDIDO_H



class Pedido {
private:
    char* codigo;
    int dni_cliente;
    double precio_producto;
public:
    Pedido();
    ~Pedido();

    void setCodigo(char* cod);
    void getCodigo(char* cod);

    void setDniCliente(int d);
    double getDniCliente() const;

    void setPrecio(double precio);
    double getPrecio() const;
};

bool operator >> (ifstream& arch, Pedido& pedido);

#endif //LAB06_2023_2_PEDIDO_H
