//
// Created by Carlos on 4/06/2026.
//

#ifndef LAB8_2023_1_VIRTUAL_H
#define LAB8_2023_1_VIRTUAL_H
#include "Alumno.h"

class Virtual : public Alumno {
private:
    char* licencia;
    double total;
public:
    // Como tenemos nuevamente cadena de caracteres dinamica, aplicamos REGLA DE LOS 3
    Virtual();
    ~Virtual();
    Virtual(const Virtual& org);
    void operator=(const Virtual& org);

    void setLicencia(const char* lic);
    void setTotal(double tot);

    void getLicencia(char* lic);
    double getTotal() const;

    void calcularTotal(int cantCreditos, double escala);
};
void operator >> (ifstream& arch, Virtual& v);
void operator << (ofstream& arch, Virtual& v);

#endif //LAB8_2023_1_VIRTUAL_H
