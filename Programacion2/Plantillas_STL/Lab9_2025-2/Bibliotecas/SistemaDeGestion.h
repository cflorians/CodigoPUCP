//
// Created by Carlos on 24/06/2026.
//

#ifndef LAB9_2025_2_SISTEMADEGESTION_H
#define LAB9_2025_2_SISTEMADEGESTION_H
#include "Categoria.h"
#include "Comentario.h"
#include "Etiqueta.h"
#include "Streamer.h"

class SistemaDeGestion {
private:
    list<Categoria> categorias;
    list<Comentario> comentarios;
    map<string, Etiqueta> etiquetas;
    list<Streamer> streamers;
public:
    void cargaCategorias(const char* nombArch);
    void cargaComentarios(const char* nombArch);
    void cargaEtiquetas(const char* nombArch);
    void cargaStreamers(const char* nombArch);

    void completarStreamers();
    void mostrarReporte(const char* nombArch) const;

    void eliminaStreamers(const string& idioma);
};

#endif //LAB9_2025_2_SISTEMADEGESTION_H
