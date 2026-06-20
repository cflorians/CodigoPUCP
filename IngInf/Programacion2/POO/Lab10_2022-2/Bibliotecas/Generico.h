//
// Created by Carlos on 18/06/2026.
//

#ifndef LAB10_2022_2_GENERICO_H
#define LAB10_2022_2_GENERICO_H
#include "Medicamento.h"

class Generico : public Medicamento{
private:
    string pais;
public:
    Generico();
    Generico(const Generico& org);
    void operator = (const Generico& org);

    void setPais(const string& pais);
    string getPais() const;

    void lee(ifstream& arch);
    void imprime(ofstream& arch) const;
};

#endif //LAB10_2022_2_GENERICO_H
