//
// Created by Carlos on 24/06/2026.
//

#ifndef LAB9_2025_2_CATEGORIA_H
#define LAB9_2025_2_CATEGORIA_H
#include "Streamer.h"

class Categoria {
private:
    string codigo;
    string nombre;
    string descripcion;
public:
    Categoria();
    ~Categoria();
    Categoria(const Categoria & org);
    Categoria & operator=(const Categoria & org);

    void setCodigo(const string& cod);
    void setNombre(const string& nomb);
    void setDescripcion(const string& desc);
    string getCodigo() const;
    string getNombre() const;
    string getDescripcion() const;

    void leer(ifstream& arch);
    void imprimir(ofstream& arch) const;

    bool operator < (const Categoria& cat) const;
    bool operator == (const Categoria& cat) const;
};
ifstream& operator >> (ifstream& arch, Categoria& categoria);
ofstream& operator << (ofstream& arch, const Categoria& categoria);

#endif //LAB9_2025_2_CATEGORIA_H
