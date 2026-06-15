#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Funciones.h"

enum REGLISTA {DATO, SIGUIENTE};
enum REGISTRO {DNI, NOMBRE, EDAD, GENERO};

void crearLista(void*& lista,void* (*leer)(ifstream&), int (*comparar)(const void*, const void*),
                const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    void* dato;
    while (true) {
        dato = leer(arch);
        if (arch.eof()) break;
        insertarEnOrden(lista, dato, comparar);
    }
}

void* leerDato(ifstream& arch) {
    void** reg = new void*[4];
    int* dni = new int, *edad = new int;
    char* nombre, *genero;

    // 30001001,H. Glasspool,69,M
    arch >> *dni;
    if (arch.eof()) return nullptr;
    arch.get();
    nombre = leerCadenaExacta(arch, ',');
    arch >> *edad;
    arch.get();
    genero = leerCadenaExacta(arch, '\n');

    reg[DNI] = dni;
    reg[NOMBRE] = nombre;
    reg[EDAD] = edad;
    reg[GENERO] = genero;
    return reg;
}

char* leerCadenaExacta(ifstream& arch, char limit) {
    char cadena[100];
    char* cadenaExacta;
    arch.getline(cadena, 100, limit);
    cadenaExacta = new char[strlen(cadena) + 1];
    strcpy(cadenaExacta, cadena);
    return cadenaExacta;
}

void insertarEnOrden(void*& lista,void* dato,int (*comparar)(const void*, const void*)) {

    // Inicializar punteros necesarios
    void** recorrido = (void**)lista;
    void** anterior = nullptr;

    // Creamos el nuevo nodo
    void** nuevo = new void*[2];
    nuevo[DATO] = dato;
    nuevo[SIGUIENTE] = nullptr;

    // Recorremos la lista
    while (recorrido) {
        if (comparar(dato, recorrido[DATO]) < 0) break;
        anterior = recorrido;
        recorrido = (void**)recorrido[SIGUIENTE];
    }

    // Ya que tenemos el lugar donde ira, lo insertamos
    nuevo[SIGUIENTE] = recorrido;
    if (anterior) anterior[SIGUIENTE] = nuevo;
    else lista = nuevo;
}

int compararNombre(const void* a, const void* b) {
    void** ptrA = (void**)a;
    void** ptrB = (void**)b;
    char* nombA = (char*) ptrA[NOMBRE];
    char* nombB = (char*) ptrB[NOMBRE];
    // cout << "Nombre A: " << nombA << endl;
    // cout << "Nombre B: " << nombB << endl;
    if (strcmp(nombA, nombB) < 0 ) return -1;
    if (strcmp(nombA, nombB) > 0) return 1;
    else return 0;
}

void imprimirLista(void* lista, void (*imprime)(void*, ofstream&) ,const char* nombArch) {
    ofstream arch(nombArch, ios::out);
    void** pacientes = (void**)lista;
    for (int i = 0; pacientes; i++) {
        imprime(pacientes[DATO], arch);
        pacientes = (void**)pacientes[SIGUIENTE];
    }
}

void imprimirDato(void* dato, ofstream& arch) {
    void** paciente = (void**)dato;
    arch << *(int*)paciente[DNI] << "    ";
    arch << setw(5) << left << setw(20) << (char*)paciente[NOMBRE];
    arch << setw(2) << right << *(int*)paciente[EDAD] << setw(5) << " ";
    arch << left << (char*)paciente[GENERO];
    arch << endl;
}

int compararEdades(const void* a, const void* b) {
    void** ptrA = (void**)a;
    void** ptrB = (void**)b;
    int* edadA = (int*)ptrA[EDAD];
    int* edadB = (int*)ptrB[EDAD];
    if (*edadA < *edadB) return -1;
    if (*edadA > *edadB) return 1;
    else return 0;
}

int compararDni(const void* a, const void* b) {
    void** ptrA = (void**)a;
    void** ptrB = (void**)b;
    int* dniA = (int*)ptrA[DNI];
    int* dniB = (int*)ptrB[DNI];
    if (*dniA < *dniB) return -1;
    if (*dniA > *dniB) return 1;
    else return 0;
}

void invertirLista(void*& lista) {
    // Inicializamos 3 punteros, uno para recorrer y 2 para almacenar
    void** actual = (void**) lista;
    void** anterior = nullptr;
    void** posterior = nullptr;

    while (actual) {
        // Guardamos el siguiente a actual para no perder el enlace
        posterior = (void**)actual[SIGUIENTE];
        // Ahora hacemos que actual apunte al nodo anterior para invertir la lista
        actual[SIGUIENTE] = anterior;
        // Establecemos el anterior como el nodo actual antes de avanzar
        anterior = actual;
        // Avanzamos en la lista
        actual = posterior;
    }
    // Como anterior es el unico que queda vivo, ahi apuntamos la lista
    lista = anterior;
}

void invertirListaRecursivo(void*&lista) {
    void** inicio = (void**) lista;
    // CASO BASE
    // Si el siguiente de inicio es null, es porque solo hay un elemento y eso no nos sirve
    // Nos detenemos justo cuando nos quedan 2 elementos
    if (inicio == nullptr or inicio[SIGUIENTE] == nullptr) return;

    // Definimos recorrido como inicio[SIGUIENTE];
    void * recorrido = inicio[SIGUIENTE];
    // PARTE RECURSIVA
    // Como pasamos recorrido como parametro, se actualiza mientras subimos
    invertirListaRecursivo(recorrido);

    // Aca empezamos a subir en la recursión
    // Guardamos ese inicio[SIGUIENTE] en un puntero
    void ** posterior = (void**) inicio[SIGUIENTE];
    // Mientras subimos, posterior se vuelve la cola de la lista ya invertida, por lo que lo
    // haremos apuntar a inicio para que la lista se siga invirtiendo
    posterior[SIGUIENTE] = inicio;
    // Para que inicio[SIGUIENTE] deje de de apuntar a posterior y no quede en una lista circular
    // hacemos que apunte a nullptr
    inicio[SIGUIENTE] = nullptr;
    // Actualizamos la cabeza de la lista, que sera recorrido, que luego de entrar
    // se encuentra al final de la lista
    lista = recorrido;
    // subimos en la parte recursiva
}