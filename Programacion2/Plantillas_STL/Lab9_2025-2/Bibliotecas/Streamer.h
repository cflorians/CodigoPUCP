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
    vector<class Etiqueta> etiquetasVector;
    string idioma;
    vector<string> comentarios;
public:
    void setEtiquetaStr(const string& etiqueta);
    void setFecha(int fech);
    void setIdioma(const string& idioma);
    void setCanal(const string& canal);
    void setCategoria(const Categoria& categoria);
    string getEtiquetaStr() const;
    int getFecha() const;
    string getIdioma() const;
    string getCanal() const;
    Categoria getCategoria() const;

    void insertarEtiqueta(const Etiqueta& etiqueta);
    void insertarComentario(const string& comentario);

    void leer(ifstream& arch);
    void imprimir(ofstream& arch) const;

    bool operator < (const Streamer& str);
};
ifstream& operator>> (ifstream& arch, Streamer& streamers);
ofstream& operator<< (ofstream& arch, const Streamer& streamers);

#endif //LAB9_2025_2_STREAMERS_H
