//
// Created by Carlos on 3/06/2026.
//

#ifndef POLIMORFISMOFICHAS_TORRE_H
#define POLIMORFISMOFICHAS_TORRE_H
#include "Ficha.h"


class Torre : public Ficha{
public:
    void mover(char direccion, int cantidad);
};


#endif //POLIMORFISMOFICHAS_TORRE_H
