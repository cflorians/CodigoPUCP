//
// Created by carlo on 11/28/2025.
//

#ifndef FINAL_2024_2_ATENCION_H
#define FINAL_2024_2_ATENCION_H

#include "Plato.h"
#include "Comentario.h"

struct Atencion {
    int codigo;
    struct Plato *platos_atendidos;
    int cantidad_platos;
    double total_venta;
    int hora;
    struct Comentario comentarios[20];
    int cantidad_comentarios;
};

#endif //FINAL_2024_2_ATENCION_H