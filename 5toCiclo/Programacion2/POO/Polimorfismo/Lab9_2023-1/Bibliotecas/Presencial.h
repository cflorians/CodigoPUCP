//
// Created by Carlos on 11/06/2026.
//

#ifndef LAB9_2023_1_PRESENCIAL_H
#define LAB9_2023_1_PRESENCIAL_H
#include "Alumno.h"

class Presencial : public Alumno{
private:
    double recargo;
    double total;
public:
    Presencial();

    void setRecargo(double rec);
    void setTotal(double tot);

    double getRecargo() const;
    double getTotal() const;

    void lee(ifstream& arch);
    void imprime(ofstream& arch);

    void actualizaTotal();
};

#endif //LAB9_2023_1_PRESENCIAL_H
