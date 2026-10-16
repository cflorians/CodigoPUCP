#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

#include "Gestor.h"

GestorStreamers::GestorStreamers() {
    data = nullptr;
    dataVista = nullptr;
    cantidadDatos = 0;
    cantidadDatosVista = 0;
}
GestorStreamers::~GestorStreamers() {
    delete[] data;
    delete[] dataVista;
}
void GestorStreamers::cargarDatos(const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    Streamer temp[250];
    Streamer streamer;
    int cantStreamers = 0;

    while (true) {
        streamer.leer_streamer(arch);
        if (arch.eof()) break;
        temp[cantStreamers] = streamer;
        cantStreamers++;
    }

    this->data = new Streamer[cantStreamers];
    for (int i = 0; i < cantStreamers; i++) {
        data[i] = temp[i];
    }
    this->cantidadDatos = cantStreamers;
}
void GestorStreamers::copiarDatos() {
    if (dataVista != nullptr) {
        delete[] dataVista;
        cantidadDatosVista = 0;
    }
    dataVista = new Streamer[cantidadDatos];
    for (int i = 0; i < cantidadDatos; i++) {
        dataVista[i] = data[i];
    }
    cantidadDatosVista = cantidadDatos;
}
void GestorStreamers::cortarDatos(int cant) {
    if (dataVista != nullptr) {
        Streamer *nuevo = new Streamer[cant];
        for (int i = 0; i < cant; i++) {
            nuevo[i] = dataVista[i];
        }
        delete[] dataVista;
        dataVista = nuevo;
        cantidadDatosVista = cant;
    }
}
void GestorStreamers::top10seguidores() {
    copiarDatos();
    qsort(dataVista, cantidadDatosVista, sizeof(Streamer), compararSeguidores);
    cortarDatos(10);
    mostrarDataVista();
}
void GestorStreamers::bottom10Tiempo() {
    copiarDatos();
    qsort(dataVista, cantidadDatosVista, sizeof(Streamer), compararTiempo);
    cortarDatos(10);
    mostrarDataVista();
}
void GestorStreamers::top5Categorias() {
    struct CategoriaResumen {
        char categoria[50];
        double sumaEspectadores;
    };

    // Arreglo temporal para guardar categorías únicas
    CategoriaResumen* resumen = new CategoriaResumen[cantidadDatos];
    int cantCategoriasUnicas = 0;

    // 1. Agrupar y Sumar
    for (int i = 0; i < cantidadDatos; i++) {
        char* catActual = data[i].getCategoria();
        bool encontrado = false;

        for (int j = 0; j < cantCategoriasUnicas; j++) {
            if (strcmp(resumen[j].categoria, catActual) == 0) {
                resumen[j].sumaEspectadores += data[i].getPromedio(); // Suma el promedio actual al total de la categoría
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            strcpy(resumen[cantCategoriasUnicas].categoria, catActual);
            resumen[cantCategoriasUnicas].sumaEspectadores = data[i].getPromedio();
            cantCategoriasUnicas++;
        }
    }

    // 2. Ordenar el arreglo de RESUMEN, no el de streamers
    qsort(resumen, cantCategoriasUnicas, sizeof(CategoriaResumen), compararCategoria);

    // 3. Imprimir los resultados
    cout << endl << "TOP 5 CATEGORIAS CON MAYOR SUMA DE ESPECTADORES:" << endl;
    cout << left << setw(25) << "CATEGORIA" << right << setw(15) << "TOTAL PROM." << endl;
    cout << "--------------------------------------------------------" << endl;

    int tope = (cantCategoriasUnicas < 5) ? cantCategoriasUnicas : 5;
    for (int i = 0; i < tope; i++) {
        cout << left << setw(25) << resumen[i].categoria
             << right << setw(15) << fixed << setprecision(2) << resumen[i].sumaEspectadores << endl;
    }

    delete[] resumen;
}
void GestorStreamers::reportePorCategoria() {

}
void GestorStreamers::reporteInfluencia() {

}
void GestorStreamers::top10seguidores(const char*) {

}
void GestorStreamers::bottom10Tiempo(const char*) {

}
void GestorStreamers::top5Categorias(const char*) {

}
void GestorStreamers::reportePorCategoria(const char*) {

}
void GestorStreamers::reporteInfluencia(const char*) {

}
void GestorStreamers::mostrarMenu() {
    char seleccion;
    int subseleccion;
    char categoria[50];
    while (true) {
        cout << "a) Cargar Datos" << endl;
        cout << "b) Mostrar Reporte" << endl; // se muestra en consola
        cout << "c) Generar Reporte" << endl; // se muestra en archivo
        cout << "d) Generar Todos los Reportes" << endl;
        cout << "e) Terminar" << endl;
        cin >> seleccion;
        if (seleccion == 'e') break;
        switch (seleccion) {
        case 'a':
            cargarDatos("Archivos/streamers.csv");
            break;
        case 'b':
        case 'c':
            cout << "1) Reporte Top10 streamers por numero de seguidores." << endl;
            cout << "2) Reporte Bottom10 streamers por tiempo total transmitido." << endl;
            cout << "3) Reporte Top5 categorias con mayor promedio de espectadores." << endl;
            cout << "4) Reporte de Categoría" << endl;
            cout << "5) Reporte de Influencia" << endl;
            cin >> subseleccion;
            switch (subseleccion) {
                case 1:
                if (seleccion == 'b') {
                    top10seguidores();
                }
                else {
                    top10seguidores("Reportes/Top10Seguidores");
                }
                break;
                case 2:
                if (seleccion == 'b') {
                    bottom10Tiempo();
                }
                else {
                    bottom10Tiempo("Reportes/Bottom10Tiempo");
                }
                break;
                case 3:
                if (seleccion == 'b') {
                    top5Categorias();
                }
                else {
                    top5Categorias("Reportes/Top5Categorias");
                }
                break;
                case 4:
                cout << "Que categoria?" << endl;
                cin >> categoria;
                if (seleccion == 'b') {
                    reportePorCategoria();
                }
                else {
                    reportePorCategoria("Reportes/PorCategoria");
                }
                break;
                case 5:
                if (seleccion == 'b') {
                    reporteInfluencia();
                }
                else {
                    reporteInfluencia("Reportes/Influencia");
                }
                break;
                default:
                cout << "No es una seleccion valida" << endl;
            }
            break;
        case 'd':
            top10seguidores("Reportes/Top10Seguidores");
            bottom10Tiempo("Reportes/Bottom10Tiempo");
            top5Categorias("Reportes/Top5Categorias");
            reportePorCategoria("Reportes/PorCategoria");
            reporteInfluencia("Reportes/Influencia");
            break;
        default:
            cout << "No es una seleccion valida" << endl;
        }
    }

}
void GestorStreamers::mostrarDataVista() {
    cout << "  Canal         Categoria         TiempoTotal   Prom   #Seguidores" << endl;
    for (int i = 0; i < cantidadDatosVista; i++) {
        dataVista[i].mostrar_streamer();
    }
}
void GestorStreamers::mostrarDataVista(ofstream& arch) {
    arch << "  Canal         Categoria         TiempoTotal   Prom   #Seguidores" << endl;
    for (int i = 0; i < cantidadDatosVista; i++) {
        dataVista[i].mostrar_streamer(arch);
    }
}

int GestorStreamers::compararSeguidores(const void* a, const void* b) {
    Streamer* sA = (Streamer*)a;
    Streamer* sB = (Streamer*)b;

    int diff = sB->getNSeguidores() - sA->getNSeguidores();

    if (diff < 0) return -1; // como va en orden descendente el mayor va primero
    if (diff > 0) return 1;
    return 0;
}
int GestorStreamers::compararTiempo(const void* a, const void* b) {
    Streamer* sA = (Streamer*)a;
    Streamer* sB = (Streamer*)b;

    long long int diff = sA->getTiempoTotal() - sB->getTiempoTotal();

    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}
int GestorStreamers::compararEspectadores(const void* a, const void* b) {
    Streamer* sA = (Streamer*)a;
    Streamer* sB = (Streamer*)b;

    double diff = sB->getPromedio() - sA->getPromedio();

    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}
int GestorStreamers::compararCategoria(const void* a, const void* b) {
    struct CategoriaResumen {
        char categoria[50];
        double sumaEspectadores;
    };

    CategoriaResumen* catA = (CategoriaResumen*)a;
    CategoriaResumen* catB = (CategoriaResumen*)b;

    if (catB->sumaEspectadores > catA->sumaEspectadores) return 1;
    if (catB->sumaEspectadores < catA->sumaEspectadores) return -1;
    return 0;
}
int GestorStreamers::compararInfluencia(const void* a, const void* b) {
    Streamer* sA = (Streamer*)a;
    Streamer* sB = (Streamer*)b;

    long double influenciaA = (sA->getPromedio()*sA->getTiempoTotal())/log(sA->getNSeguidores());
    long double influenciaB = (sB->getPromedio()*sB->getTiempoTotal())/log(sB->getNSeguidores());

    long double diff = influenciaB - influenciaA;

    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}

