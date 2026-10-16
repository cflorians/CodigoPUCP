//
// Created by Carlos on 24/06/2026.
//

#ifndef LAB9_2025_2_ETIQUETA_H
#define LAB9_2025_2_ETIQUETA_H

class Etiqueta {
private:
    string codigo;
    string nombre;
public:
    Etiqueta();
    ~Etiqueta();
    Etiqueta(const Etiqueta& org);
    Etiqueta& operator=(const Etiqueta& org);

    void setCodigo(const string& cod);
    void setNombre(const string& nomb);
    string getCodigo() const;
    string getNombre() const;

    void leer(ifstream& arch);
    void imprimir(ofstream& arch) const;
};
ifstream& operator >> (ifstream& arch, Etiqueta& etiqueta);
ofstream& operator << (ofstream& arch, const Etiqueta& etiqueta);

#endif //LAB9_2025_2_ETIQUETA_H
