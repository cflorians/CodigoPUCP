//
// Created by carlo on 4/16/2026.
//

#ifndef LAB2_2025_1_FUNCIONES_H
#define LAB2_2025_1_FUNCIONES_H

void cargar_faltas_de_los_conductores(Faltas& faltas);
int buscarConductor(int dni, Conductores conductores);
void incrementarCapacidad(int& capacidad, int& cant, Faltas& faltas);
void colocarPlaca(char* placa,int i,Faltas& faltas);
void incrementarCapacidad(int& capacidad, int& cant, char**& placas);

void operator += (Conductores& conductores, const char* nombArch);
void operator += (Infracciones& infracciones, const char* nombArch);


#endif //LAB2_2025_1_FUNCIONES_H
