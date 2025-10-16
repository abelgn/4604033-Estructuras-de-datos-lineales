#include <iostream>
#include <string>

#include "lista_generica.h"

using namespace std;


int main() {
    Lista<int> li(5);
    Lista<double> ld(20);
    Lista<char> lc(10);
    Lista<string> ls(10);
    string hola = "Hol";

    for (int i=0; i < 5; i++) {
        li.insertar(i, li.getNumElementos());
        ld.insertar((double) i / 5, ld.getNumElementos());
        lc.insertar(static_cast<char>(i+'a'), lc.getNumElementos());
        ls.insertar(hola + static_cast<char>(i+'a'), ls.getNumElementos());
    }
    
    cout << li << endl;
    cout << ld << endl;
    cout << lc << endl;
    cout << ls << endl;
}
