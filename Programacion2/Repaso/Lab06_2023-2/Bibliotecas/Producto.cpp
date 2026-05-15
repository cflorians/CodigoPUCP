#include <cstring>
#include <fstream>
using namespace std;
#include "Producto.h"

Producto::Producto() {
    codigo = nullptr;
    descripcion = nullptr;
    precio = 0;
    stock = 0;
    cantidad_clientes_servidos = 0;
    cantidad_clientes_no_servidos = 0;
}
Producto::~Producto() {
    if (codigo) delete[] codigo;
    if (descripcion) delete[] descripcion;
    precio = 0;
    stock = 0;
    cantidad_clientes_servidos = 0;
    cantidad_clientes_no_servidos = 0;
}
void Producto::setCodigo(char* cod) {
    if (codigo) delete[] codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo, cod);
}
void Producto::getCodigo(char* cod) {
    if (codigo == nullptr) cod[0] = 0;
    else strcpy(cod, codigo);
}
void Producto::setDescripcion(char* desc) {
    if (descripcion) delete[] descripcion;
    descripcion = new char[strlen(desc) + 1];
    strcpy(descripcion, desc);
}
void Producto::getDescripcion(char* desc) {
    if (descripcion == nullptr) desc[0] = 0;
    else strcpy(desc, descripcion);
}
void Producto::setPrecio(double prec) {
    precio = prec;
}
double Producto::getPrecio() const {
    return precio;
}
void Producto::setStock(int st) {
    stock = st;
}
int Producto::getStock() const {
    return stock;
}
void Producto::setCantidadServidos(int cantidad) {
    cantidad_clientes_servidos = cantidad;
}
int Producto::getCantidadServidos() const {
    return cantidad_clientes_servidos;
}
void Producto::setCantidadNoServidos(int cantidad) {
    cantidad_clientes_no_servidos = cantidad;
}
int Producto::getCantidadNoServidos() const {
    return cantidad_clientes_no_servidos;
}
bool operator>>(ifstream& arch, Producto& p) {
    // BIT-434,Campana Extractora modelo Glass,375.09,10
    // codigo, descripcion, precio, stock
    char codigo[20];
    char descripcion[100];
    double precio;
    int stock;

    arch.getline(codigo, 20, ',');
    if (arch.eof()) return false;
    arch.getline(descripcion, 100, ',');
    arch >> precio;
    arch.get();
    arch >> stock;

    p.setCodigo(codigo);
    p.setDescripcion(descripcion);
    p.setPrecio(precio);
    p.setStock(stock);

    return true;
}
