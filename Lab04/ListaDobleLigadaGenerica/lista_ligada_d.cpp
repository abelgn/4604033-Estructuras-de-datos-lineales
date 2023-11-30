#include <iostream>
#include <string>

#include "lista_ligada_generica_d.h"

using namespace std;


int main() {
    ListaLigadaD<int> le;
    ListaLigadaD<double> ld;
    ListaLigadaD<char> lc;

    for (int i=0; i < 5; i++) {
        le.insertar(i, le.fin());
        ld.insertar((double) i / 5, ld.fin());
        lc.insertar((char) (i+97), lc.fin());
    }

    NodoD<int> *p = le.primera();
    while (p != le.fin()) {
        cout << le.obtener(p) << endl;
        p = le.siguiente(p);
    }

    NodoD<double> *q = ld.primera();
    while (q != ld.fin()) {
        cout << ld.obtener(q) << endl;
        q = ld.siguiente(q);
    }


    NodoD<char> *r = lc.primera();
    while (r != lc.fin()) {
        cout << lc.obtener(r) << endl;
        r = lc.siguiente(r);
    }
}
