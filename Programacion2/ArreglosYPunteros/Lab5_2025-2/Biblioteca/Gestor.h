//
// Created by carlo on 5/11/2026.
//

#ifndef LAB5_2025_2_GESTOR_H
#define LAB5_2025_2_GESTOR_H

#include "Streamer.h"

class GestorStreamers {
private:
    Streamer* data;
    Streamer* dataVista;
    int cantidadDatos;
    int cantidadDatosVista;
public:
    GestorStreamers();
    ~GestorStreamers();

    // Cargar datos
    void cargarDatos(const char*);
    // Manejo dataVista
    void copiarDatos(); // pasamos data a dataVista
    void cortarDatos(int); // redimenciona dataVista

    // Reportes en consola
    void top10seguidores();
    void bottom10Tiempo();
    void top5Categorias();
    void reportePorCategoria();
    void reporteInfluencia();
    // Reportes en archivos
    void top10seguidores(const char*);
    void bottom10Tiempo(const char*);
    void top5Categorias(const char*);
    void reportePorCategoria(const char*);
    void reporteInfluencia(const char*);

    // Mostrar
    void mostrarMenu();
    void mostrarDataVista();
    void mostrarDataVista(ofstream&);

    // Ordenamiento
    static int compararSeguidores(const void*, const void*);
    static int compararTiempo(const void*, const void*);
    static int compararEspectadores(const void*, const void*);
    static int compararCategoria(const void*, const void*);
    static int compararInfluencia(const void*, const void*);
};

#endif //LAB5_2025_2_GESTOR_H
