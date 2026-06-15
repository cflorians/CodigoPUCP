//
// Created by Carlos on 4/06/2026.
//

#ifndef LAB8_2022_2_MEDICO_H
#define LAB8_2022_2_MEDICO_H

class Medico {
private:
    int codigo;
    char* nombre;
    char* especialidad;
public:
    Medico();
    ~Medico();
    Medico(const Medico& org);
    void operator = (const Medico& org);

    void setCodigo(int cod);
    void setNombre(const char* nomb);
    void setEspecialidad(const char* esp);

    int getCodigo() const;
    void getNombre(char* nomb);
    void getEspecialidad(char* espec);
};
void operator >> (ifstream& arch, Medico& medico);

#endif //LAB8_2022_2_MEDICO_H
