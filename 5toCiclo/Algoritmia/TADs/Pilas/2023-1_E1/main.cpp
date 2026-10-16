#include <iostream>
using namespace std;

#include "BibliotecaPila/Funciones.h"
#include "BibliotecaPila/Pila.h"

#define N 7 // Cantidad de servidores
int red[N][N] {
    {0,0,0,0,0,0,0},
    {10,0,20,30,0,20,40},
    {0,0,0,0,0,100,0},
    {0,0,0,0,0,80,0},
    {50,10,5,10,0,100,4},
    {100,0,0,0,0,0,0},
    {0,0,0,0,0,0,0}
};

int BuscarSkyNerd() {
    Pila servidores;
    Elemento servidor_a, servidor_b, candidato;
    int n;
    construir(servidores);
    // Apilamos todos los servidores para analizar cada uno
    // si cumple con las condiciones del problema
    for (int i = 0; i < N; i++) {
        apilar(servidores, {i});
    }
    // Analizar si no recibe paquetes un servidor de otro
    n = servidores.longitud;
    while (n>1) {
        servidor_a = desapilar(servidores)->elemento;
        servidor_b = desapilar(servidores)->elemento;
        if (red[servidor_a.numero][servidor_b.numero] == 0) {
            // Si A no envía paquetes a B, descarto A como SkyNerd
            apilar(servidores, servidor_b);
        }
        else {
            // Si A envía paquetes a B, descarto B como SkyNerd, pues recibe paquetes
            apilar(servidores, servidor_a);
        }
        n--;
    }
    // Me quedo con un candidato
    // Ahora verifico que ese candidato no reciba de nadie
    candidato = desapilar(servidores)->elemento;
    bool cumple = true;
    // verificamos las filas
    for (int i = 0; i < N; i++) {
        if (red[candidato.numero][i] == 0 and candidato.numero != i) {
            cumple = false;
        }
    }
    // verificamos las columnas
    for (int i = 0; i < N; i++) {
        if (red[i][candidato.numero] != 0) {
            cumple = false;
        }
    }

    if (cumple == true) {
        return candidato.numero + 1;
    }
    else {
        return -1;
    }
}

int main() {

    cout << "SkyNerd ha sido detectado en el servidor: " << BuscarSkyNerd() << endl;

    return 0;
}
