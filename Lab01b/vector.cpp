#include <iostream>

using namespace std;

class Vect {                // una clase vector
public:
    Vect();
    Vect(Vect &a);
    Vect(int n);        // constructor con un tamaño dado
    ~Vect();            // destructor
    Vect &operator=(Vect &a);
    void mostrar();
    // ... se omiten otros miembros públicos
private:
    static const int TAMAÑO_MIN = 10;
    int *datos;         // un arreglo que contiene el vector
    int tamaño;         // número de entradas del arreglo
};

Vect::Vect() {
    tamaño = TAMAÑO_MIN;
    datos = new int[TAMAÑO_MIN];
}

Vect::Vect(int n) {         // constructor
    tamaño = n;
    datos = new int[n];     // asigna el arreglo
}

Vect::Vect(Vect &a) {         // constructor de copia desde a
    tamaño = a.tamaño;              // copia el tamaño
    datos = new int[tamaño];        // asigna un nuevo arreglo
    for (int i = 0; i < tamaño; i++) {    // copia el contenido
        datos[i] = a.datos[i];
    }
}

Vect::~Vect() {             // destructor
    delete [] datos;        // libera el arreglo asignado
}

void Vect::mostrar() {
    for (int i = 0; i < tamaño; i++) {
        cout << datos[i] << " ";
    }
    cout << endl;
}


void Vect::copiar(Persona p) {
    p.nombre;
}

// operador de asignación desde a
Vect &Vect::operator=(Vect &a) {
    if (this != &a) {            // evitar autoasignación
        delete [] datos;        // eliminar arreglo anterior
        tamaño = a.tamaño;    // establece el nuevo tamaño
        datos = new int[tamaño];    // asigna un nuevo arreglo
        // copia el contenido del vector
        for (int i = 0; i < tamaño; i++) {
            datos[i] = a.datos[i];
        }
    }
    return *this;
}



int main() {
    Vect a(100);            // a es a vector of tamaño 100
    a.mostrar();
    Vect b = a;             // inicializa b desde a (¡CUIDADO!)
    b.mostrar();
    Vect c;                 // c es a vector (tamaño por default 10)
    c = a;                  // asigna a a c (¡CUIDADO!)
    c.mostrar();
    return EXIT_SUCCESS;
}
