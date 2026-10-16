#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "FuncionesAdicionales.h"
#include "Comentario.h"
#include "Palabra.h"
#include "Plato.h"
#include "Atencion.h"

void leerLexicon(struct Palabra *lexicon, int& cantLexicon) {
    ifstream arch("ArchivosDeDatos/lexicon.csv", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo de lexicon.csv" << endl;
        exit(1);
    }
    // rapido,1
    char palabra[20];
    int polaridad;

    cantLexicon = 0;
    while (true) {
        arch.getline(palabra, 20,',');
        arch >> polaridad;
        arch.ignore();

        lexicon[cantLexicon].texto = insertarChar(palabra);
        lexicon[cantLexicon].polaridad = polaridad;

        // cout << lexicon[cantLexicon].texto << "   " << lexicon[cantLexicon].polaridad << endl;

        cantLexicon++;

        if (arch.eof()) break;
    }
}

char* insertarChar(char* cadena) {
    char* nueva = new char [strlen(cadena)+1];
    strcpy(nueva, cadena);
    return nueva;
}

void leerPlatos(struct Plato *platos, int& cantPlatos) {
    ifstream arch("ArchivosDeDatos/platos.csv", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo de platos.csv" << endl;
        exit(1);
    }
    // A3H6GJ,Causa de Atun,12.57
    char codigo[10];
    char nombre[50];
    double precio;

    cantPlatos = 0;
    while (true) {
        arch.getline(codigo, 10, ',');
        arch.getline(nombre, 50, ',');
        arch >> precio;
        arch.ignore();

        platos[cantPlatos].codigo = insertarChar(codigo);
        platos[cantPlatos].nombre = insertarChar(nombre);
        platos[cantPlatos].precio = precio;

        cantPlatos++;

        if (arch.eof()) break;
    }
    // for (int i=0; i<cantPlatos; i++) {
    //     cout << platos[i].codigo << " " << platos[i].nombre << " " << platos[i].precio << " " << platos[i].cantidad << endl;
    // }
}

int buscarPosPlato(char* codigo, struct Plato *platos, int cantPlatos) {
    for (int i = 0; i < cantPlatos; i++) {
        if (strcmp(codigo, platos[i].codigo) == 0) return i;
    }
    return -1;
}

void leerAtenciones(struct Atencion *atenciones, int& cantAtenciones, struct Plato *platos, int cantPlatos) {
    ifstream arch("ArchivosDeDatos/atenciones.txt", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo de atenciones.txt" << endl;
        exit(1);
    }
    // 415217 21:36 B959AG 2 FK25HJ 1 S92K8X 3
    // numAten, hora, plato, cantidad
    int codigo;
    int hh,mm, hora;
    char codPlato[10];
    char c;
    int cantidad, numPlatos;
    int posPlato;
    cantAtenciones = 0;
    while (true) {
        arch >> codigo;
        arch >> hh >> c >> mm;
        hora = hh*60 + mm;

        if (arch.eof()) break;

        atenciones[cantAtenciones].codigo = codigo;
        atenciones[cantAtenciones].hora = hora;
        atenciones[cantAtenciones].total_venta = 0;
        atenciones[cantAtenciones].cantidad_comentarios = 0;
        atenciones[cantAtenciones].platos_atendidos = new struct Plato[20];
        numPlatos = 0;

        while (true) {
            arch >> codPlato >> cantidad;

            posPlato = buscarPosPlato(codPlato, platos, cantPlatos);

            if (posPlato != -1) {
                atenciones[cantAtenciones].total_venta += platos[posPlato].precio*cantidad;
                atenciones[cantAtenciones].platos_atendidos[numPlatos].precio = platos[posPlato].precio;
                atenciones[cantAtenciones].platos_atendidos[numPlatos].codigo = insertarChar(codPlato);
                atenciones[cantAtenciones].platos_atendidos[numPlatos].nombre = insertarChar(platos[posPlato].nombre);
                atenciones[cantAtenciones].platos_atendidos[numPlatos].cantidad = cantidad;
                numPlatos++;
            }

            if (arch.peek() == '\n') break;
        }
        atenciones[cantAtenciones].cantidad_platos = numPlatos;

        cantAtenciones++;
    }
}

