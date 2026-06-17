//
// Created by Carlos on 17/06/2026.
//

#ifndef CLASESTL_ALUMNO_H
#define CLASESTL_ALUMNO_H

class Alumno {
private:
    string nombre;
    int nota;
public:
    Alumno(const string& nombre, int nota);
    void mostrar();
    bool aprobo();
    int getNota();
    string getNombre();
};

#endif //CLASESTL_ALUMNO_H
