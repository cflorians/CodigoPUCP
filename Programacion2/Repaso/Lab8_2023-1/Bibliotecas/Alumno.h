//
// Created by Carlos on 4/06/2026.
//

#ifndef LAB8_2023_1_ALUMNO_H
#define LAB8_2023_1_ALUMNO_H

class Alumno {
private:
    int codigo;
    char* nombre;
    int escala;
    double total;
public:
    // Como tiene un char*, debemos aplicar la REGLA DE LOS 3
    Alumno();
    ~Alumno();
    Alumno(const Alumno& org);
    void operator = (const Alumno& org);

    void setCodigo(int cod);
    void setNombre(const char* nomb);
    void setEscala(int esc);
    void setTotal(double tot);

    int getCodigo() const;
    void getNombre(char* nomb);
    int getEscala() const;
    double getTotal() const;

    void leer(ifstream& arch);
    void mostrar(ofstream& arch);
};

#endif //LAB8_2023_1_ALUMNO_H
