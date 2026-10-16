
#ifndef LAB8_2025_1_FUNCIONESADICIONALES_H
#define LAB8_2025_1_FUNCIONESADICIONALES_H

void leerInfracciones(struct TablaDeInfracciones *arrTablaDeInfracciones, int& cantInfracciones);
char* insertarChar(char* cadena);
void toMayus(char* cadena);
void leerEmpresas(struct EmpresasRegistradas *arrEmpresasRegistradas, int& cantEmpresas);
void leerPlacas(struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresas);
int buscarPlaca(int dniBuscado,const struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresas);
void asignarFecha(struct EmpresasRegistradas *arrEmpresasRegistradas, int dd, int mm, int aa, int pos);
double buscarMulta(char* codigo, struct TablaDeInfracciones *arrTablaDeInfracciones, int cantInfracciones);
void leerInfraccionesCometidas(struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresas,
                                struct TablaDeInfracciones *arrTablaDeInfracciones, int cantInfracciones);

#endif //LAB8_2025_1_FUNCIONESADICIONALES_H