#include <iostream>
#include <string>

#include "cola.h"

using namespace std;


void probarClaseCola() {
    Cola<int> q(100);
    
    q.enqueue(5);
    cout << q << endl;
    q.enqueue(3);
    cout << q << endl;
    q.dequeue();
    cout << q << endl;
    q.enqueue(2);
    cout << q << endl;
    q.enqueue(8);
    cout << q << endl;
    q.dequeue();
    cout << q << endl;
    q.dequeue();
    cout << q << endl;
    q.enqueue(9);
    cout << q << endl;
    q.enqueue(1);
    cout << q << endl;
    q.dequeue();
    cout << q << endl;
    q.enqueue(7);
    cout << q << endl;
    q.enqueue(6);
    cout << q << endl;
    q.dequeue();
    cout << q << endl;
    q.dequeue();
    cout << q << endl;
    q.enqueue(4);
    cout << q << endl;
    q.dequeue();
    cout << q << endl;
    q.dequeue();
    cout << q << endl;
}


/*
 Hace una copia de q en r.
 */
void copiar(Cola<int> &q, Cola<int> &r) {
    // implementar
}


/*
 Determina si q y r son la misma cola de elementos. Si son la misma cola, devuelve true, false en caso contrario.
 */
bool sonIguales(Cola<int> &q, Cola<int> &r) {
    // implementar
}


/*
 Agrega a q los elementos de r. La cola r no sufre modificaciones.
 */
void agregar(Cola<int> &q, Cola<int> &r) {
    // implementar
}


/*
 Combina las colas q y r en s, de tal forma que s está ordenada en forma no descendente. q y r están ordenadas ascendentemente y s está vacía. Las colas q y r no sufren modificaciones.
 */
void combinar(Cola<int> &q, Cola<int> &r, Cola<int> &s) {
    // implementar
}



int main() {
    probarClaseCola();
    
    Cola<int> q(10), r(10), s(10), t(10);
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(6);
    q.enqueue(8);
    q.enqueue(10);
    cout << "Cola q: " << q << endl;

    // Ejercicio 2a
    copiar(q, r);
    cout << "Cola r: " << r << endl;

    // Ejercicio 2b
    if (sonIguales(q, r))
        cout << "Las colas q y r son iguales" << endl;
    else
        cout << "Las colas q y r no son iguales" << endl;

    s.enqueue(1);
    s.enqueue(3);
    s.enqueue(5);
    s.enqueue(7);
    s.enqueue(9);
    cout << "Cola s: " << s << endl;
    if (sonIguales(q, s))
        cout << "Las colas q y s son iguales" << endl;
    else
        cout << "Las colas q y s no son iguales" << endl;

    // Ejercicio 2c
    agregar(q, s);
    cout << "Cola q: " << q << endl;

    // Ejercicio 2d
    combinar(r, s, t);
    cout << "Cola t: " << t << endl;

    return EXIT_SUCCESS;
}
