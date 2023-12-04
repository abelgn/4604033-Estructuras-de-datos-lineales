#include <iostream>
#include <string>

#include "lista_ligada_c2.h"

using namespace std;


int main() {
    ListaLigadaC listaRep;

    cout << listaRep << endl;
    listaRep.insertar("Mientras me curo del cora");
    cout << listaRep << endl;
    listaRep.insertar("Houdini");
    cout << listaRep << endl;
    listaRep.insertar("Baila conmigo");
    cout << listaRep << endl;
    listaRep.insertar("Vocation");
    cout << listaRep << endl;

    listaRep.avanzar();
    cout << listaRep << endl;
    listaRep.avanzar();
    cout << listaRep << endl;
    listaRep.avanzar();
    cout << listaRep << endl;

    listaRep.eliminar();
    cout << listaRep << endl;
    listaRep.insertar("Watati");
    cout << listaRep << endl;
}
