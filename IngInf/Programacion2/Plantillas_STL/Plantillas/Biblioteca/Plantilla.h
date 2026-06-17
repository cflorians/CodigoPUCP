//
// Created by Carlos on 17/06/2026.
//

#ifndef PLANTILLAS_PLANTILLA_H
#define PLANTILLAS_PLANTILLA_H

/*
 * Clase Generica
 */
template <typename T>
class Plantilla {
private:
    T dato;
public:
    void setDato(const T& dat);
    T getDato() const;
    void leerDato();
    void imprimirDato();
};

template<typename T>
void Plantilla<T>::setDato(const T &dat) {
    dato = dat;
}

template<typename T>
T Plantilla<T>::getDato() const {
    return dato;
}

template<typename T>
void Plantilla<T>::leerDato() {
    cin >> dato;
}

template<typename T>
void Plantilla<T>::imprimirDato() {
    cout << dato << endl;
}

#endif //PLANTILLAS_PLANTILLA_H
