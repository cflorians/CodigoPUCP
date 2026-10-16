//
// Created by Carlos on 18/06/2026.
//

#ifndef LAB10_2022_2_NODO_H
#define LAB10_2022_2_NODO_H
#include "Medicamento.h"

class Nodo {
private:
    Medicamento* medicamento;
    Nodo* izq;
    Nodo* der;
public:
    Nodo();
    ~Nodo();
    void setMedicamento(Medicamento* m);
    Medicamento* getMedicamento() const;
    void setIzq(Nodo* n);
    Nodo* getIzq() const;
    void setDer(Nodo* n);
    Nodo* getDer() const;
};

#endif //LAB10_2022_2_NODO_H
