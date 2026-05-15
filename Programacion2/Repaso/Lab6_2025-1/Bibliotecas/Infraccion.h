//
// Created by carlo on 5/13/2026.
//

#ifndef LAB6_2025_1_INFRACCION_H
#define LAB6_2025_1_INFRACCION_H
#include <iosfwd>


class Infraccion {
private:
    int codigo;
    char* descripcion;
    char* gravedad;
    double multa;
public:
    // Constructores
    Infraccion();
    ~Infraccion();
    Infraccion(const Infraccion& orig);
    void operator=(const Infraccion& orig);

    void setCodigo(int cod);
    int getCodigo() const;

    void setDescripcion(const char* desc);
    void getDescripcion(char* desc);

    void setGravedad(const char* grav);
    void getGravedad(char* grav);

    void setMulta(double mul);
    double getMulta() const;
};
void operator >> (ifstream& arch, Infraccion& infraccion);
void operator << (ofstream& arch, Infraccion& infraccion);

#endif //LAB6_2025_1_INFRACCION_H
