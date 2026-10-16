//
// Created by carlo on 5/13/2026.
//

#ifndef LAB6_2025_1_MULTA_H
#define LAB6_2025_1_MULTA_H



class Multa {
private:
    char* placa;
    int fechaInfraccion;
    int fechaPago;
    int codigoInfraccion;
    double multa;
public:
    Multa();
    ~Multa();
    Multa(const Multa& org);
    void operator=(const Multa& org);

    void setPlaca(const char* placa);
    void getPlaca(char* placa) const;

    void setFechaInfraccion(int fecha);
    int getFechaInfraccion() const;

    void setFechaPago(int fecha);
    int getFechaPago() const;

    void setCodigoInfraccion(int codigo);
    int getCodigoInfraccion() const;

    void setMulta(double multa);
    double getMulta() const;
};

void operator >> (ifstream&, Multa&);
int leerFecha(ifstream&);
void operator << (ofstream&, Multa&);


#endif //LAB6_2025_1_MULTA_H
