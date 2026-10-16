#include <iomanip>
#include <iostream>
using namespace std;

#include "Bibliotecas/FuncionesAuxiliares.h"

int main()
{
    char opcion;
    int opcionCorrecta;
    double voltaje, corriente, resistencia1, resistencia2, resistencia3, rTotal;
    double voltaje1, voltaje2, voltaje3;
    double corriente1, corriente2;

    cout << "Seleccione una opcíon de tipo de circuito. " << endl;
    cout << "[A] En serie, [B] En paralelo, [C] Salir: " << endl;
    cin >> opcion;

    opcionCorrecta = validarOpcion(opcion);

    if (opcionCorrecta)
    {
        if (opcion != 'C' and opcion != 'c')
        {
            cout << "Ingrese el voltaje de la fuente el voltios: " << endl;
            cin >> voltaje;
            if (voltaje > 0)
            {
                cout << "Ingresar el valor de la resistencia 1 en ohmios: " << endl;
                cin >> resistencia1;
                cout << "Ingesar el valor de la resistencia 2 en ohmios: " << endl;
                cin >> resistencia2;
                if (resistencia1 > 0 and resistencia2 > 0)
                {
                    if (opcion == 'A' or opcion == 'a')
                    {
                        cout << "Ingresar el valor de la resistencia 3 en ohmios: " << endl;
                        cin >> resistencia3;
                        if (resistencia3 > 0)
                        {
                            rTotal = resistencia1 + resistencia2 + resistencia3;
                            corriente = voltaje / rTotal;
                            voltaje1 = calcularVoltaje(resistencia1, corriente);
                            voltaje2 = calcularVoltaje(resistencia2, corriente);
                            voltaje3 = calcularVoltaje(resistencia3, corriente);
                            cout << "La resistencia total (R) en ohmios es: " <<fixed<<setprecision(2)<<rTotal << endl;
                            cout << "La corriente (I) en amperios es: " << fixed<<setprecision(2)<< corriente << endl;
                            cout << "El voltaje (V) de la resist.1 es: " << fixed<<setprecision(2)<< voltaje1 << ", resist.2 es : "<<
                                fixed<<setprecision(2)<<voltaje2 << " y resist.3 es : " << fixed<<setprecision(2)<< voltaje3 << endl;
                        }
                        else
                        {
                            cout << "El valor de la resistencia 3 debe ser mayor a cero" << endl;
                        }
                    }
                    else
                    {
                        calcularResistenciaIntesidades(voltaje, resistencia1, resistencia2, &rTotal, &corriente, &corriente1, &corriente2);
                        cout << "La resistencia total (R) en ohmios es: " << fixed<<setprecision(2)<< rTotal << endl;
                        cout << "La corriente total (I) en amperios es: " << fixed<<setprecision(2)<< corriente << endl;
                        cout << "La corriente de la resist.1 es: " << fixed<<setprecision(2)<< corriente1 << " y para resist.2 es : " << fixed<<setprecision(2)<< corriente2 << endl;
                    }
                }
                else
                {
                    cout << "El valor de las resistencias 1 y 2 deben ser mayores a cero" << endl;
                }
            }
            else
            {
                cout << "El valor del voltaje debe ser mayor a cero" << endl;
            }
        }
        else
        {
            cout << "Salir" << endl;
        }
    }
    else
    {
        cout << "Es una opción incorrecta" << endl;
    }

    return 0;
}