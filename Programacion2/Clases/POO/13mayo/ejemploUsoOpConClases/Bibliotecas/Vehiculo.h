//
// Created by carlo on 5/13/2026.
//

#ifndef LAB6_2025_1_VEHICULO_H
#define LAB6_2025_1_VEHICULO_H
#include "Accesorio.h"

class Vehiculo {
private:
    char* marca;
    char* modelo;
    int anno;
    char* color;
    double velocidadActual;
    Accesorio listaAccesorios[20];
    int cantAccesorios;
public:
    // Constructores
    Vehiculo();
    // Constructor copia
    Vehiculo(const Vehiculo&);
    void operator=(const Vehiculo&);

    ~Vehiculo(); // Destructor

    //Setters y getters
    void setMarca(const char*);
    void getMarca(char*) const;

    void setModelo(const char*);
    void getModelo(char*) const;

    void setColor(const char*);
    void getColor(char*) const;

    void set_anno(const int);
    int get_anno() const;

    void set_velocidad_actual(const double);
    double get_velocidad_actual() const;
};

ifstream& operator>> (ifstream&, Vehiculo&);
char* leerCadena(ifstream&, char limit = ',');
ofstream& operator<<(ofstream& arch ,const Vehiculo& v);


#endif //LAB6_2025_1_VEHICULO_H
