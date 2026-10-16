//
// Created by carlo on 5/13/2026.
//

#ifndef LAB6_2025_1_EMPRESA_H
#define LAB6_2025_1_EMPRESA_H

#include "Multa.h"


class Empresa {
private:
    int dni;
    char* nombre;
    char* placas[10];
    int numPlacas;
    Multa multas[100];
    int numMultas;
public:
    Empresa();
    ~Empresa();

    void setDni(int dni);
    int getDni() const;

    void setNombre(const char* nombre);
    void getNombre(char* nomb) const;

    void setPlacaI(const char* plac, int i);
    void getPlacaI(char* plac, int i) const;

    int getNumPlacas() const;
    void setNumPlacas(int numPlacas);

    int getNumMultas() const;
    void setNumMultas(int numMultas);

    Multa getMulta(int) const;

    void operator += (const Multa&);
};

void operator >> (ifstream&, Empresa&);
void operator << (ofstream&, const Empresa&);


#endif //LAB6_2025_1_EMPRESA_H
