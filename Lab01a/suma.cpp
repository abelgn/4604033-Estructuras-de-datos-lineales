#include <cstdlib>
#include <iostream>
using namespace std;

/* Este programa recibe dos números x y y, y regresa su suma. */
int main() {
    int x, y, suma;
    
    cout << "Por favor ingresa dos números: ";
    cin >> x >> y;         // ingresa x y y
    suma = x + y;               // se calcula la suma
    cout << "Su suma es " << suma << endl;
    return EXIT_SUCCESS;        // termina con éxito
}
