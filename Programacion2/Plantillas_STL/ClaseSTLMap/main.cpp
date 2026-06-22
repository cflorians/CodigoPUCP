#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
using namespace std;

int main(int argc, char** argv) {

    map<int, string> ciudades;
    // Map si deja asignar con el indice
    ciudades[1] = "San Miguel";
    ciudades[2] = "Pueblo Libre";
    ciudades[3] = "Lince";
    ciudades[4] = "La Molina";

    cout << "Ingrese las ciudades: " << endl;
    for (int i=0; i<2; i++) {
        cin >> ciudades[i+5];
    }

    for (auto ciudad : ciudades) {
        cout << ciudad.first << "->" << ciudad.second << endl;
    }

    return 0;
}
