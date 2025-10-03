#include <iostream>
#include <ctime>
using namespace std;

// declaracion de la funcion
// bool sumaPar(int a[], int n);


/* Muestra el funcionamiento de las funciones. */
int main() {
    const int NUM_ELEMENTOS = 100;
    int lista[NUM_ELEMENTOS];

    /* initialize random seed: */
    srand (time(NULL));
    
    for (int i = 0; i < NUM_ELEMENTOS; i++) {
        lista[i] = rand() % 100 + 1;
    }
    
    // invoca la funcion
    bool resultado = sumaPar(lista, NUM_ELEMENTOS);
    if (resultado)
        cout << "la suma es par\n" << endl;
    else
        cout << "la suma es impar\n" << endl;
    return EXIT_SUCCESS;
}

// definicion de la funcion
bool sumaPar(int a[], int n) {
    int suma = 0;
    // suma los elementos
    for (int i = 0; i < n; i++)
        suma += a[i];
    // devuelve true si la suma es par
    return (suma % 2) == 0;
}


