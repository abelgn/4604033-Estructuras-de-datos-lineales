#include <iostream>

using namespace std;

class Contador {                        // un contador simple
    public:
        Contador();                     // inicializacion
        int getCuenta();                // obtiene la cuenta actual
        void incrementarEn(int x);      // incrementa la cuenta en x
    private:
        int cuenta;                     // el valor del contador
};


Contador::Contador() {
    cuenta = 0;
}

int Contador::getCuenta() {
    return cuenta;
}

void Contador::incrementarEn(int x) {
    cuenta += x;
}


int main() {
    Contador ctr;                       // una instancia de Contador
    cout << ctr.getCuenta() << endl;    // imprime el valor inicial (0)
    ctr.incrementarEn(3);               // incrementa en 3
    cout << ctr.getCuenta() << endl;    // imprime 3
    ctr.incrementarEn(5);               // incrementa en 5
    cout << ctr.getCuenta() << endl;    // imprime 8
}
