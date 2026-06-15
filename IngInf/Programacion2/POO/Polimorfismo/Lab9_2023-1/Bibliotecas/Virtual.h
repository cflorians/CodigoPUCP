//
// Created by Carlos on 11/06/2026.
//

#ifndef LAB9_2023_1_VIRTUAL_H
#define LAB9_2023_1_VIRTUAL_H
#include "Alumno.h"

class Virtual : public Alumno{
private:
    char* licencia;
    double total;
public:
    Virtual();
    ~Virtual();
    Virtual(const Virtual& org);
    void operator=(const Virtual& org);

    void setLicencia(const char* lic);
    void setTotal(double tot);

    void getLicencia(char* lic);
    double getTotal() const;

    void lee(ifstream& arch);
    void imprime(ofstream& arch);

    void actualizaTotal();
};

#endif //LAB9_2023_1_VIRTUAL_H
