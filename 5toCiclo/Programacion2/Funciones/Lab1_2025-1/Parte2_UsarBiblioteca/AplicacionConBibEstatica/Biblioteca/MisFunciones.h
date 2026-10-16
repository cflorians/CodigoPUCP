//
// Created by carlo on 4/6/2026.
//

#ifndef APLICACIONCONBIBESTATICA_MISFUNCIONES_H
#define APLICACIONCONBIBESTATICA_MISFUNCIONES_H

void leerArchivo(ifstream& arch,int*& dni, struct CadenaDeCaracteres*& conductor, struct CadenaDeCaracteres*& placa);
void consumirEspacios(ifstream& arch);
void juntarNombre(struct CadenaDeCaracteres& nombreJunto, struct CadenaDeCaracteres* temp, int cantidad);
void emitirReporte(ofstream& arch,int* dni, struct CadenaDeCaracteres* conductor, struct CadenaDeCaracteres* placa);
void separador(ofstream& arch, char separador);
void formatearNombre(struct CadenaDeCaracteres& nombre);

#endif //APLICACIONCONBIBESTATICA_MISFUNCIONES_H
