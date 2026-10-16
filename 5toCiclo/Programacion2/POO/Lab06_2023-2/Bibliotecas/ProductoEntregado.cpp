#include <cstring>
#include <fstream>
using namespace std;
#include "ProductoEntregado.h"

ProductoEntregado::ProductoEntregado() {
    codigo = nullptr;
    precio = 0;
}
ProductoEntregado::~ProductoEntregado() {
    if (codigo) delete[] codigo;
    precio = 0;
}
void ProductoEntregado::setCodigo(char* cod) {
    if (codigo) delete[] codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo, cod);
}
void ProductoEntregado::getCodigo(char* cod) const {
    if (codigo != nullptr) cod[0] = 0;
    else strcpy(cod, codigo);
}
void ProductoEntregado::setPrecio(double pre) {
    precio = pre;
}
double ProductoEntregado::getPrecio() const {
    return precio;
}
