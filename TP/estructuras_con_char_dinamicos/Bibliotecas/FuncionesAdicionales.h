//
// Created by carlo on 11/17/2025.
//

#ifndef ESTRUCTURAS_CON_CHAR_DINAMICOS_FUNCIONESADICIONALES_H
#define ESTRUCTURAS_CON_CHAR_DINAMICOS_FUNCIONESADICIONALES_H

void leerEmpleados(struct Persona *empleados, int& cantEmpleados);
void toMayus(char* cadena);
char* insertarCadena(char* cadena);
void ordenarPorDni(struct Persona *empleados, int cantEmpleados);
void mostrar(const struct Persona *empleados, int cantEmpleados);
void ordenarPorSueldo(struct Persona *empleados, int cantEmpleados);

#endif //ESTRUCTURAS_CON_CHAR_DINAMICOS_FUNCIONESADICIONALES_H