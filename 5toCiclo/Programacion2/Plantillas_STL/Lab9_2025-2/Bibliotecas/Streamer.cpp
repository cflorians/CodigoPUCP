#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;
#include "Streamer.h"

void Streamer::setEtiquetaStr(const string &etiqueta) {
    etiquetasStr = etiqueta;
}

void Streamer::setFecha(int fech) {
    fecha = fech;
}

void Streamer::setIdioma(const string &idiom) {
    idioma = idiom;
}

void Streamer::setCanal(const string &ch) {
    canal = ch;
}

void Streamer::setCategoria(const Categoria &cat) {
    categoria = cat;
}

Categoria Streamer::getCategoria() const {
    return categoria;
}

void Streamer::insertarEtiqueta(const Etiqueta &etiqueta) {
    etiquetasVector.push_back(etiqueta);
}

void Streamer::insertarComentario(const string &comentario) {
    comentarios.push_back(comentario);
}

string Streamer::getEtiquetaStr() const {
    return etiquetasStr;
}

int Streamer::getFecha() const {
    return fecha;
}

string Streamer::getIdioma() const {
    return idioma;
}

string Streamer::getCanal() const {
    return canal;
}

void Streamer::leer(ifstream &arch) {
    // summit1g,12/11/2021,MK1092,HTR108-UPK123-SWT139-LWC105,English
    // codigo, fechaCreacion, codCategoria, etiquetas, idioma
    int dia, mes, anio;
    char c;
    string codCat;

    getline(arch, canal, ',');
    if (arch.eof()) return;
    arch >> dia >> c >> mes >> c >> anio >> c;
    fecha = anio*10000 + mes*100 + dia;
    getline(arch, codCat, ',');
    categoria.setCodigo(codCat);
    getline(arch, etiquetasStr, ',');
    getline(arch, idioma);
}

void Streamer::imprimir(ofstream &arch) const{
    int dd = fecha%100, mm = (fecha%10000)/100, aa = fecha/10000;
    arch << left << setw(10) << "CANAL:" << canal << endl
         << setw(10) << "FECHA: " << right << setfill('0')<< setw(2) << dd << '/' << setw(2) << mm << '/' << aa << setfill(' ')<< endl
         << left << setfill(' ') << setw(10) << "LENGUAJE:" << idioma << endl;
    arch << categoria;
    arch << "ETIQUETAS STR: " << etiquetasStr << endl;
    int i = 1;
    for (const Etiqueta& etiqueta : etiquetasVector) {
        arch << setw(4) << right << i << ") ";
        arch << etiqueta;
        i++;
    }
    arch << "COMENTARIOS: " << endl;
    i = 1;
    for (const string& com : comentarios) {
        arch << setw(4) << right << i << ") ";
        arch << com << endl;
        i++;
    }
}

bool Streamer::operator<(const Streamer &str) {
    if (categoria == str.categoria) {
        return fecha < str.fecha;
    }
    return categoria < str.categoria;
}

ifstream & operator>>(ifstream &arch, Streamer &streamer) {
    streamer.leer(arch);
    return arch;
}

ofstream & operator<<(ofstream &arch, const Streamer &streamer) {
    streamer.imprimir(arch);
    return arch;
}
