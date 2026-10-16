//
// Created by Carlos on 24/06/2026.
//

#ifndef LAB9_2025_2_COMENTARIOS_H
#define LAB9_2025_2_COMENTARIOS_H

class Comentario {
private:
    string canal;
    string comentario;
public:
    Comentario();
    ~Comentario();
    Comentario(const Comentario& org);
    Comentario & operator=(const Comentario & org);

    void setCanal(const string& can);
    void setComentario(const string& co);
    string getCanal() const;
    string getComentario() const;

    void leer(ifstream& arch);
    void imprimir(ofstream& arch) const;

    bool operator < (const Comentario& coment) const;
};
ifstream& operator >> (ifstream& arch, Comentario& comentarios);
ofstream& operator << (ofstream& arch, const Comentario& comentarios);

#endif //LAB9_2025_2_COMENTARIOS_H
