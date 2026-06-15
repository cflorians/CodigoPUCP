//
// Created by carlo on 4/1/2026.
//

#ifndef MEMORIAPORINCREMENTOS_FUNCIONES_H
#define MEMORIAPORINCREMENTOS_FUNCIONES_H

void leerDatosPorIncrementos(int*& datos,int& numDatos, const char* nombArch);
void incrementarLosEspacios(int*& datos,int numDatos,int& capacidad);

void leerDatosPorIncrementos(int*& datos, const char* nombArch);
void incrementarLosEspaciosSin(int*& datos,int& numDatos,int& capacidad);

#endif //MEMORIAPORINCREMENTOS_FUNCIONES_H