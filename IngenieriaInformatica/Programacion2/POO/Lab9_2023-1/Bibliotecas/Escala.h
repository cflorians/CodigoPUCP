//
// Created by Carlos on 28/05/2026.
//

#ifndef EJERCICIOLABORATORIOHERENCIA_ESCALA_H
#define EJERCICIOLABORATORIOHERENCIA_ESCALA_H


class Escala {
private:
    int codigo;
    double precio;
public:
    Escala();

    void setCodigo(int cod);
    int getCodigo() const;

    void setPrecio(double pre);
    double getPrecio() const;
};
void operator >> (ifstream& arch, Escala& escala);
void operator << (ofstream& arch, Escala& escala);

#endif //EJERCICIOLABORATORIOHERENCIA_ESCALA_H
