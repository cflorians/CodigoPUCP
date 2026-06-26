//
// Created by Carlos on 25/06/2026.
//

#ifndef LAB9_2025_1_EMPRESA_H
#define LAB9_2025_1_EMPRESA_H


class Empresa {
private:
    int dni;
    string nombre;
    string distrito;
    map<string, class Vehiculo> vehiculos;
    vector<class Multa> multasRecibidas;
public:
    void setDni(int num);
    void setNombre(const string& nomb);
    void setDistrito(const string& dist);
    void insertarVehiculo(const class Vehiculo& v);
    void insertarMulta(const class Multa& m);

    int getDni() const;
    string getNombre() const;
    string getDistrito() const;

    bool operator < (const Empresa& e) const;
};
ifstream& operator >> (ifstream& arch, Empresa& e);
ofstream& operator << (ofstream& arch, const Empresa& e);


#endif //LAB9_2025_1_EMPRESA_H
