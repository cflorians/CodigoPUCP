//
// Created by Carlos on 4/06/2026.
//

#ifndef LAB8_2023_1_SEMIPRESENCIAL_H
#define LAB8_2023_1_SEMIPRESENCIAL_H
#include "Alumno.h"

class Semipresencial : public Alumno{
private:
    double descuento;
    double total;
public:
    void setDescuento(double desc);
    void setTotal(double tot);

    double getDescuento() const;
    double getTotal() const;

    void calcularTotal(int cantCreditos, double escala);
};
void operator >> (ifstream& arch, Semipresencial& s);
void operator << (ofstream& arch, Semipresencial& s);

#endif //LAB8_2023_1_SEMIPRESENCIAL_H
