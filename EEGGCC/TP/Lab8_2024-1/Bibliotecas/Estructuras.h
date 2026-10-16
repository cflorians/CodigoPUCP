

#ifndef LAB8_2024_1_ESTRUCTURAS_H
#define LAB8_2024_1_ESTRUCTURAS_H

struct Facultad {
    char codigo[10]{};
    char nombre[40]{};
};

struct Alumno {
    int codigo = 0;
    char nombre[40]{};
    int numeroDeCursos=0;
    double sumaPonderada=0;
    double numeroDeCreditos=0;
    double promedioPonderado=0;
    struct Facultad facultad;
};

#endif //LAB8_2024_1_ESTRUCTURAS_H