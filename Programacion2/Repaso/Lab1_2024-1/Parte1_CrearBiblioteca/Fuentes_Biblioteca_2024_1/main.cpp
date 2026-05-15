#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "Bibliotecas/Funciones.h"
#include "Bibliotecas/Estructuras.h"

int main(int argc, char** argv) {
    
    struct Libro libro{};
    struct Cliente cliente{};

    ifstream archClientes("Archivos/Cientes.csv", ios::in);
    if (not archClientes.is_open()) {
        cout << "Error al abrir clientes.csv" << endl;
        exit(1);
    }
    archClientes >> cliente;
    cout << cliente.nombre << endl;

    ifstream archLibros("Archivos/Libros.csv", ios::in);
    if (not archLibros.is_open()) {
        cout << "Error al abrir libros.csv" << endl;
        exit(1);
    }

    archLibros >> libro;
    cout << libro.autor << endl;

    return 0;
}
