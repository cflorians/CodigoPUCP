//
// Created by carlo on 4/29/2026.
//

#ifndef PUNTEROAFUNCIONEJEMPLO_FUNCIONES_H
#define PUNTEROAFUNCIONEJEMPLO_FUNCIONES_H

double sumar(double x, double y);
double restar(double x, double y);
double multiplicar(double x, double y);
double division(double x, double y);
double operator + (const struct Persona& perA, const struct Persona& perB);
double tipoDeCambio(double tipoDeCambio, double montoSoles);
double operacion(double x, double y, double(*funcion)(double, double));
double calcularIGV(double precio);
Persona operator * (const Persona& perA, double (*calcImpuesto)(double));
int compararEnteros(const void* a, const void* b);
void mostrarArreglo(int* arreglo, int n);
void mostrarArreglo(const char** arreglo, int n);
int comparaCadenas(const void* a, const void* b);

void asignarPalabras(char**& palabras);

#endif //PUNTEROAFUNCIONEJEMPLO_FUNCIONES_H
