//
// Created by Carlos on 25/06/2026.
//

#ifndef LAB9_2025_1_VEHICULO_H
#define LAB9_2025_1_VEHICULO_H

class Vehiculo {
private:
    string placa;
    string marca;
    string modelo;
public:
    void setPlaca(const string &plac);
    void setMarca(const string &marc);
    void setModelo(const string &mod);
    string getPlaca() const;
    string getMarca() const;
    string getModelo() const;
};
ifstream& operator >> (ifstream& arch, Vehiculo& vehiculo);

#endif //LAB9_2025_1_VEHICULO_H
