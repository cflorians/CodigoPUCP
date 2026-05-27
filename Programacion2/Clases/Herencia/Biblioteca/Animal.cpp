//
// Created by Carlos on 5/27/2026.
//

#include <cstring>
#include <iostream>
using namespace std;

#include "Animal.h"

Animal::Animal() {
    nombre = nullptr;
    edad = 0;
    peso = 0;
}

Animal::~Animal() {
    if (nombre) delete[] nombre;
    edad = 0;
    peso = 0;
    cout << "Destruyendo a animal" << endl;
}

Animal::Animal(const char *nomb, int ed, double pe) {
    nombre = nullptr;
    edad = ed;
    peso = pe;
    setNombre(nomb);
}

Animal::Animal(const Animal &ani) {
    nombre = nullptr;
    edad = 0;
    peso = 0;
    *this = ani;
}

void Animal::operator=(const Animal &ani) {
    setNombre(ani.nombre);
    setEdad(ani.edad);
    setPeso(ani.peso);
}

void Animal::setNombre(const char *nomb) {
    if (nombre) delete[] nombre;
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre, nomb);
}

void Animal::getNombre(char *nomb) {
    if (nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb, nombre);
}

void Animal::setEdad(int ed) {
    edad = ed;
}

int Animal::getEdad() const {
    return edad;
}

void Animal::setPeso(double pe) {
    peso = pe;
}

double Animal::getPeso() const {
    return peso;
}

void Animal::mostrar() {
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << " anios" << endl;
    cout << "Peso: " << peso << " kg" << endl;
}
