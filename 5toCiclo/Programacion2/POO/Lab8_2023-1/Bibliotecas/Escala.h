//
// Created by Carlos on 4/06/2026.
//

#ifndef LAB8_2023_1_ESCALA_H
#define LAB8_2023_1_ESCALA_H

class Escala {
private:
    int codigo;
    double precio;
public:
    Escala();  // El constructor lo agregamos para establecer el codigo en 0 que nos ayudara en
    ~Escala(); // la impresion de los datos para saber cuando detenernos

    void setCodigo(int cod);
    void setPrecio(double pre);

    int getCodigo() const;
    double getPrecio() const;
};

void operator >> (ifstream& arch, Escala& escala);

#endif //LAB8_2023_1_ESCALA_H
