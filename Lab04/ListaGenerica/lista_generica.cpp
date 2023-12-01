#include <iostream>
#include <string>

#include "lista_generica.h"

using namespace std;


int main() {
    Lista<int> li(5);
    Lista<double> ld(20);
    Lista<char> lc(10);

    for (int i=0; i < 5; i++) {
        li.insertar(i, li.fin());
        ld.insertar((double) i / 5, ld.fin());
        lc.insertar((char) (i+97), lc.fin());
    }

    cout << li << endl;
    cout << ld << endl;
    cout << lc << endl;
}
