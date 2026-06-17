//
// Created by Carlos on 17/06/2026.
//

#ifndef PLANTILLAS_MIPLANTILLA_H
#define PLANTILLAS_MIPLANTILLA_H

/*
 * Función generica
 */
template <typename T>
T sumar(T a, T b) {
    return a + b;
}

template <typename T, typename U>
U sumar(const T& a, const U& b) {
    return a + b;
}

#endif //PLANTILLAS_MIPLANTILLA_H
