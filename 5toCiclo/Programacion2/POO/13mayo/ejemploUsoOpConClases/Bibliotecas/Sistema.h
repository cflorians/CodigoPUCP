//
// Created by carlo on 5/13/2026.
//

#ifndef LAB6_2025_1_SISTEMA_H
#define LAB6_2025_1_SISTEMA_H
#include "Vehiculo.h"

class Sistema {
private:
    class Vehiculo* vehiculos;
    int numVehiculos;
public:
    Sistema();
    ~Sistema();

    void operator << (const char*);
    ofstream& operator >> (const char*);
    void operator < (const char*);
};



#endif //LAB6_2025_1_SISTEMA_H
