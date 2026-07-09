#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#include "BibliotecaArbol/Arbol.h"
#include "BibliotecaArbol/Funciones.h"

// bool verificaExistencia(Nodo* nodo, int bits[], int longitud, int i)
// {
//     // CASOS BASE
//     // si no encuentra nada
//     if (nodo == nullptr) return false;
//     // si es que procesamos todos los bits
//     if (i == longitud) return nodo->elemento.almacenado;
//
//     // PARTE RECURSIVA
//     if (bits[i] == 1) {
//         return verificaExistencia(nodo->izq, bits, longitud, i + 1);
//     }
//     else {
//         return verificaExistencia(nodo->der, bits, longitud, i + 1);
//     }
// }
// bool verificaExistencia(const Arbol& arbol, int buscado) {
//     // convertir buscado en binario
//     int binarioTemp[32];
//     int longitud = 0;
//     int temp = buscado;
//
//     if (buscado == 0) {
//         binarioTemp[0] = 0;
//         longitud = 1;
//     }
//     else {
//         while (temp > 0) {
//             binarioTemp[longitud] = temp % 2;
//             temp /= 2;
//             longitud++;
//         }
//     }
//
//     // ahora invertimos bits para tenerlos en el mismo orden que el arbol
//     int bits[32];
//     for (int i=0; i<longitud; i++) {
//         bits[i] = binarioTemp[(longitud-1) - i];
//     }
//
//     return verificaExistencia(arbol.raiz, bits, longitud, 0);
// }
//
// void imprime(Nodo* nodo, int numero) {
//     if (nodo != nullptr) {
//         if (numero == -1) numero = 0;
//         numero = numero*10 + nodo->elemento.digito;
//         if (nodo->elemento.almacenado and numero != -1){
//             // volver numero a decimal
//             int decimal = 0;
//             int temp = numero;
//             int digito;
//             int i = 0;
//             while (temp > 0) {
//                 digito = temp % 10;
//                 temp /= 10;
//                 decimal += digito*(int)pow(2, i);
//                 i++;
//             }
//             cout << left << setw(6) << numero << ":" << decimal << endl;
//         }
//         imprime(nodo->izq, numero);
//         imprime(nodo->der, numero);
//     }
// }
// void imprime(Arbol& arbol) {
//     imprime(arbol.raiz, 0);
// }

bool verificaContrasena(Nodo* nodo, const string& cadena, int n) {
    if (nodo != nullptr) {
        // verificamos en orden
        verificaContrasena(nodo->izq, cadena, n);
        if (nodo->elemento.caracter != cadena.at(nodo->elemento.posicion-1)) return false;
        else if (nodo->elemento.posicion == n) return true;
        verificaContrasena(nodo->der, cadena, n);
    }
    return true;
}

int main() {

    // Arbol arbol;
    // Arbol arbol1, arbol2, arbol3, arbol4, arbol5, arbol6, arbol7, arbol8, arbol9;
    //
    // construir(arbol);
    // construir(arbol1);
    // construir(arbol2);
    // construir(arbol3);
    // construir(arbol4);
    // construir(arbol5);
    // construir(arbol6);
    // construir(arbol7);
    // construir(arbol8);
    // construir(arbol9);
    //
    // plantar(arbol1, nullptr, {0, true}, nullptr);
    // plantar(arbol2, nullptr, {1, true}, nullptr);
    //
    // plantar(arbol3, nullptr, {1,false}, arbol1.raiz);
    // plantar(arbol4, nullptr, {1,true}, nullptr);
    // plantar(arbol5, arbol2.raiz, {0,false}, nullptr);
    //
    // plantar(arbol6, arbol3.raiz, {1,true}, nullptr);
    // plantar(arbol7, arbol4.raiz, {0,false}, arbol5.raiz);
    //
    // plantar(arbol8, arbol6.raiz, {1,true}, arbol7.raiz);
    // plantar(arbol9, nullptr, {0,true}, nullptr);
    //
    // plantar(arbol, arbol8.raiz, {-1, false}, arbol9.raiz);
    //
    // imprime(arbol);

    // cout << verificaExistencia(arbol, 13) << endl;


    Arbol contrasena;
    construir(contrasena);

    insertar(contrasena,{4,'P'});
    insertar(contrasena,{2,'U'});
    insertar(contrasena,{6,'0'});
    insertar(contrasena,{1,'P'});
    insertar(contrasena,{3,'C'});
    insertar(contrasena,{5,'2'});
    insertar(contrasena,{7,'2'});
    insertar(contrasena,{8,'4'});

    int intentos = 0;
    int maxIntentos;
    int cantDigitos = maximo(contrasena);
    string cadena;

    cout << "Ingrese el numero maximo de intentos: ";
    cin >> maxIntentos;

    while (intentos < maxIntentos) {
        cout << "Intento " << intentos+1 << "/" << maxIntentos << ".";
        cout << "Ingrese la contrasena: ";
        cin >> cadena;
        if (cadena.length() != cantDigitos) {
            cout << "Longitud incorrecta. Intento fallido" << endl;
        }
        else {
            if (verificaContrasena(contrasena.raiz, cadena, intentos)) {
                cout << "Acceso concedido." << endl;
                return 0;
            }
            else {
                cout << "Contrasena incorrecta. Intento fallido" << endl;
            }
        }
        intentos++;
    }

    cout << "Se llego al numero maximo de intentos permitidos" << endl;

    return 0;
}
