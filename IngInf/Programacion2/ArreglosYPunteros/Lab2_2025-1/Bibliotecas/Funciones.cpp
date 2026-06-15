#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

#define INCREMENTO 2;

#include "Conductores.h"
#include "Infracciones.h"
#include "Faltas.h"

#include "Funciones.h"

void operator += (Conductores& conductores, const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    // 12270502,CUEVA FUENTES CINTHIA DELIA
    int dnis[115]{};
    char nombre[50]{};
    char* nombres[115]{};
    int cant = 0;

    while (true) {
        arch >> dnis[cant];
        arch.get();
        arch.get(nombre, 50, '\n');

        nombres[cant] = new char[strlen(nombre) + 1];
        strcpy(nombres[cant], nombre);

        if (arch.eof()) break;
        cant++;
    }

    conductores.dnis = new int[cant + 1];
    conductores.nombres = new char*[cant + 1];

    for (int i = 0; i < cant; i++) {
        conductores.dnis[i] = dnis[i];
        conductores.nombres[i] = nombres[i];
    }
    conductores.cantidad = cant;
}

void operator += (Infracciones& infracciones, const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    // 101,Adelantar o sobrepasar en forma indebida a otro veh�culo.,Grave,316.00
    int codigos[120]{};
    char descripcion[200]{}, * descripciones[120]{};
    char tipo[20]{}, *tipos[120]{};
    double valores[120]{};
    int cant = 0;

    while (true) {
        arch >> codigos[cant];
        arch.get();
        arch.getline(descripcion, 200, ',');
        arch.getline(tipo, 20, ',');
        arch >> valores[cant];

        descripciones[cant] = new char[strlen(descripcion) + 1];
        strcpy(descripciones[cant], descripcion);

        tipos[cant] = new char[strlen(tipo) + 1];
        strcpy(tipos[cant], tipo);

        if (arch.eof()) break;
        cant++;
    }

    infracciones.codigos = new int[cant + 1];
    infracciones.descripciones = new char*[cant + 1];
    infracciones.tipos = new char*[cant + 1];
    infracciones.valores = new double[cant + 1];

    for (int i=0; i < cant; i++) {
        infracciones.codigos[i] = codigos[i];
        infracciones.descripciones[i] = descripciones[i];
        infracciones.tipos[i] = tipos[i];
        infracciones.valores[i] = valores[i];
    }
    infracciones.cantidad = cant;
}

void cargar_faltas_de_los_conductores(Faltas& faltas) {
    ifstream arch("Archivos/Faltas.csv", ios::in);
    if (not arch.is_open()) exit(1);

    // Cargar los datos base (Pregunta 1)
    faltas.conductores += "Archivos/Conductores.csv";
    faltas.infracciones += "Archivos/Infracciones.csv";

    // INICIALIZACIÓN: Placas y capacidades según n conductores
    int n = faltas.conductores.cantidad;
    faltas.placas = new char**[n]{};      // Cada posición es un char** en nullptr
    faltas.capacidades = new int[n]{};    // Cada posición inicia con 0 placas

    int dni, codInfraccion, indiceConductor;
    char placa[8], fecha[11];

    while (arch >> dni) {
        arch.get(); // saltar coma
        arch.getline(placa, 8, ',');
        arch.getline(fecha, 11, ',');
        arch >> codInfraccion;

        indiceConductor = buscarConductor(dni, faltas.conductores);
        if (indiceConductor != -1) {
            // Pasamos el índice del conductor encontrado
            colocarPlaca(placa, indiceConductor, faltas);
        }
    }
}

int buscarConductor(int dni, Conductores conductores) {
    for (int i = 0; i < conductores.cantidad; i++) {
        if (conductores.dnis[i] == dni) return i;
    }
    return -1;
}

void incrementarCapacidad(int& capacidad, int& cant, Faltas& faltas) {
    capacidad += INCREMENTO;
    char*** auxPlacas;
    int* auxCapacidades;
    if (faltas.placas == nullptr or faltas.capacidades == nullptr) {
        faltas.placas = new char**[capacidad]{};
        faltas.capacidades = new int[capacidad]{};
        cant++;
    }
    else {
        auxPlacas = new char**[capacidad]{};
        auxCapacidades = new int[capacidad]{};
        for (int i=0; i < cant; i++) {
            auxPlacas[i] = faltas.placas[i];
            auxCapacidades[i] = faltas.capacidades[i];
        }
        delete[] faltas.placas;
        delete[] faltas.capacidades;

        faltas.placas = auxPlacas;
        faltas.capacidades = auxCapacidades;
    }
}

// En Funciones.cpp
void colocarPlaca(char* placa, int i, Faltas& faltas) {
    // 1. Extraemos el puntero a las placas del conductor i
    char** ptrPlacasConductor = faltas.placas[i];
    int numPlacas = 0;

    // 2. Contamos cuántas placas tiene ya registradas
    if (ptrPlacasConductor != nullptr) {
        while (ptrPlacasConductor[numPlacas] != nullptr) {
            // Verificamos si la placa ya existe para no duplicar
            if (strcmp(ptrPlacasConductor[numPlacas], placa) == 0) return;
            numPlacas++;
        }
    }

    // 3. Si la cantidad de placas llegó al límite de la capacidad actual del conductor
    if (numPlacas == faltas.capacidades[i]) {
        // Llamamos al incremento pasando la referencia del puntero dentro del arreglo triple
        incrementarCapacidad(faltas.capacidades[i], numPlacas, faltas.placas[i]);
        // IMPORTANTE: Actualizamos nuestra variable local con la nueva dirección de memoria
        ptrPlacasConductor = faltas.placas[i];
    }

    // 4. Reservamos memoria para la cadena de la placa y la copiamos
    // Aquí usamos un solo índice sobre ptrPlacasConductor
    ptrPlacasConductor[numPlacas] = new char[strlen(placa) + 1];
    strcpy(ptrPlacasConductor[numPlacas], placa);
}

// En Funciones.cpp
void incrementarCapacidad(int& capacidad, int& cant, char**& placas) {
    int nuevaCapacidad = capacidad + 2; // Incremento de 2 según el PDF
    char** auxPlacas = new char*[nuevaCapacidad]{}; // El {} inicializa todo en nullptr

    if (placas != nullptr) {
        for (int i = 0; i < cant; i++) {
            auxPlacas[i] = placas[i]; // Copiamos los punteros existentes
        }
        delete[] placas; // Liberamos el arreglo de punteros anterior
    }

    placas = auxPlacas; // Asignamos el nuevo bloque a la estructura
    capacidad = nuevaCapacidad;
}