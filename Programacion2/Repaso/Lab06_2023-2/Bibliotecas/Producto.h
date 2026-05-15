//
// Created by carlo on 5/14/2026.
//

#ifndef LAB06_2023_2_PRODUCTO_H
#define LAB06_2023_2_PRODUCTO_H



class Producto {
private:
    char* codigo;
    char* descripcion;
    double precio;
    int stock;
    int clientes_servidos[200]{};
    int cantidad_clientes_servidos;
    int cantidad_clientes_no_servidos;
public:
    Producto();
    ~Producto();

    void setCodigo(char* cod);
    void getCodigo(char* cod);

    void setDescripcion(char* desc);
    void getDescripcion(char* desc);

    void setPrecio(double prec);
    double getPrecio() const;

    void setStock(int st);
    int getStock() const;

    void setCantidadServidos(int cantidad);
    int getCantidadServidos() const;

    void setCantidadNoServidos(int cantidad);
    int getCantidadNoServidos() const;
};

bool operator >> (ifstream& arch, Producto& p);


#endif //LAB06_2023_2_PRODUCTO_H
