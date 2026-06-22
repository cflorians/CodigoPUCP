#include <iostream>
using namespace std;
#include "Bibliotecas/FuncionesAdicionales.h"
#include <iomanip>

int main(int argc, char** argv)
{
    char tipo;
    double resistencia1, resistencia2, resistencia3, rTotal;
    double voltaje1, voltaje2, voltaje3, voltaje, corriente, corriente1, corriente2;
    int esValido;

    cout<<"Seleccione una opción de tipo de circuito."<<endl;
    cout<<"[A] En Serie, [B] En Paralelo, [C] Salir:"<<endl;
    cin>>tipo;

    esValido = validarEsCircuitoSerieParalelo(tipo);
    if (esValido){
        cout<<"Ingresar el voltaje de la fuente [voltios]: "<< endl;
        cin>>voltaje;
        if (voltaje>0){
            cout<<"Ingresar el valor de la resistencia 1 [ohmios]:  "<<endl;
            cin>>resistencia1;
            cout<<"Ingresar el valor de la resistencia 2 [ohmios]:  "<<endl;
            cin>>resistencia2;
            if (resistencia1>0 and resistencia2>0){
                if (tipo == 'A' or tipo == 'a') {
                    cout<<"Ingresar el valor de la resistencia 3 [ohmios]:  "<<endl;
                    cin>>resistencia3;
                    if (resistencia3>0){
                        //en Serie
                        rTotal=resistencia1+resistencia2+resistencia3;
                        cout<<"La resistencia total (R) en ohmios es: "<< rTotal <<endl;
                        corriente= voltaje/rTotal;
                        cout<<"La corriente (I) en amperios es:" << corriente <<endl;
                        voltaje1= calcularVoltaje(corriente, resistencia1);
                        voltaje2= calcularVoltaje(corriente, resistencia2);
                        voltaje3= calcularVoltaje(corriente, resistencia3);
                        cout<<"El voltaje (V) de la resist.1 es: "<< voltaje1 <<" resist.2 es: "<<fixed<<setprecision(2)<<voltaje2 <<" y resist.3 es "<< voltaje3 << endl;
                    }
                    else{
                        printf("El valor de la resistencia 3 debe ser mayor a cero\n");
                    }
                }
                else{ //en paralelo 2 resistencia
                    calcularIntensidadParalelo(voltaje,resistencia1,resistencia2,&rTotal,&corriente,&corriente1,&corriente2);
                    cout<<"La resistencia total (R) en ohmios es:" <<  rTotal <<endl;
                    cout<<"La corriente total (I) en amperios es: "<< corriente<<endl;
                    cout<<"La corriente de resist.1 es "<<corriente1<<" y resist.2 es "<< corriente2 <<endl;
                }
            }
            else {
                cout<<"El valor de las resistencias 1 y 2 deben ser mayores a cero"<<endl;
            }
        }
        else{
            cout<<"El valor del voltaje de la fuente debe ser mayor a cero"<<endl;
        }
    }

    else {
        if(tipo == 'C' or tipo == 'c'){
            cout<<"Salir"<<endl;
        }
        else{
            cout<<"Es una opción incorrecta"<<endl;
        }
    }

    return 0;
}