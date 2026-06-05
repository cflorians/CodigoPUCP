//
// Created by Carlos on 4/06/2026.
//

#ifndef LAB8_2022_2_MEDICAMENTOS_H
#define LAB8_2022_2_MEDICAMENTOS_H

class Medicamentos {
private:
    int codigo;
    char* nombre;
    int cantidad;
    double precio;
    int fecha; // aaaammdd
public:
    Medicamentos();
    ~Medicamentos();
    Medicamentos(const Medicamentos& org);
    void operator = (const Medicamentos& org);

    void setCodigo(int cod);
    void setNombre(char* nomb);
    void setCantidad(int cant);
    void setPrecio(double prec);
    void setFecha(int fecha);

    int getCodigo() const;

    void getNombre(char* nomb);
    int getCantidad() const;
    double getPrecio() const;
    int getFecha() const;

};

#endif //LAB8_2022_2_MEDICAMENTOS_H
