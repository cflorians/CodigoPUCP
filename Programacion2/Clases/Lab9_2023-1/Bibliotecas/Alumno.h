//
// Created by Carlos on 28/05/2026.
//

#ifndef EJERCICIOLABORATORIOHERENCIA_ALUMNO_H
#define EJERCICIOLABORATORIOHERENCIA_ALUMNO_H

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
    // Alumno(const Alumno& orig);
    // void operator=(const Alumno& orig);

    void setCodigo(int cod);
    int getCodigo() const;

    void setNombre(const char* nomb);
    void getNombre(char* nomb);

    void setEscala(int esc);
    int getEscala() const;

    void setCreditos(double cred);
    int getCreditos() const;

    void setTotal(double tot);
    double getTotal() const;

    void leer(ifstream& arch);
};

#endif //EJERCICIOLABORATORIOHERENCIA_ALUMNO_H
