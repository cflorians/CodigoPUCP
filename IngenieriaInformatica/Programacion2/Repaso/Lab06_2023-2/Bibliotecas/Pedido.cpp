#include <cstring>
#include <fstream>
using namespace std;
#include "Pedido.h"

Pedido::Pedido() {
    codigo = nullptr;
    dni_cliente = 0;
    precio_producto = 0;
}
Pedido::~Pedido() {
    if (codigo) delete[] codigo;
    dni_cliente = 0;
    precio_producto = 0;
}
void Pedido::setCodigo(char* cod) {
    if (codigo) delete[] codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo, cod);
}
void Pedido::getCodigo(char* cod) {
    if (codigo == nullptr) cod[0] = 0;
    else strcpy(cod, codigo);
}
void Pedido::setDniCliente(int d) {
    dni_cliente = d;
}
double Pedido::getDniCliente() const {
    return dni_cliente;
}
void Pedido::setPrecio(double precio) {
    precio_producto = precio;
}
double Pedido::getPrecio() const {
    return precio_producto;
}
bool operator >> (ifstream& arch, Pedido& pedido) {
    // JXD-139,50375303
    // codigo , dniCliente
    char codigo[20];
    int dni;

    arch.getline(codigo, 20, ',');
    if (arch.eof()) return false;
    arch >> dni;
    arch.get();

    pedido.setCodigo(codigo);
    pedido.setDniCliente(dni);

    return true;
}
