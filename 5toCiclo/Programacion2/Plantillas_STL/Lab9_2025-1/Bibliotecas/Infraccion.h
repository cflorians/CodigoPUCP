//
// Created by Carlos on 25/06/2026.
//

#ifndef LAB9_2025_1_INFRACCION_H
#define LAB9_2025_1_INFRACCION_H

class Infraccion {
private:
    string codigo;
    double multa;
    string gravedad;
    string descripcion;
public:
    void setCodigo(const string& cod);
    void setMulta(const double& mult);
    void setGravedad(const string& grav);
    void setDescripcion(const string& desc);

    string getCodigo() const;
    double getMulta() const;
    string getGrav() const;
    string getDescripcion() const;

    bool operator < (const Infraccion& infraccion) const;
};
ifstream& operator>> (ifstream& arch, Infraccion& infraccion);
ofstream& operator<< (ofstream& arch, const Infraccion& infraccion);

#endif //LAB9_2025_1_INFRACCION_H
