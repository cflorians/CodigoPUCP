#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "CadenaDeCaracteres.h"

#include "Funciones.h"

void operator ! (struct CadenaDeCaracteres& cadena) {
    cadena.cadena = nullptr;
    cadena.capacidad = 0;
    cadena.longitud = 0;
}

void operator <= (struct CadenaDeCaracteres& cadena, const char* texto) {
    cadena.capacidad = strlen(texto)+1;
    cadena.longitud = strlen(texto);
    cadena <= cadena.capacidad;
    strcpy(cadena.cadena, texto);
}

void operator <= (struct CadenaDeCaracteres& cadena, int espacio) {
    cadena.capacidad = espacio;
    cadena.cadena = new char[espacio];
}

void operator <= (struct CadenaDeCaracteres& cad1, struct CadenaDeCaracteres cad2) {
    if (cad1.capacidad == cad2.capacidad) {
        strcpy(cad1.cadena, cad2.cadena);
    }
    else if (cad1.capacidad > cad2.capacidad or cad1.longitud < cad2.capacidad) {
        delete []cad1.cadena;
        cad1 <= cad2.capacidad;
        cad1.longitud = cad2.longitud;
        strcpy(cad1.cadena, cad2.cadena);
    }
    else if (cad1.longitud == 0) {
        cad1.longitud = cad2.longitud;
        cad1 <= cad2.capacidad;
        strcpy(cad2.cadena, cad1.cadena);
    }
}

bool operator += (struct CadenaDeCaracteres& cadena, const char* texto) {

    if (cadena.cadena == nullptr or cadena.longitud == 0) return false;

    int longitudTexto = strlen(texto);
    int nuevaLong = cadena.longitud + longitudTexto;
    if (cadena.capacidad < nuevaLong + 1) {
        int nuevaCapacidad = nuevaLong + 1;

        char* temp = new char[cadena.capacidad];
        strcpy(temp, cadena.cadena);
        delete []cadena.cadena;

        cadena <= nuevaCapacidad;
        strcpy(cadena.cadena, temp);
        delete []temp;
    }
    strcat(cadena.cadena, texto);
    cadena.longitud = nuevaLong;
    return true;
}

bool operator += (struct CadenaDeCaracteres& cad1, const struct CadenaDeCaracteres cad2) {
    if (cad1.cadena == nullptr or cad1.longitud == 0) return false;

    int longitudTexto = cad2.longitud;
    int nuevaLong = cad1.longitud + longitudTexto;
    if (cad1.capacidad < nuevaLong + 1) {
        int nuevaCapacidad = nuevaLong + 1;

        char* temp = new char[cad1.capacidad];
        strcpy(temp, cad1.cadena);
        delete []cad1.cadena;

        cad1 <= nuevaCapacidad;
        strcpy(cad1.cadena, temp);
        delete []temp;
    }
    strcat(cad1.cadena, cad2.cadena);
    cad1.longitud = nuevaLong;
    return true;
}

int compare(const struct CadenaDeCaracteres cad1, const char* texto) {
    int estado = 0;

    char* aux = new char[cad1.capacidad];
    strcpy(aux, cad1.cadena);

    char* auxText = new char[strlen(texto) + 1];
    strcpy(auxText, texto);

    strlwr(aux);
    strlwr(auxText);

    estado = strcmp(aux, auxText);

    delete[] aux;
    delete[] auxText;
    return estado;
}

bool operator == (const struct CadenaDeCaracteres cad1, const char* texto) {
    if (compare(cad1, texto) == 0) return true;
    return false;
}

bool operator > (const struct CadenaDeCaracteres cad1, const char* texto) {
    if (compare(cad1, texto) > 0) return true;
    return false;
}

bool operator < (const struct CadenaDeCaracteres cad1, const char* texto) {
    if (compare(cad1, texto) < 0) return true;
    return false;
}

int compare(const struct CadenaDeCaracteres cad1,const struct CadenaDeCaracteres cad2) {
    int estado = 0;

    char* aux = new char[cad1.capacidad];
    strcpy(aux, cad1.cadena);

    char* auxText = new char[cad2.capacidad];
    strcpy(auxText, cad2.cadena);

    strlwr(aux);
    strlwr(auxText);

    estado = strcmp(aux, auxText);

    delete[] aux;
    delete[] auxText;
    return estado;
}

bool operator == (const struct CadenaDeCaracteres cad1, const struct CadenaDeCaracteres cad2) {
    if (compare(cad1, cad2.cadena) == 0) return true;
    return false;
}

bool operator > (const struct CadenaDeCaracteres cad1, const struct CadenaDeCaracteres cad2) {
    if (compare(cad1, cad2.cadena) > 0) return true;
    return false;
}

bool operator < (const struct CadenaDeCaracteres cad1, const struct CadenaDeCaracteres cad2) {
    if (compare(cad1, cad2.cadena) < 0) return true;
    return false;
}

int operator >> (ifstream& arch, struct CadenaDeCaracteres& cad) {
    char aux[50];
    if (!(arch >> aux)) return 1;
    if (not isalpha(aux[0])) return -1;
    cad <= aux;
    return 0;
}

void operator && (struct CadenaDeCaracteres& cad1, struct CadenaDeCaracteres& cad2) {
    char* aux = new char[cad1.capacidad];
    strcpy(aux, cad1.cadena);

    cad1 <= cad2;
    cad2 <= aux;
}

void operator << (ofstream& arch, struct CadenaDeCaracteres cad) {
    arch << cad.cadena;
}