#include <iostream>
#include <string>

#include "pila_dinamica.h"

using namespace std;


void generarExcepcionPop() {
    Pila<int> p;
    
    try {
        p.push(5);
        cout << "Pila: " << p << endl;
        p.push(3);
        cout << "Pila: " << p << endl;
        p.pop();
        cout << "Pila: " << p << endl;
        p.pop();
        cout << "Pila: " << p << endl;

        // se intenta eliminar un elemento más
        p.pop();
        cout << "Pila: " << p << endl;
    }
    catch (RuntimeException& e) {
        cout << e.getMessage() << endl;
    }
}


void generarExcepcionTop() {
    Pila<int> p;
    
    try {
        p.push(5);
        cout << "Pila: " << p << endl;
        p.push(3);
        cout << "Pila: " << p << endl;
        p.pop();
        cout << "Pila: " << p << endl;
        p.pop();
        cout << "Pila: " << p << endl;

        // se intenta acceder al elemento en el
        // tope de la pila vacía
        p.top();
        cout << "Pila: " << p << endl;
    }
    catch (RuntimeException& e) {
        cout << e.getMessage() << endl;
    }
}


void invertir() {
    Pila<int> p;
    
    try {
        p.push(5);
        cout << "Pila: " << p << endl;
        p.push(3);
        cout << "Pila: " << p << endl;
        p.push(1);
        cout << "Pila: " << p << endl;
        p.push(-1);
        cout << "Pila: " << p << endl;
        p.invertir();
        cout << "Pila invertida: " << p << endl << endl;
    }
    catch (RuntimeException& e) {
        cout << e.getMessage() << endl;
    }
}


void concatenar() {
    Pila<int> p1;
    Pila<int> p2;

    try {
        p1.push(5);
        cout << "Pila 1: " << p1 << endl;
        p1.push(3);
        cout << "Pila 1: " << p1 << endl;
        p1.push(1);
        cout << "Pila 1: " << p1 << endl;
        p1.push(-1);
        cout << "Pila 1: " << p1 << endl;

        p2.push(6);
        cout << "Pila 2: " << p2 << endl;
        p2.push(4);
        cout << "Pila 2: " << p2 << endl;
        p2.push(2);
        cout << "Pila 2: " << p2 << endl;
        p2.push(-2);
        cout << "Pila 2: " << p2 << endl;
        p1.push(p2);
        cout << "Concatenación Pila 1 y Pila 2: " << p1 << endl << endl;
    }
    catch (RuntimeException& e) {
        cout << e.getMessage() << endl;
    }
}


void eliminar() {
    Pila<int> p;

    try {
        p.push(5);
        cout << "Pila: " << p << endl;
        p.push(3);
        cout << "Pila: " << p << endl;
        p.push(1);
        cout << "Pila: " << p << endl;
        p.push(-1);
        cout << "Pila: " << p << endl;
        p.push(6);
        cout << "Pila: " << p << endl;
        p.pop(3);
        cout << "Elimina 3 elementos de Pila: " << p << endl;
        p.pop(3);
        cout << "Elimina 3 elementos de Pila: " << p << endl;
        p.pop(3);
        cout << "Elimina 3 elementos de Pila: " << p << endl;
    }
    catch (RuntimeException& e) {
        cout << e.getMessage() << endl;
    }
}

int main() {
    generarExcepcionPop();
    generarExcepcionTop();
    invertir();
    concatenar();
    eliminar();
    return EXIT_SUCCESS;
}
