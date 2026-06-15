//
// Created by Carlos on 11/06/2026.
//

#ifndef LAB9_2023_1_BOLETA_H
#define LAB9_2023_1_BOLETA_H
#include "Alumno.h"

class Boleta {
private:
    Alumno* pAlumno;
public:
    Boleta();
    ~Boleta();

    void inicializar(char tipo);
    void leer(ifstream& arch);

    bool existe();
    void mostrar(ofstream& arch) const;

    void actualizar();
};

#endif //LAB9_2023_1_BOLETA_H
