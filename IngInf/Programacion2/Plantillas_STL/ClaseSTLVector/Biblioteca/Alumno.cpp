#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#include "Alumno.h"

Alumno::Alumno() {
    nombre = "";
    nota = -1;
    frutas.clear();
}

Alumno::Alumno(const string& nomb, int nta) {
    nombre = nomb;
    nota = nta;
}

void Alumno::mostrar() {
    cout << left << setw(12) << nombre
         << right << setw(2) << nota << " - "
         << (aprobo() ? "Aprobo" : "Desaprobo") << endl;
    agregarFruta("Arandano");
}

bool Alumno::aprobo() {
    return nota >= 11;
}

int Alumno::getNota() const {
    return nota;
}

void Alumno::setNota(int nta) {
    nota = nta;
}

void Alumno::setNombre(const string &nomb) {
    nombre = nomb;
}

string Alumno::getNombre() const {
    return nombre;
}

void Alumno::agregarFruta(string fruta) {
    frutas.push_back(fruta);
}

bool Alumno::operator<(const Alumno &alumno) {
    return nota < alumno.nota;
    // return nombre < alumno.nombre;
}

ostream & operator << (ostream& arch, const Alumno &alumno) {
    arch << alumno.getNombre() << " - " << alumno.getNota() << endl;
    return arch;
}

ifstream & operator>>(ifstream &arch, Alumno &alumno) {
    string nombre;
    getline(arch, nombre, ',');
    if (arch.eof()) return arch;
    int nota;
    arch >> nota;

    alumno.setNombre(nombre);
    alumno.setNota(nota);

    return arch;
}
