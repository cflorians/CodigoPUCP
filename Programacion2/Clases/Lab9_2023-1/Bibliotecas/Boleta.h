//
// Created by Carlos on 4/06/2026.
//

#ifndef LAB9_2023_1_BOLETA_H
#define LAB9_2023_1_BOLETA_H
#include "Alumno.h"

class Boleta {
private:
    Alumno* pBoleta;
public:
    /* TAREA
     * A la clase Boleta le falta el constructor copia y el operador =,
     * porque tiene un puntero (pBoleta).
     * Sin ellos si alguna vez copias boleta, ambos apuntarian al mismo objeto y el otro
     * quedaria como un puntero perdido
     */
    Boleta();
    ~Boleta();

};

#endif //LAB9_2023_1_BOLETA_H
