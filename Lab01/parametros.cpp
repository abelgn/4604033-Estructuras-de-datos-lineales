#include <iostream>
using namespace std;

// recibe un parametros por valor y otro por referencia
void f (int value, int &ref ) {
    // no tiene efecto en el argumento original
    value++;
    // modifica el argumento original
    ref ++;
    cout << value << endl;      // imprime 2
    cout << ref << endl;        // imprime 6
}

int main() {
    int gato = 1;
    int perro = 5;
    // pasa gato por valor, perro por referencia
    f(gato, perro);
    cout << gato << endl;        // imprime 1
    cout << perro << endl;       // imprime 6
    return EXIT_SUCCESS;
}
