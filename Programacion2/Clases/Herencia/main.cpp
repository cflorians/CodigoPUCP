#include <iostream>
using namespace std;

#include "Biblioteca/Gato.h"
#include "Biblioteca/Perro.h"

int main() {

    // Inicializamos gato con parametros
    Gato gato("Dali", 5, 5.6, true);
    // gato.setNombre("Dali");
    // gato.setEdad(5);
    // gato.setPeso(5.6);
    gato.mostrar();

    Perro perro("Rocky", 10, 11.5, true);
    // perro.setNombre("Rocky");
    // perro.setEdad(10);
    // perro.setPeso(11.5);
    perro.mostrar();

    cout << endl << "NUEVO" << endl;
    //Clase de Punteros a clases
    //clase base: animal
    //clase derivada: perro, gato
    Animal *ptAnimal;
    Animal animal("Lulu", 5 ,5.6);
    ptAnimal = &animal;
    ptAnimal->mostrar();

    cout << endl << "NUEVO perro" << endl;
    Perro objPerro("Terry", 5, 4.2, true);
    ptAnimal = &objPerro;
    ptAnimal->mostrar(); // muestra o no muestra lo del perro?  RPTA: solo muestra lo de la clase base

    Perro *ptPerro;
    // ptPerro = &animal; esto NO se puede hacer

    // CUATRO CONDICIONES PARA QUE EXISTA POLIMORFISMO
    // 1. Debe existir herencia
    // 2. Debe existir metodos sobreescritos
    // 3. El metodo sobreescrito en la clase base debe ser virtual
    // 4. El metodo debe ser llamado con un puntero a clase
    ptAnimal->comer();

    return 0;
}
