//
// Created by Carlos on 28/05/2026.
//

#ifndef EJERCICIOLABORATORIOHERENCIA_VIRTUAL_H
#define EJERCICIOLABORATORIOHERENCIA_VIRTUAL_H
#include "Alumno.h"

class Virtual : public Alumno {
private:
    char* licencia;
    double total;
public:
    Virtual();
    ~Virtual();
    Virtual(const Virtual& orig);
    void operator=(const Virtual& orig);

    void setLicencia(const char* lic);
    void getLicencia(char* lic);

    void setTotal(double total);
    double getTotal() const;

    void leer(ifstream& arch);
};

#endif //EJERCICIOLABORATORIOHERENCIA_VIRTUAL_H
