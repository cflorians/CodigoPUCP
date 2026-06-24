//
// Created by Carlos on 24/06/2026.
//

#ifndef LAB9_2025_2_STREAMERS_H
#define LAB9_2025_2_STREAMERS_H
#include "Categoria.h"
#include "Etiqueta.h"

class Streamer {
private:
    string canal;
    int fecha;
    Categoria categoria;
    string etiquetasStr;
    vector<Etiqueta> etiquetasVector;
    string idioma;
    vector<string> comentarios;
public:
    void setEtiquetaStr(const string& etiqueta);
    void setFecha(int fech);
    void setIdioma(const string& idioma);
    void setCanal(const string& canal);
    string getEtiquetaStr() const;
    int getFecha() const;
    string getIdioma() const;
    string getCanal() const;

    void leer(ifstream& arch);
    void imprimir(ofstream& arch);

    bool operator < (const Streamer& str);
};
ifstream& operator>> (ifstream& arch, Streamer& streamers);
ofstream& operator<< (ofstream& arch, Streamer& streamers);

#endif //LAB9_2025_2_STREAMERS_H
