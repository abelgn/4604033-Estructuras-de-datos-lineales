#include <iostream>
#include <string>

#include "lista_ligada_d.h"

using namespace std;

int main() {
    ListaLigadaD l1;
    for (int i = 1; i <= 5; i++)
        l1.insertar(to_string(i), l1.primera());
    cout << l1 << endl;
    
    ListaLigadaD l2;
    for (int i = 1; i <= 5; i++)
        l2.insertar(to_string(i), l2.fin());
    cout << l2 << endl;

    l2.eliminar(l2.buscar("3"));
    
    cout << l2 << endl;

    return EXIT_SUCCESS;
}
