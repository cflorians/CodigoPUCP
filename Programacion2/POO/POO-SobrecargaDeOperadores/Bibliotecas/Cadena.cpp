//
// Created by carlo on 5/10/2026.
//

#include "Cadena.h"

#include <cstring>
#include <iostream>
using namespace std;

Cadena::Cadena() {
    cadena = nullptr;
    capacidad = 0;
    longitud = 0;
}
Cadena::Cadena(const char* cad) {
    char* nueva;
    longitud = strlen(cad);
    capacidad = longitud + 1;
    nueva = new char [capacidad];
    strcpy(nueva, cad);
    cadena = nueva;
}
Cadena::Cadena(const Cadena& otra) {
    longitud = otra.longitud;
    capacidad = otra.capacidad;
    if (otra.cadena) {
        cadena = new char[capacidad];
        strcpy(cadena, otra.cadena);
    } else {
        cadena = nullptr;
    }
}
Cadena::Cadena(int capacidad) {
    this->capacidad = capacidad;
    longitud = 0;
    cadena = new char [capacidad];
}
void Cadena::operator=(const Cadena& cad) {
    if (this != &cad) { // Evitar auto-asignación
        delete[] this->cadena; // Liberar memoria vieja
        this->longitud = cad.longitud;
        this->capacidad = cad.capacidad;
        this->cadena = new char[capacidad];
        strcpy(this->cadena, cad.cadena);
    }
}

void Cadena::assing(const char* cad) {
    int longCadena = strlen(cad);
    char* nueva = nullptr;
    while (this->capacidad <= longCadena) {
        this->capacidad += (int)(0.3*this->capacidad);
    }
    this->longitud = longCadena;
    nueva = new char [capacidad];
    strcpy(nueva, cad);
    delete[] cadena;
    cadena = nueva;
}
void Cadena::assing(const Cadena& cadOrigen) {
    char* cad = new char[cadOrigen.capacidad];
    assing(cadOrigen.cadena);
}
void Cadena::operator=(const char* cad) {
    longitud = strlen(cad);
    capacidad = longitud + 1;
    cadena = new char[capacidad];
    strcpy(cadena, cad);
}
void Cadena::append(const char* cad) {
    int longTotal = strlen(cadena) + strlen(cad);
    while (this->capacidad <= longTotal) {
        this->capacidad += (int)(0.3*this->capacidad);
    }
    char* nueva = new char[capacidad];
    strcpy(nueva, cadena);
    strcat(nueva, cad);
    delete[] this->cadena;
    this->cadena = nueva;
}
void Cadena::append(const Cadena& cad2) {
    char* cad = cad2.cadena;
    append(cad);
}
void Cadena::swap(Cadena& cad2) {
    char* auxCadena = this->cadena;
    int auxLongitud = this->longitud;

    while (this->capacidad <= cad2.longitud) {
        this->capacidad += (int)(0.3*this->capacidad);
    }
    char* nueva1 = new char[this->capacidad];
    strcpy(nueva1, cad2.cadena);
    this->cadena = nueva1;
    this->longitud = cad2.longitud;

    while (cad2.capacidad <= auxLongitud) {
        cad2.capacidad += (int)(0.3*cad2.capacidad);
    }
    char* nueva2 = new char[cad2.capacidad];
    strcpy(nueva2, auxCadena);
    delete[] auxCadena;
    cad2.cadena = nueva2;
    cad2.longitud = auxLongitud;
}

Cadena Cadena::operator+(const Cadena& cad) const {
    Cadena nueva;
    nueva = this->cadena;
    nueva.append(cad.cadena);
    return nueva;
}

int Cadena::compare(const char* cad) const {
    return strcmp(this->cadena, cad);
}
int Cadena::compare(const Cadena& cad) const {
    return strcmp(this->cadena, cad.cadena);
}
bool Cadena::operator==(const Cadena& cad) const {
    return strcmp(cad.cadena, this->cadena) == 0;
}
bool Cadena::operator>(const Cadena& cad) const {
    return strcmp(cad.cadena, this->cadena) < 0;
}
bool Cadena::operator<(const Cadena& cad) const {
    return strcmp(cad.cadena, this->cadena) > 0;
}
bool Cadena::operator>=(const Cadena& cad) const {
    return strcmp(cad.cadena, this->cadena) >= 0;
}
bool Cadena::operator<=(const Cadena&cad) const {
    return strcmp(cad.cadena, this->cadena) <= 0;
}

int Cadena::length() const {
    return longitud;
}

void Cadena::print() const {
    cout << cadena << endl;
}

Cadena::~Cadena() {
    delete[] cadena;
    cadena = nullptr;
}
