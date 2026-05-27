//
// Created by Carlos on 5/27/2026.
//

#ifndef HERENCIA_ANIMAL_H
#define HERENCIA_ANIMAL_H


class Animal {
private:
    char* nombre; // como tengo un char* aplico la REGLA DE LOS 3
    int edad;
    double peso;
public:
    Animal();
    ~Animal();
    Animal(const char* nombre, int edad, double peso);
    Animal(const  Animal& ani);
    void operator=(const Animal& ani);

    void setNombre(const char* nomb);
    void getNombre(char* nomb);

    void setEdad(int ed);
    int getEdad() const;

    void setPeso(double peso);
    double getPeso() const;

    void mostrar();
};


#endif //HERENCIA_ANIMAL_H
