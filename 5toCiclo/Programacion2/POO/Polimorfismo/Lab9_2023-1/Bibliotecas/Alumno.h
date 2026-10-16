//
// Created by Carlos on 11/06/2026.
//

#ifndef LAB9_2023_1_ALUMNO_H
#define LAB9_2023_1_ALUMNO_H

class Alumno {
private:
    int codigo;
    char* nombre;
    int escala;
    double creditos;
    double total;
public:
    Alumno();
    ~Alumno();
    Alumno(const Alumno& org);
    void operator=(const Alumno& org);

    void setCodigo(int cod);
    void setNombre(const char* nomb);
    void setEscala(int esc);
    void setCreditos(double cred);
    void setTotal(double tot);

    int getCodigo() const;
    void getNombre(char* nomb) const;
    int getEscala() const;
    double getCreditos() const;
    double getTotal() const;

    void leer(ifstream& arch);
    virtual void lee(ifstream& arch) = 0;
    void imprimir(ofstream& arch);
    virtual void imprime(ofstream& arch) = 0;
    virtual void actualizaTotal() = 0;
};

#endif //LAB9_2023_1_ALUMNO_H
