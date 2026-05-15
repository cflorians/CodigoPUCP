#include <cstring>
#include <fstream>
using namespace std;

#include "Cliente.h"
Cliente::Cliente() {
    nombre = nullptr;
    dni = 0;
    telefono = 0;
    cantidad_productos_entregados = 0;
    monto_total = 0;
}
Cliente::~Cliente() {
    if (nombre) delete[] nombre;
    dni = 0;
    telefono = 0;
    cantidad_productos_entregados = 0;
    monto_total = 0;
}
void Cliente::setDni(int dni) {
    this->dni = dni;
}
int Cliente::getDni() const {
    return dni;
}
void Cliente::setNombre(char* nomb) {
    if (nombre) delete[] nombre;
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre, nomb);
}
void Cliente::getNombre(char* nomb) const {
    if (nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb, nombre);
}
void Cliente::setTelefono(int tel) {
    telefono = tel;
}
int Cliente::getTelefono() const {
    return telefono;
}
void Cliente::setMontoTotal(double monto) {
    monto_total = monto;
}
double Cliente::getMontoTotal() const {
    return monto_total;
}

void Cliente::operator+=(Pedido& pedido) {

}

bool operator>>(ifstream& arch, Cliente& cliente) {
    // 79464412,PORTUGAL RAFFO ALEXANDER,3902394
    // dni, nombre, telefono
    int dni, telefono;
    char nombre[100];

    arch >> dni;
    if (arch.eof()) return false;
    arch.get();
    arch.getline(nombre, 100, ',');
    arch >> telefono;

    cliente.setDni(dni);
    cliente.setTelefono(telefono);
    cliente.setNombre(nombre);
    cliente.setMontoTotal(0.0);

    return true;
}
