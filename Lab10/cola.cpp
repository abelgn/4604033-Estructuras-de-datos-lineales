#include <iostream>
#include <string>

#include "cola.h"

using namespace std;


/**
 * Hace una copia de <code>q<\code> en <code>r<\code>.
 */
void copiar(Cola<int> &q, Cola<int> &r) {
    // implementar
}


/**
 * Determina si <code>q<\code> y <code>r<\code> son la misma
 * cola de elementos. Si son la misma cola, devuelve
 * <code>true<\code>, <code>false<\code> en caso contrario.
 */
bool sonIguales(Cola<int> &q, Cola<int> &r) {
    bool iguales = true;
    // implementar
    return iguales;
}


/**
 *  Agrega a la final de <code>q<\code> una copia de los
 *  elementos de <code>r<\code>. La pila <code>r<\code>
 *  no sufre modificaciones.
 */
void agregar(Cola<int> &q, Cola<int> &r) {
    // implementar

}


/**
 * Combina una copia de los elementos de las colas
 * <code>q<\code> y <code>r<\code> en <code>s<\code>, de tal
 * forma que <code>s<\code> está ordenada en forma no
 * descendente. <code>q<\code> y <code>r<\code> están ordenadas
 * ascendentemente y <code>s<\code> está vacía. Las colas
 * <code>q<\code> y <code>r<\code> no sufren modificaciones.
 */
void combinar(Cola<int> &q, Cola<int> &r, Cola<int> &s) {
    // implementar
}



int main() {
    Cola<int> q, r, s, t;

    // Ejercicio 2a
    cout << "\nEjercicio 2a: Copia cola q en r" << endl;
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(6);
    q.enqueue(8);
    q.enqueue(10);
    cout << "Cola q: " << q << endl;
    copiar(q, r);
    cout << "Cola r: " << r << endl;

    // Ejercicio 2b
    cout << "\nEjercicio 2b: Verifica si q y r son iguales" << endl;
    if (sonIguales(q, r))
        cout << "Las colas q y r son iguales" << endl;
    else
        cout << "Las colas q y r no son iguales" << endl;

    s.enqueue(1);
    s.enqueue(3);
    s.enqueue(5);
    s.enqueue(7);
    s.enqueue(9);
    cout << "\nEjercicio 2b: Verifica si q y s son iguales" << endl;
    cout << "Cola q: " << q << endl;
    cout << "Cola s: " << s << endl;
    if (sonIguales(q, s))
        cout << "Las colas q y s son iguales" << endl;
    else
        cout << "Las colas q y s no son iguales" << endl;

    // Ejercicio 2c
    cout << "\nEjercicio 2c: Agrega s a q" << endl;
    agregar(q, s);
    cout << "Cola q: " << q << endl;

    // Ejercicio 2d
    cout << "\nEjercicio 2d: Combina r y s en t" << endl;
    combinar(r, s, t);
    cout << "Cola t: " << t << endl;

    return EXIT_SUCCESS;
}
