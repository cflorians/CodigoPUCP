#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

#include "Vehiculo.h"

Vehiculo::Vehiculo() {
    marca = nullptr;
    modelo = nullptr;
    color = nullptr;
    anno = 0;
    velocidadActual = 0;
}

Vehiculo::Vehiculo(const Vehiculo& copia) {
    marca = nullptr;
    modelo = nullptr;
    color = nullptr;
    anno = 0;
    velocidadActual = 0;
    *this = copia;
}

void Vehiculo::operator=(const Vehiculo& copia) {
    setMarca(copia.marca);
    setModelo(copia.modelo);
    setColor(copia.color);
    anno = copia.anno;
    velocidadActual = copia.velocidadActual;    
}

Vehiculo::~Vehiculo() {
    if (marca) delete marca;
    if (modelo) delete modelo;
    if (color) delete color;
    velocidadActual = 0;
    anno = 0;
}

void Vehiculo::setMarca(const char* mar) {
    if (marca) delete marca;
    marca = new char[strlen(mar)+1];
    strcpy(marca,mar);
}

void Vehiculo::getMarca(char* mar) const {
    if (marca == nullptr) mar[0] = 0;
    else strcpy(mar,marca);
}

void Vehiculo::setModelo(const char* mod) {
    if (modelo) delete modelo;
    modelo = new char[strlen(mod)+1];
    strcpy(modelo,mod);
}

void Vehiculo::getModelo(char* mod) const {
    if (modelo == nullptr) mod[0] = 0;
    else strcpy(mod,modelo);
}

void Vehiculo::setColor(const char* col) {
    if (color) delete col;
    color = new char[strlen(col)+1];
    strcpy(color,col);
}

void Vehiculo::getColor(char* col) const {
    if (color == nullptr) col[0] = 0;
    else strcpy(col,color);
}

void Vehiculo::set_anno(const int anno) {
    this->anno = anno;
}

int Vehiculo::get_anno() const {
    return anno;
}

void Vehiculo::set_velocidad_actual(const double velocidad_actual) {
    velocidadActual = velocidad_actual;
}

double Vehiculo::get_velocidad_actual() const {
    return velocidadActual;
}

ifstream& operator>>(ifstream& arch, Vehiculo& vehiculo) {
    // NO SON ATRIBUTOS DE LA CLASE
    char* marca;
    char* modelo;
    char* color;
    int anno;
    double velocidad;

    // Hyunday,Nextra,1980,90,Blanco
    marca = leerCadena(arch);
    if (arch.eof()) return arch;
    modelo = leerCadena(arch);
    arch >> anno;
    arch.get();
    arch >> velocidad;
    arch.get();
    color = leerCadena(arch, '\n');

    vehiculo.setMarca(marca);
    vehiculo.setModelo(modelo);
    vehiculo.setColor(color);
    vehiculo.set_velocidad_actual(velocidad);
    vehiculo.set_anno(anno);

    return arch;
}

char* leerCadena(ifstream& arch, char limit) {
    char* cadenaExacta, cadena[100];
    arch.getline(cadena,100,limit);
    cadenaExacta = new char[strlen(cadena)+1];
    strcpy(cadenaExacta,cadena);
    return cadenaExacta;
}

ofstream& operator<<(ofstream& arch ,const Vehiculo& v) {
    char marca[50], modelo[50], color[50];
    int anno;
    double velocidad;
    v.getMarca(marca);
    v.getModelo(modelo);
    v.getColor(color);

    arch << left << setw(15) << marca
         << left << setw(15) << modelo
         << left << setw(10) << color
         << right << setw(7) << v.get_anno()
         << right << fixed << setprecision(2) << setw(8) << v.get_velocidad_actual();
    arch << endl;
    return arch;
}