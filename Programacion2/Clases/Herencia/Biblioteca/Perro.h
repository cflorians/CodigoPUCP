//
// Created by Carlos on 5/27/2026.
//

#ifndef HERENCIA_PERRO_H
#define HERENCIA_PERRO_H
#include "Animal.h"

class Perro : public Animal {
private:
    bool esDomestico;
public:
    Perro();
    Perro(const char *nomb, int ed, double pe, bool esDomestico);
    ~Perro();

    void setDomestico(bool domestico);
    bool getDomestico() const;

    void mostrar();
};


#endif //HERENCIA_PERRO_H
