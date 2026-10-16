//
// Created by carlo on 4/6/2026.
//

#ifndef BIBLIOTECA_2025_1_FUENTES_FUNCIONES_H
#define BIBLIOTECA_2025_1_FUENTES_FUNCIONES_H

void operator ! (struct CadenaDeCaracteres& cadena);

void operator <= (struct CadenaDeCaracteres& cadena, const char* texto);
void operator <= (struct CadenaDeCaracteres& cadena, int espacio);
void operator <= (struct CadenaDeCaracteres& cad1, struct CadenaDeCaracteres cad2);

bool operator += (struct CadenaDeCaracteres& cadena, const char* texto);
bool operator += (struct CadenaDeCaracteres& cad1, const struct CadenaDeCaracteres cad2);

int compare(const struct CadenaDeCaracteres cad1, const char* texto);
bool operator == (const struct CadenaDeCaracteres cad1, const char* texto);
bool operator > (const struct CadenaDeCaracteres cad1, const char* texto);
bool operator < (const struct CadenaDeCaracteres cad1, const char* texto);

int compare(const struct CadenaDeCaracteres cad1,const struct CadenaDeCaracteres cad2);
bool operator == (const struct CadenaDeCaracteres cad1, const struct CadenaDeCaracteres cad2);
bool operator > (const struct CadenaDeCaracteres cad1, const struct CadenaDeCaracteres cad2);
bool operator < (const struct CadenaDeCaracteres cad1, const struct CadenaDeCaracteres cad2);

int operator >> (ifstream& arch, struct CadenaDeCaracteres& cad);

void operator && (struct CadenaDeCaracteres& cad1, struct CadenaDeCaracteres& cad2);

void operator << (ofstream& arch, struct CadenaDeCaracteres cad);

#endif //BIBLIOTECA_2025_1_FUENTES_FUNCIONES_H
