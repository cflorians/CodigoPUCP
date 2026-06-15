//
// Created by Carlos on 4/06/2026.
//

#ifndef LAB8_2022_2_CONRECETA_H
#define LAB8_2022_2_CONRECETA_H
#include "Medicamentos.h"

class ConReceta : public Medicamentos{
private:
    int codMed;
    char* especialidad;
public:
    ConReceta();
    ~ConReceta();
    ConReceta(const ConReceta& org);
    void operator = (const ConReceta& org);

    void setCodMed(int cod);
    void setEspecialidad(const char* esp);

    int getCodMed() const;
    void getEspecialidad(char* esp);
};

#endif //LAB8_2022_2_CONRECETA_H
