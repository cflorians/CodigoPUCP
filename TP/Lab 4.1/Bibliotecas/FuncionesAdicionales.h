//
// Created by carlo on 28/09/2025.
//

#ifndef LAB_4_1_FUNCIONESADICIONALES_H
#define LAB_4_1_FUNCIONESADICIONALES_H

void procesarMedicos(int* arrCodMed,double* arrTarifaMed,int& cantMed);
void ignorarCaracteresHasta(ifstream& arch,char limite);
void procesarMedicamentos(int* arrMedicinas,double*  arrPrecioMedicinas,int& cantMedicinas);
void separadorCaracter(int ancho, char c, ofstream& salida);
void procesarCitaMedica(int* arrCodMed,double* arrTarifaMed, int numMedico);
void mostrarEncabezado();
void buscarNombreMedico(int numMedico, ofstream& salida);
void buscarEspecialidadMedico(int numMedico, ofstream& salida);
void procesarCitaPaciente(int* arrCodMed,int* arrMedicinas, double* arrPrecioMedicinas, int numMedico, int cantMedicinas);
void buscarPrecioMedicina(int* arrMedicinas, double* arrPrecioMedicinas, int medicinaBuscada, int cantMedicinas, double& precioMedicina);
void mostrarFecha(int dia,int mes,int anio,ofstream& reporte);
void mostrarHora(int hh, int mm, int ss,ofstream& reporte);

#endif //LAB_4_1_FUNCIONESADICIONALES_H