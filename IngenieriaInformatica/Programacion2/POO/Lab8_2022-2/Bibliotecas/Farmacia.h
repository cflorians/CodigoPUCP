//
// Created by Carlos on 4/06/2026.
//

#ifndef LAB8_2022_2_FARMACIA_H
#define LAB8_2022_2_FARMACIA_H
#include "ConReceta.h"
#include "Medico.h"
#include "SinReceta.h"

class Farmacia {
private:
    Medico lMedico[100];
    SinReceta lSinReceta[1000];
    ConReceta lConReceta[1000];
public:
    void cargaMedico(const char* nombArch);
    void leeRecetas(const char* nombArch, const char* nombArch2);
    void imprimeRecetas(const char* nombArch);
};

#endif //LAB8_2022_2_FARMACIA_H
