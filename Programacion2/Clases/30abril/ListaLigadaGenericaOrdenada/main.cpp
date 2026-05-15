#include <iostream>
using namespace std;

#include "Biblioteca/Funciones.h"

int main(int argc, char** argv) {
    
    void* lista = nullptr;
    // Lista ordenada
    // Podemos darle funciones diferentes a comparar
    // Para que cambie el criterio de ordenamiento
    crearLista(lista, leerDato, compararEdades, "Archivos/pacientes.csv");
    imprimirLista(lista, imprimirDato, "Reportes/pruebaPacientes.txt");
    invertirLista(lista);
    imprimirLista(lista, imprimirDato, "Reportes/ListaInvertida.txt");
    
    return 0;
}
