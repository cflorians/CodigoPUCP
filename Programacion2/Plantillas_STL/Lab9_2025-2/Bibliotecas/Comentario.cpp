#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#include "Comentario.h"

Comentario::Comentario() {
    canal = "";
    comentario = "";
}

Comentario::~Comentario() {
    canal = "";
    comentario = "";
}

Comentario::Comentario(const Comentario &org) {
    canal = "";
    comentario = "";
    *this = org;
}

Comentario & Comentario::operator=(const Comentario &org) {
    if (this != &org) {
        canal = org.canal;
        comentario = org.comentario;
    }
    return *this;
}

void Comentario::setCanal(const string &can) {
    canal = can;
}

void Comentario::setComentario(const string &co) {
    comentario = co;
}

string Comentario::getCanal() const {
    return canal;
}

string Comentario::getComentario() const {
    return comentario;
}

void Comentario::leer(ifstream &arch) {
    // LosPollosTV,reds
    // codCanal, comentario
    getline(arch, canal, ',');
    if (arch.eof()) return;
    getline(arch, comentario);
}

void Comentario::imprimir(ofstream &arch) const {
    arch << comentario << endl;
}

bool Comentario::operator<(const Comentario &coment) const {
    return canal < coment.canal;
}

ifstream & operator>>(ifstream &arch, Comentario &comentarios) {
    comentarios.leer(arch);
    return arch;
}

ofstream & operator<<(ofstream &arch, const Comentario &comentarios) {
    comentarios.imprimir(arch);
    return arch;
}
