//
// Created by Carlos on 10/06/2026.
//

#ifndef LISTACLASE_PERSONA_H
#define LISTACLASE_PERSONA_H

class Persona {
private:
    int dni;
    char* nombre;
    double sueldo;
public:
    Persona();
    ~Persona();
    Persona(const Persona& org);
    void operator=(const Persona& org);

    void setNombre(const char* nomb);
    void getNombre(char* nomb) const;
    void setDni(int id);
    int getDni() const;
    void setSueldo(double monto);
    double getSueldo() const;
};
ifstream& operator>> (ifstream& arch, Persona& per);
ofstream& operator<< (ofstream& arch, const Persona& per);
bool operator > (const Persona& a, const Persona& b);

#endif //LISTACLASE_PERSONA_H
