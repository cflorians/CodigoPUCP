#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
using namespace std;
#include "Multa.h"

Multa::Multa() {
    pagada = false;
    fechaDePago = 0;
}

void Multa::setFecha(int fec) {
    fecha = fec;
}

void Multa::setPlaca(const string &plac) {
    placa = plac;
}

void Multa::setCodMulta(const string &codMul) {
    codMulta = codMul;
}

void Multa::setMulta(double mult) {
    multa = mult;
}

void Multa::setPagada(bool pag) {
    pagada = pag;
}

void Multa::setFechaDePago(int fec) {
    fecha = fec;
}

int Multa::getFecha() const {
    return fecha;
}

string Multa::getPlaca() const {
    return placa;
}

string Multa::getCodMulta() const {
    return codMulta;
}

double Multa::getMulta() const {
    return multa;
}

bool Multa::getPagada() const {
    return pagada;
}

int Multa::getFechaDePago() const {
    return fechaDePago;
}

ifstream & operator>>(ifstream &arch, Multa &multa) {
    // 23/07/2023,P474-593,G2060,P,22/08/2023
    // fechaMulta, placa, codInfraccion, P o N, fecha pago
    int dd, mm, aa, fechaMulta;
    char c;
    string placa, codInfraccion;
    char realizoPago;

    arch >> dd >> c >> mm >> c >> aa >> c;
    if (arch.eof()) return arch;
    fechaMulta = aa*10000 + mm*100 + dd;
    getline(arch, placa, ',');
    getline(arch, codInfraccion, ',');
    arch >> realizoPago;
    if (realizoPago == 'P') {
        multa.setPagada(true);
        arch >> dd >> c >> mm >> c >> aa >> c;
        multa.setFecha(aa*10000 + mm*100 + dd);
    }
    else {
        multa.setPagada(false);
        arch.get(); // Consume el /n (porseacaso)
    }

    multa.setPlaca(placa);
    multa.setCodMulta(codInfraccion);

    return arch;
}
