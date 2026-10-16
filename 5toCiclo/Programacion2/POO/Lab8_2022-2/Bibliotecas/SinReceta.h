//
// Created by Carlos on 4/06/2026.
//

#ifndef LAB8_2022_2_SINRECETA_H
#define LAB8_2022_2_SINRECETA_H
#include "Medicamentos.h"

class SinReceta : public Medicamentos{
private:
    int dni;
    char* nombre;
public:
    SinReceta();
    ~SinReceta();
    SinReceta(const SinReceta& org);
    void operator = (const SinReceta& org);

    void setDni(int num);
    void setNombre(const char* nomb);

    int getDni() const;
    void getNombre(char* nomb);
};

#endif //LAB8_2022_2_SINRECETA_H
