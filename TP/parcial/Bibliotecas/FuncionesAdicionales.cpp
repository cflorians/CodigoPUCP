#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "FuncionesAdicionales.h"

void abrirArchivos(ifstream& arch, const char* nombreArch) {
    arch.open(nombreArch, ios::in);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << nombreArch << endl;
        exit(1);
    }
}
void abrirArchivos(ofstream& arch, const char* nombreArch) {
    arch.open(nombreArch, ios::out);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << nombreArch << endl;
        exit(1);
    }
}

void procesarStreams(ifstream& streams,ifstream& canales,ifstream& categorias,ifstream& idiomas,ofstream& reporte) {
    // 803100    1:22:25    4003    C1072
    // codStream duracion   idiom   categoria
    int codStream, duracion, idioma, hh, mm, ss, codCategoria;
    char letCategoria, c;
    int tiempoReproducciones;
    double promRating, promDropOff;

    while (streams >> codStream) {
        streams >> hh >> c >> mm >> c >> ss;
        duracion = hh*3600 + mm*60 + ss;
        streams >> idioma;
        streams >> ws >> letCategoria >> codCategoria;
        mostrarEncabezadoStreams(reporte, idiomas, categorias, codStream, duracion, idioma, letCategoria, codCategoria);
        procesarCanalesPorStream()
    }

}
void procesarCanalesPorStream(ofstream& reporte, ifstream& arch, int codStream, int& tiempoReproducciones, double& promRating, double& promDropOff) {
    // 6/2/2021    A7791    auronplay    678119    16/7/2025    17:52:9    2.35    0.960
    // fecha(no)  codCanal  nomCanal   {codStream    fecha      inicio    rating   dropOff}  {codStream fecha ....}
    int n, cantCanales=0, codCanal, codStreamActual, fechaStream, horaInicio;
    int dd, mm, aa, hh ,min, ss, cantReproduccionesCanal, codCanalAnterior;
    double rating, dropOff;
    char letCanal, c;
    tiempoReproducciones = 0;
    promRating = 0;
    promDropOff = 0;
    while (true) {
        arch >> n >> c >> n >>c >> n;
        arch >> ws >> letCanal >> codCanal;
        ignorarTextoHasta(arch, ' ');
        while (true) {
            leerCodStream(arch,codStreamActual, fechaStream, horaInicio, rating, dropOff);
            if (codStreamActual == codStream) {
                cantCanales++;
                while (arch.peek() != '\n' or arch.peek() != EOF) {

                }
                reporte << setfill('0') << setw(2) << cantCanales;
            }
            if (arch.peek() == '\n') break;
        }
        if (arch.peek() == EOF) break;
    }
}
void leerCodStream(ifstream& arch,int& codStreamActual, int& fechaStream, int& horaInicio, double& rating, double& dropOff) {
    int n, dd, mm ,aa, hh ,min, ss;
    char c;
    arch >> codStreamActual;
    arch >> dd >> c >> mm >> c >> aa;
    fechaStream = aa*10000 + mm*100 + dd;
    arch >> hh >> c >> min >> c >> ss;
    horaInicio = hh*3600 + mm*60 + ss;
    arch >> rating >> dropOff;
}


void mostrarEncabezadoStreams(ofstream& arch, ifstream& idiomas, ifstream& categorias, int codStream, int duracion, int idioma, char letCategoria, int codCategoria) {
    separadorCaracter(arch, '=');
    arch << "STREAM: " << codStream;
    arch << setw(15) << "CATEGORIA: " << letCategoria << codCategoria << " - ";
    buscarMostrarCategoria(arch, categorias, codCategoria, letCategoria);
    arch << "IDIOMA: " << idioma << " - ";
    buscarMostrarIdioma(arch, idiomas, idioma);
    arch << "DURACION: ";
    mostrarDuracion(arch, duracion);
    arch << endl;
    separadorCaracter(arch, '=');
}
void buscarMostrarCategoria(ofstream& arch, ifstream& categorias, int codigo, char letCategoria) {
    // M1000   Just_Chatting
    int codigoActual, n;
    char letCodActual, c;
    categorias.clear();
    categorias.seekg(0, ios::beg);
    while (true) {
        categorias >> letCodActual >> codigoActual;
        if (letCodActual == letCategoria and codigoActual == codigo) {
            mostrarTextoHasta(arch, categorias, '\n', n, true);
            break;
        }
        while (categorias.get() != '\n');
        if (categorias.peek() == EOF) break;
    }
    arch << setw(45-n) << ' ';
}
void buscarMostrarIdioma(ofstream& arch, ifstream& idiomas, int idioma) {
    // 1005   English
    int idiomaActual, n;
    idiomas.clear();
    idiomas.seekg(0, ios::beg);
    while (idiomas >> idiomaActual) {
        if (idiomaActual == idioma) {
            mostrarTextoHasta(arch, idiomas, '\n', n, false);
            break;
        }
        while (idiomas.get() != '\n');
    }
    arch << setw(18-n) << ' ';
}

void ignorarTextoHasta(ifstream& arch, char limitador) {
    arch >> ws;
    while (arch.get() != limitador);
}
void mostrarDuracion(ofstream& reporte, int duracion) {
    int hh, mm, ss;
    hh = duracion / 3600;
    mm = (duracion%3600)/60;
    ss = duracion%60;
    reporte << setfill('0');
    reporte << setw(2) << hh << ":" << setw(2) << mm << ":" << setw(2) << ss;
    reporte << setfill(' ');
}
void mostrarTextoHasta(ofstream& reporte, ifstream& arch, char limitador, int& largo, bool mayus) {
    char c;
    largo=0;
    arch >> ws;
    while (true) {
        arch.get(c);
        if (mayus and ('a' <= c and 'z' >= c)) c -= 'a' - 'A';
        if (c=='_') c=' ';
        reporte << c;
        largo++;
        if (arch.peek() == limitador) break;
    }
}
void mostrarTitulo(ofstream& arch) {
    separadorCaracter(arch, '=');
    arch << "PLATAFORMA DE STREAMING TP" << endl;
    arch << "REPRODUCCION DE STREAMS" << endl;
}
void separadorCaracter(ofstream& arch, char caracter) {
    arch << setfill(caracter);
    arch << setw(140) << caracter << endl;
    arch << setfill(' ');
}
