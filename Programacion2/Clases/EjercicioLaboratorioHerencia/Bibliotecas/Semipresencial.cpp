//
// Created by Carlos on 28/05/2026.
//

#include "Semipresencial.h"

Semipresencial::Semipresencial() {
    total = 0;
    descuento = 0;
}

void Semipresencial::setDescuento(double descuento) {
    this->descuento = descuento;
}

double Semipresencial::getDescuento() const {
    return descuento;
}

void Semipresencial::setTotal(double total) {
    this->total = total;
}

double Semipresencial::getTotal() const {
    return total;
}
