#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <vector>
using namespace std;

#include "SistemaDeGestion.h"

void SistemaDeGestion::cargaCategorias(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    Categoria temp;
    while (true) {
        arch >> temp;
        if (arch.eof()) break;
        categorias.push_back(temp);
    }
    categorias.sort();
}

void SistemaDeGestion::cargaComentarios(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    Comentario temp;
    while (true) {
        arch >> temp;
        if (arch.eof()) break;
        comentarios.push_back(temp);
    }
    comentarios.sort();
}

void SistemaDeGestion::cargaEtiquetas(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    Etiqueta temp;
    while (true) {
        arch >> temp;
        if (arch.eof()) break;
        etiquetas[temp.getCodigo()] = temp;
    }
}

void SistemaDeGestion::cargaStreamers(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    Streamer temp;
    while (true) {
        arch >> temp;
        if (arch.eof()) break;
        streamers.push_back(temp);
    }
}

void SistemaDeGestion::completarStreamers() {
}

void SistemaDeGestion::mostrarReporte(const char *nombArch) const {
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }
}

void SistemaDeGestion::eliminaStreamers(const string &idioma) {
}
