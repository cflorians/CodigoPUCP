//
// Created by Carlos on 28/05/2026.
//

#ifndef EJERCICIOLABORATORIOHERENCIA_SEMIPRESENCIAL_H
#define EJERCICIOLABORATORIOHERENCIA_SEMIPRESENCIAL_H
#include "Alumno.h"

class Semipresencial : public Alumno{
private:
    double descuento;
    double total;
public:
    Semipresencial();

    void setDescuento(double descuento);
    double getDescuento() const;

    void setTotal(double total);
    double getTotal() const;
};

#endif //EJERCICIOLABORATORIOHERENCIA_SEMIPRESENCIAL_H
