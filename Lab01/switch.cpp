#include <iostream>
using namespace std;

/* Muestra el funcionamiento de la declaracion switch. */
int main() {
    char comando;
    cout << "Comando: ";
    cin >> comando;         // se ingresa un carácter
    switch (comando) {      // switch de acuerdo al valor de comando
        case 'I':           // if (comando == 'I')
            cout << "Insertar" << endl;
            break;
        case 'D':           // if (comando == 'D')
            cout << "Eliminar" << endl;
            break;
        case 'R':           // if (comando == 'R')
            cout << "Reemplazar" << endl;
            break;
        default:            // else
            cout << "Comando no reconocido" << endl;
            break;
    }
}
