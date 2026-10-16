#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#include "Bibliotecas/FuncionesAdicionales.h"

int main(int argc, char *argv[])
{
    int dd_entrega, mm_entrega, aa_entrega;
    char caracter;
    int dni_repartidor;
    int hora_ini, min_ini, seg_ini;
    double puntoPartida_x, puntoPartida_y;
    double vel_prom, tiempo_viaje, distancia_viaje, dist_acum=0, pago, pago_acum=0;
    int hora_fin, min_fin, seg_fin;
    int grad_dir, min_dir, seg_dir;
    double radianes, x_llegada, y_llegada;
    int anchoTotal=139;
    int i, longitudNombre;
    double cant_repartidores = 0, mayor_recorrido=-1, menor_recorrido=10000;
    int dni_mas_recorrido, dni_menos_recorrido;

    cout << setw(89) << "EMPRESA DE REPARTOS A DOMICILIO TP S.A." << endl;
    cin >> dd_entrega >> caracter >> mm_entrega >> caracter >> aa_entrega;
    cout << setw(76)<< "FECHA DE LOS REPARTOS: ";
    mostrarFechaFormato(dd_entrega, mm_entrega, aa_entrega);

    //hacer 35 veces
    while (cin >> dni_repartidor)
    {
        dist_acum=0;
        pago_acum=0;
        puntoPartida_x=0, puntoPartida_y=0;
        i=1;

        separadorConCaracter(anchoTotal, '=');
        cout << "Repartidor: " << endl;
        cout << "Nombre: ";
        leerEscribirNombre(longitudNombre);
        cout << setw(50-longitudNombre) << "DNI: " << dni_repartidor << endl;
        separadorConCaracter(anchoTotal, '-');

        cout << "DATOS DE LA RUTA: " << endl;
        cout << setw(19) << "HORA INI" << setw(11) <<"HORA FIN" << setw(12) << "VELOCIDAD"
            << setw(12) << "DISTANCIA" << setw(24) <<"PUNTO DE PARTIDA(X,Y)"
            << setw(24) << "PUNTO DE LLEGADA(X,Y)"
            << setw(21) <<"DISTANCIA ACUMULADA" <<setw(17) << "PAGO POR ENVÍO" << endl;

        cin >> hora_ini >> caracter >> min_ini >> caracter >> seg_ini;

        do
        {
            cout << "Tramo " << i << ":";
            cin >> vel_prom;
            cin >> hora_fin >> caracter >> min_fin >> caracter >> seg_fin;
            mostrarHoraFormato(hora_ini, min_ini, seg_ini);
            mostrarHoraFormato(hora_fin, min_fin, seg_fin);
            cout << setw(10) << vel_prom;

            tiempo_viaje = ((double)hora_fin+((double)min_fin/60)+((double)seg_fin/3600))
                            -((double)hora_ini+((double)min_ini/60)+((double)seg_ini/3600));
            distancia_viaje = vel_prom * tiempo_viaje;
            cout << setw(12) << fixed << setprecision(2) << distancia_viaje;

            cin >> grad_dir >> caracter >> min_dir >> caracter >> seg_dir >> caracter;
            cout << setw(13) << fixed << setprecision(2) << puntoPartida_x << " - ";
            cout << fixed << setprecision(2) << setw(6) << puntoPartida_y;
            radianes = (grad_dir + min_dir/60 + seg_dir/3600)*(numbers::pi/180);

            x_llegada = puntoPartida_x + (distancia_viaje * cos(radianes));
            y_llegada = puntoPartida_y + (distancia_viaje * sin(radianes));
            cout << setw(15) << fixed << setprecision(2) << x_llegada << setw(3) << '-' << setw(7) << y_llegada;


            dist_acum += distancia_viaje;
            cout << setw(18) << fixed << setprecision(2) << dist_acum;

            if (distancia_viaje < 10.5)
            {
                pago = 8.5;
            }
            else if (distancia_viaje < 20.5)
            {
                pago = 17.75;
            }
            else if (distancia_viaje < 35.5)
            {
                pago = 29.85;
            }
            else
            {
                pago = 45.69;
            }
            cout << setw(18) << fixed << setprecision(2) << pago << endl;

            puntoPartida_x = x_llegada;
            puntoPartida_y = y_llegada;
            hora_ini = hora_fin;
            min_ini = min_fin;
            seg_ini = seg_fin;
            pago_acum += pago;
            i++;
        }  while (i<=3);

        cout << "Retorno:";
        distancia_viaje = sqrt(pow(puntoPartida_x,2)+pow(puntoPartida_y,2));
        mostrarHoraFormato(hora_ini, min_ini, seg_ini);
        tiempo_viaje = distancia_viaje/vel_prom;
        int tiempoInicio = hora_ini*3600 + min_ini*60 + seg_ini;
        tiempo_viaje *= 3600;
        tiempo_viaje += tiempoInicio;
        hora_fin = (int)((int)tiempo_viaje/3600)%24;
        min_fin = (int)(((int)tiempo_viaje%3600)/60);
        seg_fin = (int)tiempo_viaje%60;
        mostrarHoraFormato(hora_fin, min_fin, seg_fin);

        cout << setw(10) << vel_prom;
        cout << setw(12) << fixed << setprecision(2) << distancia_viaje;
        cout << setw(12) << fixed << setprecision(2) << puntoPartida_x << setw(3) << '-' << setw(7) << puntoPartida_y;
        cout << setw(15) << fixed << setprecision(2) << 0.00 << "  -   "
                    << setprecision(2) << 0.00;
        dist_acum += distancia_viaje;
        cout << setw(18) << fixed << setprecision(2) << dist_acum << endl ;

        separadorConCaracter(anchoTotal, '-');
        cout << "PAGO TOTAL AL REPARTIDOR: " << pago_acum << endl;

        if (dist_acum <= menor_recorrido)
        {
            dni_menos_recorrido = dni_repartidor;
            menor_recorrido = dist_acum;
        }
        if (dist_acum >= mayor_recorrido)
        {
            dni_mas_recorrido = dni_repartidor;
            mayor_recorrido = dist_acum;
        }
        cant_repartidores++;
    }

    separadorConCaracter(anchoTotal, '/');
    cout << "REPARTIDOR CON MAYOR RECORRIDO:" << endl;
    cout << "DNI :" << setw(14) << dni_mas_recorrido << endl ;
    cout << "Distancia:" << setw(7) << fixed << setprecision(2) << mayor_recorrido << " km." << endl ;
    cout << "REPARTIDOR CON MENOR RECORRIDO:" << endl;
    cout << "DNI :" << setw(14) << dni_menos_recorrido << endl ;
    cout << "Distancia:" << setw(7) << fixed << setprecision(2) << menor_recorrido << " km."<< endl ;

    return 0;
}