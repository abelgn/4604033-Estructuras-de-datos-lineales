#include <iostream>
#include <string>

#include "lista.h"

using namespace std;


int main() {
    Lista l;
    for (int i = 1; i <= 5; i++)
        l.insertar(i, l.fin());
    cout << l << endl;
    return EXIT_SUCCESS;
}
