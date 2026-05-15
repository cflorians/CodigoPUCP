#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Funciones.h"
#include "Persona.h"

double sumar(double x, double y) {
    return x+y;
}

double restar(double x, double y) {
    return x-y;
}

double multiplicar(double x, double y) {
    return x*y;
}

double division(double x, double y) {
    if (y != 0) return x/y;
}

double operator + (const struct Persona& perA, const struct Persona& perB) {
    return perA.sueldo + perB.sueldo;
}

double tipoDeCambio(double tipoDeCambio, double montoSoles) {
    return montoSoles/tipoDeCambio;
}

double operacion(double x, double y, double(*funcion)(double, double)) {
    return funcion(x,y);
};


void asignarPalabras(char**& palabras) {
    palabras = new char*[4];
    palabras[0] = new char[strlen("Suma: ")+1];
    strcpy(palabras[0], "Suma: ");
    palabras[1] = new char[strlen("Resta: ")+1];
    strcpy(palabras[1], "Resta: ");
    palabras[2] = new char[strlen("Multiplicacion: ")+1];
    strcpy(palabras[2], "Multiplicacion: ");
    palabras[3] = new char[strlen("Division: ")+1];
    strcpy(palabras[3], "Division: ");
}

double calcularIGV(double precio) {
    return precio*0.11;
}

Persona operator * (const Persona& perA, double (*calcImpuesto)(double)) {
    Persona nueva = perA;
    nueva.impuesto = calcImpuesto(nueva.sueldo);
    return nueva;
}

int compararEnteros(const void* a, const void* b) {
    int* numA = (int*)a;
    int* numB = (int*)b;
    if (*numA > *numB) return 1;
    if (*numA < *numB) return -1;
    else return 0;
}

void mostrarArreglo(int* arreglo, int n) {
    for (int i = 0; i < n; i++) {
        if (i == 0) cout << "[";
        if (i != 0) cout << ", ";
        cout << arreglo[i];
        if (i == n - 1) cout << "]" << endl;
    }
}
void mostrarArreglo(const char** arreglo, int n) {
    for (int i = 0; i < n; i++) {
        if (i == 0) cout << "[";
        if (i != 0) cout << ", ";
        cout << arreglo[i];
        if (i == n - 1) cout << "]" << endl;
    }
}

int comparaCadenas(const void* a, const void* b) {
    char** cadA = (char**)a;
    char** cadB = (char**)b;
    if (strcmp(*cadA, *cadB) < 0) return -1;
    if (strcmp(*cadA, *cadB) > 0) return 1;
    return 0;
}