#include <iostream>
#include <string>

#include "lista.h"

using namespace std;


int main() {
    Lista l(10);
    for (int i = 1; i <= 10; i++)
        l.insertar(i, l.getNumElementos());
    cout << l << endl;
    return EXIT_SUCCESS;
}
