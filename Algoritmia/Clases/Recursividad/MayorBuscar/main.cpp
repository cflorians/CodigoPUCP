#include <iostream>
using namespace std;

int encuentraMayor(int arreglo[], int longitud) {
    // CASO BASE
    if (longitud == 1) return arreglo[0];
    // PARTE RECURSIVA
    int numero1 = arreglo[longitud-1];
    int numero2 = encuentraMayor(arreglo, longitud-1);
    // esta linea es donde se hace la llamada recursiva, aca retorna al terminar de ejecutar
    // la funcion recursiva, luego sigue ejecutando el resto de lineas

    if (numero1 < numero2) return numero2;
    else return numero1;
}

int main(int argc, char** argv) {
    int arreglo[]{24,20,25,23,10};
    int longitud=5;

    cout << "El máxiom número del arreglo es: " << encuentraMayor(arreglo,longitud) << endl;
    
    return 0;
}
