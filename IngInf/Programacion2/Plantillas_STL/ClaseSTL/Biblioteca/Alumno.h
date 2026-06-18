//
// Created by Carlos on 17/06/2026.
//

#ifndef CLASESTL_ALUMNO_H
#define CLASESTL_ALUMNO_H

class Alumno {
private:
    string nombre;
    int nota;
    vector<string> frutas;
public:
    Alumno();
    Alumno(const string& nombre, int nota);
    void mostrar();
    bool aprobo();
    int getNota() const;
    void setNombre(const string& nombre);
    string getNombre() const;
    void agregarFruta(string fruta);
    bool operator < (const Alumno& alumno); // esto es para el sort
};
ostream& operator << (ostream& arch, const Alumno& alumno);
ifstream& operator >> (ifstream& arch, Alumno& alumno);

#endif //CLASESTL_ALUMNO_H
