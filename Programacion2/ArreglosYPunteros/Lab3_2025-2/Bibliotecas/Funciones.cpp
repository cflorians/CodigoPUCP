#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Funciones.h"

#define INCREMENTO 5

enum streamer{CUENTA, SEGUIDORES, CATEGORIA, COMENTARIOS};
enum comentario{CODIGO, EMISOR, RECEPTOR, TEXTO};

void cargarStreamers(void*& strmr) {
    ifstream arch("Archivos/streamers.csv", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir streamers.csv" << endl;
        exit(1);
    }

    void** streamers = nullptr;
    void* reg = nullptr;
    int capacidad = 0;
    int nd = 0;

    // Rubius,2588632635,42948,5751354,BC1084
    while (true) {
        reg = leerRegistro(arch);
        if (arch.eof()) break;
        if (nd == capacidad) incrementarCapacidad(streamers, nd, capacidad);
        streamers[nd-1] = reg;
        nd++;
    }

    strmr = streamers;
}

void* leerRegistro(ifstream& arch) {
    // Rubius,2588632635,42948,5751354,BC1084
    // cuenta, tiempoTotal, promEspectadores, seguidores, categoria
    char *cuenta, *categoria;
    double *tiempoTotal = new double, *promEspectadores = new double, *seguidores = new double;
    double tempTiempo=0, tempEspectadores=0, tempSeguidores=0;
    void** reg = nullptr;
    char c;

    // ahora leemos 1 linea
    // xQcOW,6196161750,27716,3246298,QA1080
    cuenta = obtenerCadenaExacta(arch, ',');
    arch >> tempTiempo >> c >> tempEspectadores >> c >> tempSeguidores >> c;
    categoria = obtenerCadenaExacta(arch, '\n');

    *tiempoTotal = tempTiempo;
    *promEspectadores = tempEspectadores;
    *seguidores = tempSeguidores;

    reg = new void*[4]{};
    reg[CUENTA] = cuenta;
    reg[SEGUIDORES] = seguidores;
    reg[CATEGORIA] = categoria;
    reg[COMENTARIOS] = nullptr;

    return reg;
}

char* obtenerCadenaExacta(ifstream& arch, char limit) {
    char cadena[300]{};
    arch.getline(cadena, 300, limit);
    char* cadenaExacta = new char[strlen(cadena) + 1];
    strcpy(cadenaExacta, cadena);
    return cadenaExacta;
}

void incrementarCapacidad(void**& streamers,int& nd,int& capacidad) {
    void** aux;
    capacidad += INCREMENTO;
    if (streamers == nullptr) {
        streamers = new void*[capacidad]{};
        nd = 1;
    }
    else {
        aux = new void*[capacidad]{};
        for (int i = 0; i < nd ; i++) aux[i] = streamers[i];
        delete streamers;
        streamers = aux;
    }
}

void pruebaStreamers(void* strmr) {
    void** streamers = (void**)strmr;

    for (int i = 0; streamers[i]; i++) {
        imprimirStreamer(streamers[i]);
    }
}

void imprimirStreamer(void* strmr) {
    void** streamer = (void**)strmr;
    char* cuenta = (char*)streamer[CUENTA];
    double* seguidores = (double*)streamer[SEGUIDORES];
    char* categoria = (char*)streamer[CATEGORIA];
    cout << left << setw(15) << cuenta << setw(12) << fixed
         << setprecision(0) << *seguidores << categoria << endl;
}

void cargarComentarios(void*& coment) {
    ifstream arch("Archivos/comentarios.csv", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir comentarios.csv" << endl;
        exit(1);
    }

    //ab7f2910,Can someone please help me understand [Castro_1021 loltyler1]
    //codigo, texto, [emisor receptor]
    void** comentarios = nullptr;
    void* reg = nullptr;
    int capacidad = 0;
    int nd = 0;

    while (true) {
        reg = leerComentario(arch);
        if (arch.eof()) break;
        if (nd == capacidad) incrementarCapacidad(comentarios, nd, capacidad);
        comentarios[nd-1] = reg;
        nd++;
    }

    coment = comentarios;
}

void* leerComentario(ifstream& arch) {
    // ab7f2910,Can someone please help me understand [Castro_1021 loltyler1]
    void** reg = nullptr;
    char* codigo, *texto, *emisor, *receptor;

    codigo = obtenerCadenaExacta(arch, ',');
    texto = obtenerCadenaExacta(arch, '[');
    emisor = obtenerCadenaExacta(arch, ' ');
    receptor = obtenerCadenaExacta(arch, ']');
    arch.get();

    reg = new void*[4]{};
    reg[CODIGO] = codigo;
    reg[EMISOR] = emisor;
    reg[RECEPTOR] = receptor;
    reg[TEXTO] = texto;

    return reg;
}

