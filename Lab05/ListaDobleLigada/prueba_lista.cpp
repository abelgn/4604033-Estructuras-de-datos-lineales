#include <iostream>
#include <string>

#include "lista_d_ligada.h"

using namespace std;

int main() {
    ListaDLigada *l1 = new ListaDLigada();
    for (int i = 1; i <= 5; i++)
        l1->insertar(to_string(i), 0);
    cout << "Lista 1: " << *l1 << endl;
    
    ListaDLigada *l2 = new ListaDLigada();
    for (int i = 1; i <= 5; i++)
        l2->insertar(to_string(i), l2->getNumElementos());
    cout << "Lista 2: " << *l2 << endl;

    l2->eliminar(l2->buscar("3"));

    cout << "Lista 2: " << *l2 << endl;

    return EXIT_SUCCESS;
}
