//
// Created by carlo on 4/30/2026.
//

#ifndef RECURSION_FUNCIONES_H
#define RECURSION_FUNCIONES_H

int contarPares(int posX, int posY, int n, int m, int matriz[][5]);

int dron(int posX, int posY, int objX, int objY,int n, int m, int bateria, int viento[][5]);

void sonda(int mat[][7], int N, int M,
           int x, int y,
           int dx, int dy,
           int E, int scan);

#endif //RECURSION_FUNCIONES_H
