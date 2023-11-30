#include <iostream>
#include <string>

#include "lista_ligada_generica_d2.h"

using namespace std;


int main() {
    ListaLigadaD<int> le;
    ListaLigadaD<double> ld;
    ListaLigadaD<char> lc;

    for (int i=0; i < 5; i++) {
        le.insertar(i, le.fin());
        ld.insertar((double) i / 5.0, ld.fin());
        lc.insertar((char) (97+i), lc.fin());
    }

    cout << le << endl;
    cout << ld << endl;
    cout << lc << endl;
}
