//
// Created by carlo on 10/20/2025.
//

#ifndef PARCIAL_FUNCIONESADICIONALES_H
#define PARCIAL_FUNCIONESADICIONALES_H

void separadorCaracter(ofstream& arch, char caracter);
void mostrarTitulo(ofstream& arch);
void abrirArchivos(ifstream& arch, const char* nombreArch);
void abrirArchivos(ofstream& arch, const char* nombreArch);
void mostrarTextoHasta(ofstream& reporte, ifstream& arch, char limitador, int& largo, bool mayus);
void buscarMostrarIdioma(ofstream& arch, ifstream& idiomas, int idioma);
void buscarMostrarCategoria(ofstream& arch, ifstream& categorias, int codigo, char letCategoria);
void mostrarDuracion(ofstream& reporte, int duracion);
void mostrarEncabezadoStreams(ofstream& arch, ifstream& idiomas, ifstream& categorias, int codStream, int duracion, int idioma, char letCategoria, int codCategoria);
void procesarStreams(ifstream& streams,ifstream& canales,ifstream& categorias,ifstream& idiomas,ofstream& reporte);
void ignorarTextoHasta(ifstream& arch, char limitador);
void leerCodStream(ifstream& arch,int& codStreamActual, int& fechaStream, int& horaInicio, double& rating, double& dropOff);

#endif //PARCIAL_FUNCIONESADICIONALES_H