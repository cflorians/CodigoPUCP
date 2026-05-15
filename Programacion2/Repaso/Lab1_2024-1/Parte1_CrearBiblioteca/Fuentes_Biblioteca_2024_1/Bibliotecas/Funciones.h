//
// Created by carlo on 4/6/2026.
//

#ifndef FUENTES_BIBLIOTECA_2024_1_FUNCIONES_H
#define FUENTES_BIBLIOTECA_2024_1_FUNCIONES_H

bool operator >> (ifstream& arch, struct Libro& libro);
bool operator >> (ifstream& arch, struct Cliente& cliente);
bool operator >> (struct LibroSolicitado& libroSolicitado, struct Libro*& arrLibros);
bool operator << (struct Cliente& cliente, struct LibroSolicitado libroSolicitado);
void operator ++ (struct Cliente& cliente);
void operator << (ofstream& arch, struct Libro libro);
void operator << (ofstream& arch, struct Cliente cliente);

#endif //FUENTES_BIBLIOTECA_2024_1_FUNCIONES_H
