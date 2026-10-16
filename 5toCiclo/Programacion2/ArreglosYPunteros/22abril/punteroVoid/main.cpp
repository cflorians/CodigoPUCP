#include <cstring>
#include <iostream>
using namespace std;

enum dato{CODIGO, NOMBRE};

int main() {

    // creamos datos para guardarlas en un void
    int *codigo = new int;
    *codigo = 10101;
    char *nombre;
    char auxNombre[30] = "MARIA VICTORIA";
    nombre = new char[strlen(auxNombre) + 1];
    strcpy(nombre, auxNombre);

    // doble apuntado para arreglo de punteros genericos
    void **w;
    void *v;
    w = new void*[]{};
    w[0] = codigo;
    w[1] = nombre;
    v = w; // apunte al arreglo de punteros

    // USO: recuperacion de información

    void **p;
    p = (void **)v;

    // tenemos que crear punteros para tener donde volcar los datos
    int* cod;
    char* nomb;
    cod = (int*)p[CODIGO]; // volcamos los datos en los punteros casteando
    nomb = (char*)p[NOMBRE];

    cout << *cod << endl;
    cout << nomb << endl;

    // limpiamos las variables que creamos con new
    delete codigo;
    delete nombre;
    delete w;

    return 0;
}
