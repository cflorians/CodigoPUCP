//
// Created by carlo on 5/13/2026.
//

#ifndef LAB6_2025_1_MINISTERIODETRANSPORTE_H
#define LAB6_2025_1_MINISTERIODETRANSPORTE_H
#include "Empresa.h"
#include "Infraccion.h"


class MinisterioDeTransporte {
private:
    Infraccion *infracciones;
    int numInf;
    Empresa empresas[50];
    int numEmp;
public:
    MinisterioDeTransporte();
    ~MinisterioDeTransporte();

    void operator < (const char*);
    void operator <= (const char*);
    void operator <<= (const char*);
    int buscarInfraccion(int) const;
    int buscarEmpresa(const char*) const;

    void operator >> (const char*) const;
};
void separador(ofstream&, char);

#endif //LAB6_2025_1_MINISTERIODETRANSPORTE_H
