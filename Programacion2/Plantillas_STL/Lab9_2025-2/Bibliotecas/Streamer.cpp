#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
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

void Streamer::imprimir(ofstream &arch) {
    int dd = fecha%100, mm = (fecha%10000)/100, aa = fecha/10000;
    arch << left << setw(10) << "CANAL:" << canal << endl
         << setw(10) << "FECHA: " << setfill(' ')<< setw(2) << dd << '/' << setw(2) << mm << '/' << aa << endl
         << setfill(' ') << setw(10) << "LENGUAJE:" << idioma << endl;
    arch << categoria;
    arch << "ETIQUETAS STR: " << etiquetasStr << endl;
    int i = 1;
    for (Etiqueta etiqueta : etiquetasVector) {
        arch << i << ") " << etiqueta << endl;
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

ofstream & operator<<(ofstream &arch, Streamer &streamer) {
    streamer.imprimir(arch);
    return arch;
}
