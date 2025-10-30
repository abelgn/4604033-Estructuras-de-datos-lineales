#include <iostream>
#include <string>

#include "pila_doble.h"

using namespace std;


void generarExcepcionPush() {
    PilaDoble<int> p(20);
    
    try {
        for (int i = 0; i < 10; i++) {
            p.push(i, 1);
            p.push(i, 2);
        }
        cout << "Pila doble: " << p << endl;

        // se intenta agregar un elemento más
        p.push(100, 1);
    }
    catch (RuntimeException& e) {
        cout << e.getMessage() << endl;
    }
}

void generarExcepcionPop() {
    PilaDoble<int> p(10);

    try {
        p.push(5, 1);
        cout << "Pila doble: " << p << endl;
        p.push(3, 1);
        cout << "Pila doble: " << p << endl;
        p.pop(1);
        cout << "Pila doble: " << p << endl;
        p.pop(1);
        cout << "Pila doble: " << p << endl;

        // se intenta eliminar un elemento más
        p.pop(1);
        cout << "Pila doble: " << p << endl;
    }
    catch (RuntimeException& e) {
        cout << e.getMessage() << endl;
    }
}


void generarExcepcionTop() {
    PilaDoble<int> p(10);

    try {
        p.push(5, 2);
        cout << "Pila doble: " << p << endl;
        p.push(3, 2);
        cout << "Pila doble: " << p << endl;
        p.pop(2);
        cout << "Pila doble: " << p << endl;
        p.pop(2);
        cout << "Pila doble: " << p << endl;

        // se intenta acceder al elemento en el
        // tope de la pila vacía
        p.top(2);
        cout << "Pila doble: " << p << endl;
    }
    catch (RuntimeException& e) {
        cout << e.getMessage() << endl;
    }
}


int main() {
    generarExcepcionPush();
    generarExcepcionPop();
    generarExcepcionTop();
    
    return EXIT_SUCCESS;
}
