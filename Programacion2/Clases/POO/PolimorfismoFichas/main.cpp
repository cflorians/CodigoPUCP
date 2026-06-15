#include <iostream>
using namespace std;

#include "Bibliotecas/Alfil.h"
#include "Bibliotecas/Torre.h"

int main() {

    // CUATRO CONDICIONES PARA QUE EXISTA POLIMORFISMO
    // 1. Debe existir herencia
    // 2. Debe existir metodos sobreescritos
    // 3. El metodo sobreescrito en la clase base debe ser virtual
    // 4. El metodo debe ser llamado con un puntero a clase
    Ficha *pt;
    
    pt = new Alfil();
    pt->mover('A', 4);

    pt = new Torre();
    pt = &torre;
    pt->mover('F', 5);

    return 0;
}
