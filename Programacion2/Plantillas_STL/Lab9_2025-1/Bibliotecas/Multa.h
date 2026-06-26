//
// Created by Carlos on 25/06/2026.
//

#ifndef LAB9_2025_1_MULTA_H
#define LAB9_2025_1_MULTA_H

class Multa {
private:
    int fecha;
    string placa;
    string codMulta;
    double multa;
    bool pagada;
    int fechaDePago;
public:
    Multa();

    void setFecha(int fec);
    void setPlaca(const string& placa);
    void setCodMulta(const string& codMul);
    void setMulta(double mult);
    void setPagada(bool pag);
    void setFechaDePago(int fec);

    int getFecha() const;
    string getPlaca() const;
    string getCodMulta() const;
    double getMulta() const;
    bool getPagada() const;
    int getFechaDePago() const;
};
ifstream& operator>> (ifstream& in, Multa& multa);


#endif //LAB9_2025_1_MULTA_H
