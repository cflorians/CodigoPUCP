#include <iostream>
using namespace std;

int buscaNumero(int* arr, int longitud, int numBuscado) {
    // CASO BASE
    if (longitud == 0) return -1;
    if (arr[longitud-1] == numBuscado) return longitud - 1;
    // PARTE RECURSIVA
    return buscaNumero(arr, longitud-1, numBuscado);
}

int main(int argc, char** argv) {
    
    int arr[] = {24,20,25,23,10};
    int longitud = 5;

    cout << "El número 25 fue encontrado en la posicion: " << buscaNumero(arr,longitud, 20)+1<< endl;
    
    return 0;
}
