#include <iostream>
using namespace std;

/* Muestra el funcionamiento de la declaracion if. */
int main() {
    int nivelNieve;

    cout << "Nivel de nieve: ";
    cin >> nivelNieve;
    
    if (nivelNieve < 2) {
        // hacer esto si el nivel de nieve es menor que 2
        cout << "Ir a clases y regresar a casa" << endl;
    } else if ( nivelNieve < 5 )
        // si el nivel es al menos 2 pero menor que 5
        cout << "Jugar con la nieve" << endl;
    else if ( nivelNieve < 10 )
        // si el nivel es al menos 5 pero menor que 10
        cout << "Ir a esquiar" << endl;
    else
        // si el nivel de nieve es 10 o más
        cout << "Quedarse en casa" << endl;
}
