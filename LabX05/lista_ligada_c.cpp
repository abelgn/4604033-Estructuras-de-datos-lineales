#include <iostream>
#include <string>

#include "lista_ligada_c.h"

using namespace std;


/*
 Cuenta y devuelve el número de elementos que hay en lista ligada circular l.
 */
int contarElementos(ListaLigadaC &l) {
    int numElems = 0;
    // implementar
    return numElems;
}


/*
 Determina si las listas ligadas circulares l y m son la misma lista de elementos. Si son la misma lista, devuelve true, false en caso contrario.
 */
bool sonIguales(ListaLigadaC &l, ListaLigadaC &m) {
    bool iguales = true;
    // implementar
    return iguales;
}


/*
 Agrega a l los elementos de m.
 */
void agregar(ListaLigadaC &l, ListaLigadaC &m) {
    // implementar
}


/*
 Divide a la lista circular l, la cual tiene un número par de elementos, en dos listas ligadas circulares de la mitad del tamaño y las devuelve en las listas m1 y m2.
 */
void dividir(ListaLigadaC &l, ListaLigadaC &m1, ListaLigadaC &m2) {
    // implementar
}


/* NO MODIFICAR */
int main() {
    ListaLigadaC l1;
    l1.insertar("Another one bites the dust");
    l1.insertar("Sweet child o’mine");
    l1.insertar("Roadhouse blues");
    l1.insertar("She’s a rainbow");
    cout << "Lista: " << l1 << endl;
    // Ejercicio 2a
    cout << "Hay " << contarElementos(l1) << " canciones" << endl;

    ListaLigadaC l2;
    l2.insertar("Roadhouse blues");
    l2.insertar("She’s a rainbow");
    l2.insertar("Another one bites the dust");
    l2.insertar("Sweet child o’mine");
    cout << "Lista: " << l2 << endl;
    // Ejercicio 2b
    bool iguales = sonIguales(l1, l2);
    if (iguales)
        cout << "Las listas son iguales" << endl;
    else
        cout << "Las listas no son iguales" << endl;

    ListaLigadaC l3;
    l3.insertar("Sunday bloody sunday");
    l3.insertar("I want to hold your hand");
    l3.insertar("Sultans of swing");
    l3.insertar("Close to me");
    l3.insertar("Personal Jesus");
    l3.insertar("You really got me");
    cout << "Lista: " << l3 << endl;
    
    // Ejercicio 2c
    agregar(l2, l3);
    cout << "Lista: " << l2 << endl;

    // Ejercicio 2d
    ListaLigadaC l4;
    ListaLigadaC l5;
    dividir(l2, l4, l5);
    cout << "Lista: " << l4 << endl;
    cout << "Lista: " << l5 << endl;

    return EXIT_SUCCESS;
}
