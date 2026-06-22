//
// Created by Carlos on 18/06/2026.
//

#ifndef LAB10_2022_2_MARCA_H
#define LAB10_2022_2_MARCA_H
#include "Medicamento.h"

class Marca : public Medicamento{
private:
    int lote;
    string laboratorio;
public:
    Marca();
    Marca(const Marca& org);
    void operator = (const Marca& org);

    void setLote(int lot);
    int getLote() const;
    void setLaboratorio(const string& lab);
    string getLaboratorio() const;

    void lee(ifstream& arch);
    void imprime(ofstream& arch) const;
};

#endif //LAB10_2022_2_MARCA_H
