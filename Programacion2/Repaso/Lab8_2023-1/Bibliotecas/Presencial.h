//
// Created by Carlos on 4/06/2026.
//

#ifndef LAB8_2023_1_PRESENCIAL_H
#define LAB8_2023_1_PRESENCIAL_H
#include "Alumno.h"
#include "Escala.h"

class Presencial : public Alumno {
private:
    double recargo;
    double total;
public:
    void setRecargo(double rec);
    void setTotal(double tot);

    double getRecargo() const;
    double getTotal() const;

    void calcularTotal(int cantCreditos, double escala);
};
void operator >> (ifstream& arch, Presencial& p);
void operator << (ofstream& arch, Presencial& p);

#endif //LAB8_2023_1_PRESENCIAL_H
