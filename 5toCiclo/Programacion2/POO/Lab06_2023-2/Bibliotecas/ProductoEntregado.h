//
// Created by carlo on 5/14/2026.
//

#ifndef LAB06_2023_2_PRODUCTOENTREGADO_H
#define LAB06_2023_2_PRODUCTOENTREGADO_H

class ProductoEntregado {
private:
    char* codigo;
    double precio;
public:
    ProductoEntregado();
    ~ProductoEntregado();

    void setCodigo(char*);
    void getCodigo(char*) const;

    void setPrecio(double);
    double getPrecio() const;
};



#endif //LAB06_2023_2_PRODUCTOENTREGADO_H
