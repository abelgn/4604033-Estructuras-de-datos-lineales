#include <iostream>
#include <string>

#include "lista_d_ligada_generica.h"

using namespace std;


int main() {
    ListaDLigadaG<int> le;
    ListaDLigadaG<double> ld;
    ListaDLigadaG<char> lc;
    ListaDLigadaG<string> ls;
    string hola = "Hol";
    
    for (int i=0; i < 5; i++) {
        le.insertar(i, le.getNumElementos());
        ld.insertar((double) i / 5.0, ld.getNumElementos());
        lc.insertar(static_cast<char>(97+i), lc.getNumElementos());
        ls.insertar(hola + static_cast<char>(i+'a'), ls.getNumElementos());
    }
    
    cout << le << endl;
    cout << ld << endl;
    cout << lc << endl;
    cout << ls << endl;
    
    le.eliminar(3);
    cout << le << endl;
    le.hacerVacia();
    cout << le << endl;
}
