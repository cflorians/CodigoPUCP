//
// Created by carlo on 21/08/2025.
//

#ifndef INC_21_8_25_FUNCIONESADICIONALES_H
#define INC_21_8_25_FUNCIONESADICIONALES_H

int validarEsCircuitoSerieParalelo (char tipo);

double calcularVoltaje (double corriente, double resistencia);

void calcularIntensidadParalelo (double voltaje, double resistencia1,
    double resistencia2, double *rTotal, double *corriente,
    double *corriente1, double *corriente2);

#endif //INC_21_8_25_FUNCIONESADICIONALES_H