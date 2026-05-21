#include <iostream>
using namespace std;

#include "Bibliotecas/Pila.h"
#include "Bibliotecas/Funciones.h"

int N = 7;
int red[7][7] {
    {0,0,0,0,0,0,0},
    {10,0,20,30,0,20,40},
    {0,0,0,0,0,100,0},
    {0,0,0,0,0,80,0},
    {50,10,5,10,0,100,4},
    {100,0,0,0,0,0,0},
    {0,0,0,0,0,0,0}
};

void skynerd() {
    Pila servidores;
    construir(servidores);
    Elemento a, b, candidato;
    int n;
    // Apilamos para analizar uno por uno
    // comparandolo con otro
    for (int i = 0; i < N; i++) {
        apilar(servidores, {i});
    }
    // analizamos si a recibe paquetes de b
    n = servidores.longitud;
    while (n>1) {
        a = desapilar(servidores);
        b = desapilar(servidores);
        if (red[a.cod][b.cod] == 0) { // a NO le envia a b
            apilar(servidores, b);
        }
        else { // a le envia a b, entonces b no es skynerd
            apilar(servidores, a);
        }
        n--;
    }
    // Aca nos quedaremos con un candidato
    // debemos revisar sus filas y sus columnas
    candidato = desapilar(servidores);
    bool esSkynerd = true;
    int maxEnviado = -1;
    //Filas
    for (int i = 0; i < N; i++) {
        if (red[candidato.cod][i] == 0 and i != candidato.cod) esSkynerd = false;
        if (red[candidato.cod][i] > maxEnviado) maxEnviado = red[candidato.cod][i];
    }
    //Columnas
    for (int i = 0; i < N; i++) {
        if (red[i][candidato.cod] != 0) esSkynerd = false;
    }

    if (esSkynerd) {
        cout << "SkyNerd ha sido detectado en el servidor: " << candidato.cod + 1<< endl;
        cout << "Máximo de paquetes enviados por SkyNerd: " << maxEnviado << endl;
    }
    else {
        cout << "SkyNerd no esta en la red" << endl;
    }
}

int main() {

    skynerd();

    return 0;
}
