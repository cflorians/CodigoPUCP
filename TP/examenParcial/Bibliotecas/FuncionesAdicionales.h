//
// Created by carlo on 9/10/2025.
//

#ifndef EXAMENPARCIAL_FUNCIONESADICIONALES_H
#define EXAMENPARCIAL_FUNCIONESADICIONALES_H

void abrirArch(ifstream& arch, const char* nombreArchivo);
void abrirArch(ofstream& arch, const char* nombreArchivo);
void separadorCaracter(ofstream& arch, char caracter);
void emitirTitulo(ofstream& arch);
void copiarTextoHasta(ifstream& arch, ofstream& salida, char limitador, int& longTexto);
void procesarCliente(ifstream& clientes,ifstream& platos,ifstream& repartidores,ifstream& repartos, ofstream& reporte, double& totalRecaudado,double& totalAPagar);
void mostrarTipoVehiculo(ofstream& reporte,char tipoVehiculo, int& longTexto);
void procesarRepartos(ifstream& platos,ifstream& repartidores,ifstream& repartos, ofstream& reporte, int dniCliente);
void buscarPlato(ifstream& platos, ofstream& reporte, int codPlato,int cantPlatos);


#endif //EXAMENPARCIAL_FUNCIONESADICIONALES_H