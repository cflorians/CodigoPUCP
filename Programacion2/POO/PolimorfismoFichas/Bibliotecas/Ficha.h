//
// Created by Carlos on 3/06/2026.
//

#ifndef POLIMORFISMOFICHAS_FICHA_H
#define POLIMORFISMOFICHAS_FICHA_H


class Ficha { // Como sus metodos no se implementan, esto es una clase abstracta
private:
    int fila;
    int columna;
public:
    //Los metodos virtual puros NO SE IMPLEMENTAN
    virtual void mover(char direccion, int cantidad) = 0; // el " = 0 " es para que sea virtual puro
};


#endif //POLIMORFISMOFICHAS_FICHA_H
