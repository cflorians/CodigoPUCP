//
// Created by carlo on 11/9/2025.
//

#ifndef LAB8_2025_1_ESTRUCTURAS_H
#define LAB8_2025_1_ESTRUCTURAS_H

struct TablaDeInfracciones {
    char* codigo;
    double multa;
    char* descripcion;
};

struct Fecha {
    int dd;
    int mm;
    int aa;
    int fecha;
};

struct EmpresasRegistradas {
    int dni;
    char* nombre;
    char* distrito;
    char* placas[10];
    int numPlacas;
    struct Fecha fechaDeInfraccion;
    struct Fecha fechaDePago;
    double totalMultas;
    double totalPagado;
    double totalAdeudado;
    int cantidadDeFechas;
};

#endif //LAB8_2025_1_ESTRUCTURAS_H