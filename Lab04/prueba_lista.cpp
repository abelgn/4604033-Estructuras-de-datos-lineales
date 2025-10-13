#include <iostream>
#include <string>

#include "lista.h"

using namespace std;

int main() {
    Lista l1;
    for (int i = 1; i <= 5; i++)
        l1.insertar(i, 0);
    cout << l1 << endl;
    
    Lista l2;
    for (int i = 1; i <= 5; i++) {
        l2.insertar(i, l2.getNumElementos());
    }
    cout << l2 << endl;

    l2.eliminar(l2.buscar(3));
    
    cout << l2 << endl;

    return EXIT_SUCCESS;
}
