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

    // map de etiquetas
    // pair<T1, T2> p;
    // p.first;   // clave
    // p.second;  // dato miembro
    // etiqueta.first // la clave
    // etiqueta.second // objeto Etiqueta
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
    string codCat;
    for (Streamer& streamer : streamers) {
        // Actualizamos las categorias
        codCat = streamer.getCategoria().getCodigo();
        for (const Categoria& cat : categorias) {
            if (codCat == cat.getCodigo()) {
                streamer.setCategoria(cat);
                break;
            }
        }
        // Completamos las etiquetas
        string str = streamer.getEtiquetaStr();
        string auxEtiqueta;
        for (int i = 0; i < str.length() ; i+=7) {
            auxEtiqueta = str.substr(i,6);
            auto it = etiquetas.find(auxEtiqueta);

            if (it != etiquetas.end()) {
                streamer.insertarEtiqueta(it->second);
            }
        }
        // Ahora asignamos los comentarios
        string canal = streamer.getCanal();
        for (const Comentario& comentario : comentarios) {
            if (comentario.getCanal() == canal) {
                streamer.insertarComentario(comentario.getComentario());
            }
        }
    }
}

void SistemaDeGestion::mostrarReporte(const char *nombArch) const {
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }
    arch << "========================================================\n";
    arch << setw(36) << "RELACION STREAMERS" << endl;
    for (const Streamer& streamer : streamers) {
        arch << "--------------------------------------------------------\n";
        arch << streamer;
    }
    arch << "========================================================\n";
}

void SistemaDeGestion::eliminaStreamers(const string&idioma) {
    for (auto it = streamers.begin(); it != streamers.end(); ++it) {
        if (it->getIdioma() == idioma) {
            it = streamers.erase(it);
            --it;
        }
    }
}