void pruebaComentarios(void* coment) {
    void** comentarios = (void**)coment;
    for (int i = 0; comentarios[i]; i++) {
        imprimirComentarios(comentarios[i]);
    }
}

void imprimirComentarios(void* coment) {
    void** comentario = (void**)coment;
    char *codigo = (char*)comentario[CODIGO];
    char *emisor = (char*)comentario[EMISOR];
    char *receptor = (char*)comentario[RECEPTOR];
    char *texto = (char*)comentario[TEXTO];

    cout << left << setw(15) << codigo << setw(15) << emisor;
    cout << setw(15) << receptor << texto << endl;
}

void actualizaComentarios(void* strmr,void* coment) {
    // recorregmos streamer por streamer
    void** streamers = (void**)strmr;
    for (int i = 0; streamers[i]; i++) {
        recorrerComentarios(streamers[i], coment);
    }
}

void recorrerComentarios(void* streamer, void* coment) {
    void** comentarios = (void**)coment;
    for (int i = 0; comentarios[i]; i++) {
        if (comparar(streamer, comentarios[i])) {
            asignarComentario(streamer, comentarios[i]);
        }
    }
}

bool comparar(void* strmr,void* coment) {
    void** streamer = (void**)strmr;
    void** comentario = (void**)coment;

    char* cuenta = (char*)streamer[CUENTA];
    char* emisor = (char*)comentario[EMISOR];

    return strcmp(cuenta, emisor) == 0;
}

void asignarComentario(void* strm,void* coment) {
    void** streamer = (void**)strm;
    void** comentario = (void**)coment;

    int nd = obtenerNumeroDeComentarios(streamer[COMENTARIOS]);
    aumentoCapacidadComentarios(streamer[COMENTARIOS], nd);
    void** nuevoComentario = new void*[2]{};
    nuevoComentario[0] = comentario[RECEPTOR];
    nuevoComentario[1] = comentario[TEXTO];

    colocarComentario(streamer[COMENTARIOS], nuevoComentario, nd);
}

void aumentoCapacidadComentarios(void*& streamer,int& nd) {
    void** aux = nullptr;
    void** strmComen = (void**)streamer;
    if (streamer == nullptr) {
        streamer = new void*[2]{};
        nd = 1;
    }
    else {
        aux = new void*[nd + 2]{}; // <- aumento + nuevo + nullptr
        for (int i = 0; i < nd; i++) aux[i] = strmComen[i];
        delete[] strmComen;
        strmComen = aux;
        streamer = strmComen;
        nd++;
    }
}

int obtenerNumeroDeComentarios(void* strmr) {
    void** comentariosCuenta = (void**)strmr;
    int nd = 0;
    if (strmr == nullptr) return 0;
    while (comentariosCuenta[nd] != nullptr) nd++;
    return nd;
}

void colocarComentario(void* strm,void* coment, int nd) {
    void** streamer = (void**)strm;
    char* texto = (char*)coment;
    streamer[nd - 1] = texto;
}

void imprimeStreamers(void* strm) {
    ofstream arch("Reportes/Reporte.txt", ios::out);
    separador(arch, '=');
    void** streamers = (void**)strm;
    for (int i = 0; streamers[i]; i++) {
        imprimirReporteStreamer(streamers[i], arch);
    }
}

void imprimirReporteStreamer(void* strm, ofstream& arch) {
    void** streamer = (void**)strm;
    arch << left << setw(20) << "Cuenta" << "Seguidores" << endl;
    mostrarStreamer(strm, arch);
    separador(arch, '-');
    arch << "Comentarios emitidos:" << endl;
    separador(arch, '-');
    arch << left << setw(20) << "Receptor" << "Texto" << endl;
    separador(arch, '-');
    mostrarComentariosStreamer(streamer[COMENTARIOS], arch);
    separador(arch, '=');
}

void mostrarComentariosStreamer(void* strm,ofstream& arch) {
    if (strm == nullptr) return;

    void** comentariosStreamer = (void**)strm;
    for (int i=0; comentariosStreamer[i]; i++) {
        imprimirComentario(comentariosStreamer[i], arch);
    }
}

void imprimirComentario(void* comentarioStreamer,ofstream& arch) {
    void** comentario = (void**)comentarioStreamer;
    char* receptor = (char*)comentario[0];
    char* texto = (char*)comentario[1];

    arch << left << setw(20) << receptor << texto << endl;
}

void mostrarStreamer(void* strm,ofstream& arch) {
    void** streamer = (void**)strm;
    char* cuenta = (char*)streamer[CUENTA];
    double* seguidores = (double*)streamer[SEGUIDORES];

    arch << left << setw(20) << cuenta;
    arch << fixed << setprecision(0) << *seguidores << endl;
}

void separador(ofstream& arch, char separador) {
    arch << setfill(separador);
    arch << setw(100) << separador << endl;
    arch << setfill(' ');
}