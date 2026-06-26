//
// Created by Carlos on 25/06/2026.
//

#ifndef LAB9_2025_1_MINISTERIODETRANSPORTE_H
#define LAB9_2025_1_MINISTERIODETRANSPORTE_H

class MinisterioDeTransporte {
private:
    list<class Infraccion> tablaInfracciones;
    list<class Empresa> listaEmpresas;
public:
    void cargaDeInfracciones(const char* nombArch);
    void cargaEmpresas(const char* nombArch);
    void cargaVehiculos(const char* nombArch);
    void cargaInfraccionesCometidas(const char* nombArch);
    void reporteDeEmpresaConInfracciones(const char* nombArch);
    void eliminaInfraccionesPagadas();
};

#endif //LAB9_2025_1_MINISTERIODETRANSPORTE_H
