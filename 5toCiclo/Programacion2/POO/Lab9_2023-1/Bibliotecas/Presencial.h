//
// Created by Carlos on 28/05/2026.
//

#ifndef EJERCICIOLABORATORIOHERENCIA_PRESENCIAL_H
#define EJERCICIOLABORATORIOHERENCIA_PRESENCIAL_H
#include <iosfwd>

#include "Alumno.h"

class Presencial : public Alumno {
private:
    double recargo;
    double total;
public:
    Presencial();
    void operator = (const Presencial& org);

    void setRecargo(double recargo);
    double getRecargo() const;

    void setTotal(double total);
    double getTotal() const;

    void leer(ifstream& arch);
};

void operator << (ifstream& arch, const Presencial& org);

#endif //EJERCICIOLABORATORIOHERENCIA_PRESENCIAL_H
