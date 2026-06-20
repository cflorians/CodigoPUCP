//
// Created by Carlos on 18/06/2026.
//

#ifndef LAB10_2022_2_MEDICAMENTO_H
#define LAB10_2022_2_MEDICAMENTO_H

class Medicamento {
    int codigo;
    string nombre;
    int stock;
    double precio;
public:
    Medicamento();
    Medicamento(const Medicamento& org);
    void operator=(const Medicamento& org);

    void setCodigo(int cod);
    void setNombre(const string& nomb);
    void setStock(int stk);
    void setPrecio(double prec);

    int getCodigo() const;
    string getNombre() const;
    int getStock() const;
    double getPrecio() const;

    virtual void lee(ifstream& arch);
    virtual void imprime(ofstream& arch) const;

    bool operator < (const Medicamento& m) const;
};

#endif //LAB10_2022_2_MEDICAMENTO_H
