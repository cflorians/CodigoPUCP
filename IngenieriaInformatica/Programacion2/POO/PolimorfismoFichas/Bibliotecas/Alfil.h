//
// Created by Carlos on 3/06/2026.
//

#ifndef POLIMORFISMOFICHAS_ALFIL_H
#define POLIMORFISMOFICHAS_ALFIL_H
#include "Ficha.h"


class Alfil : public Ficha{
public:
    void mover(char direccion, int cantidad);
};


#endif //POLIMORFISMOFICHAS_ALFIL_H
