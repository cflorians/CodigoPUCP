#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "Bibliotecas/Persona.h"
using namespace std;

#include "Bibliotecas/Funciones.h"
#include "Bibliotecas/Persona.h"

int main(int argc, char** argv) {
    
    // Declaro el puntero (el control remoto)
    double (*pFuncion)(double, double);

    // Asigno la dirección de la función al puntero
    pFuncion = sumar;

    //
    double resultado = pFuncion(10.5, 20.5);
    cout << "Llamada a la funcion suma: " << resultado << endl << endl;

    //guardo la direccion en el control
    double a = 23.5, b = 45.7;
    double (*arreglo[4])(double, double);
    arreglo[0] = sumar;
    arreglo[1] = restar;
    arreglo[2] = multiplicar;
    arreglo[3] = division;

    char** palabras;
    asignarPalabras(palabras);

    for (int i = 0; i < 4; i++) {
        cout << palabras[i] << arreglo[i](10, 5) << endl;
    }


    // Declarracion del puntero a funcion
    // este puntero puede apuntar a cualquier funcion que reciba dos parametros
    // y que devuelva un double
    double (*ptPer)(const struct Persona&, const struct Persona&);
    // Asigna la funcion operator + al puntero
    ptPer = operator +; // es importante que en los operadores se añada el operator

    double sumaSueldos = ptPer({1000},{1500});
    cout << endl << "La suma de los sueldos es: " << sumaSueldos << endl;

    double montoSoles = 5000;
    double tipoCambioDolar = 3.43;
    double tipoCambioEuro = 4.11;
    cout << endl;
    cout << "Monto final en dolares: " << operacion(tipoCambioDolar, montoSoles, tipoDeCambio) << endl;
    cout << "Monto final en euros: " << operacion(tipoCambioEuro, montoSoles, tipoDeCambio) << endl;

    Persona profesor{5546.51, 0};
    Persona profesorConImpuesto = profesor*calcularIGV;
    cout << endl;
    cout << "El sueldo del profesor es: " << profesorConImpuesto.sueldo << endl;
    cout << "El impuesto a pagar es:  " << profesorConImpuesto.impuesto << endl;

    // 1. Ordenar un arreglo de Enteros;
    int notas[] = {13,11,15,12,14};
    int n = sizeof(notas)/sizeof(notas[0]); // la cantidad de datos del arreglo

    cout << endl;
    mostrarArreglo(notas, n);
    // ordenamos
    qsort(notas, n, sizeof(int), compararEnteros);
    // mostramos ordenado
    mostrarArreglo(notas, n);

    // 2. Ordenar Nombres (cadenas)
    const char* nombres[] = {"Alvaro", "Zoe", "Jose", "Joaquin"};
    n = sizeof(nombres)/sizeof(nombres[0]);
    cout << endl;
    mostrarArreglo(nombres, n);
    qsort(nombres, n, sizeof(char*), comparaCadenas);
    mostrarArreglo(nombres, n);

    return 0;
}
