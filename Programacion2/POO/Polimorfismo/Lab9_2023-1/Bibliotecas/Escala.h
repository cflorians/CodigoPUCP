//
// Created by Carlos on 11/06/2026.
//

#ifndef LAB9_2023_1_ESCALA_H
#define LAB9_2023_1_ESCALA_H

class Escala {
private:
    int codigo;
    double precio;
public:
    Escala();

    void setCodigo(int cod);
    void setPrecio(double prec);

    int getCodigo() const;
    double getPrecio() const;
};
void operator >> (ifstream& arch, Escala &e);

#endif //LAB9_2023_1_ESCALA_H