void leerComentarios(struct Atencion *atenciones, int cantAtenciones, struct Palabra *lexicon, int cantLexicon) {
    ifstream arch("ArchivosDeDatos/comentarios.csv", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo de comentarios.csv" << endl;
        exit(1);
    }

    // 394386,"Los platos estuvieron muy ricos y sabrosos, el pedido fue rapido. ¡Volveria seguramente!"
    int codAtencion;
    char comentario[100];
    int pos, cantComentarios;
    int polaridad;

    while (arch >> codAtencion) {
        arch.ignore();
        arch.getline(comentario, 100,'\n');

        pos = buscarAtencion(codAtencion, atenciones, cantAtenciones);
        cantComentarios = atenciones[pos].cantidad_comentarios;

        atenciones[pos].comentarios[cantComentarios].pre_procesado = preProcesarComentario(comentario);

        procesarComentario(pos, cantComentarios, comentario, atenciones, cantAtenciones, lexicon, cantLexicon);

        //polaridad total

    }
}

int buscarAtencion(int codigo, struct Atencion *atenciones, int cantAtenciones) {
    for (int i = 0; i < cantAtenciones; i++) {
        if (codigo == atenciones[i].codigo) return i;
    }
    return -1;
}

char* preProcesarComentario(char* comentario) {
    int largo = strlen(comentario);
    // "Estuvo bueno, pero demoraron en atender."
    for (int i = 0; i < largo ; i++) {
        if (not isalpha(comentario[i]) and comentario[i] != ' ') {
            for (int j = i+1; j < largo ; j++) {
                comentario[j-1] = comentario[j];
            }
            comentario[largo-1] = '\0';
            largo--;
            i--;
        }
    }
    for (int i = 0; i < largo ; i++) {
        if ('A' <= comentario[i] and comentario[i] <= 'Z') comentario[i] = tolower(comentario[i]);
    }
    return comentario;
}

void procesarComentario(int pos, int cantComentarios, char* comentario, struct Atencion *atenciones, int cantAtenciones, struct Palabra *lexicon, int cantLexicon) {
    char palabra[20];
    int cantPalabras = 0;

    atenciones[pos].comentarios[cantComentarios].cantidadPalabras = 0;
    atenciones[pos].comentarios[cantComentarios].polaridadTotal = 0;

    for (int i = 0, j=0; comentario[i]; i++) {
        if (comentario[i] != ' ') {
            palabra[j] = comentario[i];
            j++;
        }
        else {
            atenciones[pos].comentarios[cantComentarios].palabras[cantPalabras].texto = insertarChar(palabra);
            atenciones[pos].comentarios[cantComentarios].polaridadTotal += buscarPalabra(palabra, lexicon, cantLexicon);
            atenciones[pos].comentarios[cantComentarios].cantidadPalabras++;
            j=0;
        }
    }
}

int buscarPalabra(char* palabra, struct Palabra *lexicon, int cantLexicon) {
    for (int i=0; i<cantLexicon; i++) {
        if (strcmp(palabra, lexicon[i].texto) == 0) return lexicon[i].polaridad;
    }
    return 0;
}

void emitirReporte(struct Atencion *atenciones, int cantAtenciones) {
    ofstream reporte("ArchivosDeReporte/ReporteAtencionesAnalisisSentimiento.txt", ios::out);

    reporte << "EMPRESA DE REPARTOS A DOMICILIO TP S.A" << endl;
    reporte << "REACCION DE CLIENTES" << endl;
    int polaridad;
    for (int i = 0; i < cantAtenciones; i++) {
        polaridad = 0;
        separador(reporte, '=');

        reporte << "No. ATENCION" << atenciones[i].codigo << setw(20) << "Atendido a las: ";
        mostarHora(reporte, atenciones[i].hora);
        reporte << endl;
        separador(reporte, '-');
        for (int j=0; j<atenciones[i].cantidad_platos;j++) {
            reporte << atenciones[i].platos_atendidos[j].codigo << ") " << atenciones[i].platos_atendidos[j].nombre;
            reporte << setw(30-strlen(atenciones[i].platos_atendidos[j].nombre)) << atenciones[i].platos_atendidos[j].precio;
            reporte << setw(10) << atenciones[i].platos_atendidos[j].cantidad;
            reporte << setw(10) << atenciones[i].platos_atendidos[j].cantidad * atenciones[i].platos_atendidos[j].precio << endl;
        }
        polaridad = 0;
        for (int j=0; i < atenciones[i].cantidad_comentarios; i++) {
            polaridad += atenciones[i].comentarios[j].polaridadTotal;
        }
        reporte << "Polaridad total de los comentarios: " << polaridad << endl;

        separador(reporte, '=');
    }
}

void separador(ofstream& arch, char separador) {
    arch << setfill(separador);
    arch << setw(80) << separador << endl;
    arch << setfill(' ');
}

void mostarHora(ofstream& arch, int hora) {
    int hh, mm;
    hh = hora/60;
    mm = hora%60;

    arch << setfill('0');
    arch << hh << ":" << mm;
    arch << setfill(' ');

}