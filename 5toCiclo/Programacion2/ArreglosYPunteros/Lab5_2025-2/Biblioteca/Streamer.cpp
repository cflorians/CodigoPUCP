#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "Funciones.h"
#include "Streamer.h"

Streamer::Streamer() {
    cuenta = nullptr;
    tiempoTotal = 0;
    promedioEspectadores = 0;
    nSeguidores = 0;
    categoria = nullptr;
}
Streamer::Streamer(const char* cuent, long long int tiempo, double prom, int num, const char* cat) {
    setCuenta(cuent);
    setTiempoTotal(tiempo);
    setPromedio(prom);
    setNSeguidores(num);
    setCategoria(cat);
}
Streamer::~Streamer() {
    delete[] cuenta;
    delete[] categoria;
}
Streamer::Streamer(const class Streamer& streamer) {
    cuenta = new char[strlen(streamer.cuenta) + 1];
    strcpy(cuenta, streamer.cuenta);

    tiempoTotal = streamer.tiempoTotal;
    promedioEspectadores = streamer.promedioEspectadores;
    nSeguidores = streamer.nSeguidores;

    categoria = new char[strlen(streamer.categoria) + 1];
    strcpy(categoria, streamer.categoria);
}
void Streamer::setCuenta(const char* cuenta) {
    delete[] this->cuenta;
    this->cuenta = new char[strlen(cuenta) + 1];
    strcpy(this->cuenta, cuenta);
}
void Streamer::setTiempoTotal(long long int tiempo) {
    tiempoTotal = tiempo;
}
void Streamer::setPromedio(double prom) {
    promedioEspectadores = prom;
}
void Streamer::setNSeguidores(int numero) {
    nSeguidores = numero;
}
void Streamer::setCategoria(const char* categoria) {
    delete[] this->categoria;
    this->categoria = new char[strlen(categoria) + 1];
    strcpy(this->categoria, categoria);
}
char* Streamer::getCuenta() {
    return this->cuenta;
}
long long int Streamer::getTiempoTotal() {
    return tiempoTotal;
}
double Streamer::getPromedio() {
    return promedioEspectadores;
}
int Streamer::getNSeguidores() {
    return nSeguidores;
}
char* Streamer::getCategoria() {
    return this->categoria;
}
void Streamer::leer_streamer(ifstream& arch) {
    // XStormHD,5758257274,38932.69,4865726,PUBG
    // Cuenta  , tiempoTotal, prom ,seguidores, categoria
    cuenta = leerCadena(arch);
    arch >> tiempoTotal;
    arch.get();
    arch >> promedioEspectadores;
    arch.get();
    arch >> nSeguidores;
    arch.get();
    categoria = leerCadena(arch, '\n');
}
void Streamer::mostrar_streamer() {
    cout << left << setw(15) << cuenta
         << left << setw(17) << categoria
         << right << setw(12) << tiempoTotal
         << right << setw(10) << fixed << setprecision(2) << promedioEspectadores
         << right << setw(10) << nSeguidores << endl;
}
void Streamer::mostrar_streamer(ofstream &arch) {
    arch << left << setw(15) << cuenta
         << left << setw(17) << categoria
         << right << setw(12) << tiempoTotal
         << right << setw(10) << fixed << setprecision(2) << promedioEspectadores
         << right << setw(10) << nSeguidores << endl;
}
void Streamer::copiar(const class Streamer& otro) {
    cuenta = new char[strlen(otro.cuenta) + 1];
    strcpy(cuenta, otro.cuenta);

    categoria = new char[strlen(otro.categoria) + 1];
    strcpy(categoria, otro.categoria);

    tiempoTotal = otro.tiempoTotal;
    promedioEspectadores = otro.promedioEspectadores;
    nSeguidores = otro.nSeguidores;
}

Streamer& Streamer::operator=(const Streamer& otro) {
    if (this == &otro) return *this;

    delete[] cuenta;
    delete[] categoria;

    cuenta = new char[strlen(otro.cuenta) + 1];
    strcpy(cuenta, otro.cuenta);

    categoria = new char[strlen(otro.categoria) + 1];
    strcpy(categoria, otro.categoria);

    tiempoTotal = otro.tiempoTotal;
    promedioEspectadores = otro.promedioEspectadores;
    nSeguidores = otro.nSeguidores;

    return *this;
}