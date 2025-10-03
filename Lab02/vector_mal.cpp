#include <iostream>

using namespace std;

class Vect {                // una clase vector
    public:
        Vect();
        Vect(int n);        // constructor con un tamaño dado
        ~Vect();            // destructor
        // ... se omiten otros miembros públicos
    private:
        int *datos;         // un arreglo que contiene el vector
        int tamaño;         // número de entradas del arreglo
};

Vect::Vect() { }

Vect::Vect(int n) {         // constructor
    tamaño = n;
    datos = new int[n];     // asigna el arreglo
}

Vect::~Vect() {             // destructor
    delete [] datos;        // libera el arreglo asignado
}


int main() {
    Vect a(100);            // a es a vector of tamaño 100
    Vect b = a;             // inicializa b desde a (¡CUIDADO!)
    Vect c;                 // c es a vector (tamaño por default 10)
    c = a;                  // asigna a a c (¡CUIDADO!)
    return EXIT_SUCCESS;
}
