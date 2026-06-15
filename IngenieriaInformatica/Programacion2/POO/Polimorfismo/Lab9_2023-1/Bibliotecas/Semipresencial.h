//
// Created by Carlos on 11/06/2026.
//

#ifndef LAB9_2023_1_SEMIPRESENCIAL_H
#define LAB9_2023_1_SEMIPRESENCIAL_H
#include "Alumno.h"

class Semipresencial : public Alumno{
private:
    double descuento;
    double total;
public:
    Semipresencial();

    void setDescuento(double desc);
    void setTotal(double tot);

    double getDescuento() const;
    double getTotal() const;

    void lee(ifstream& arch);
    void imprime(ofstream& arch);

    void actualizaTotal();
};

#endif //LAB9_2023_1_SEMIPRESENCIAL_H
