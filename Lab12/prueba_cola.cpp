#include <iostream>
#include <string>

#include "cola_dinamica.h"

using namespace std;


int main() {
    Cola<int> q;
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(6);
    q.enqueue(8);
    q.enqueue(10);
    cout << "Cola q: " << q << endl;

    // Ejercicio 2
    Cola<int> r(q);
    cout << "Cola r: " << r << endl;

    // Ejercicio 3b
    if (q == r)
        cout << "Las colas q y r son iguales" << endl;
    else
        cout << "Las colas q y r no son iguales" << endl;

    Cola<int> s;
    s.enqueue(1);
    s.enqueue(3);
    s.enqueue(5);
    s.enqueue(7);
    s.enqueue(9);
    cout << "Cola s: " << s << endl;
    if (q == s)
        cout << "Las colas q y s son iguales" << endl;
    else
        cout << "Las colas q y s no son iguales" << endl;

    // Ejercicios 3a y 3c
    q = q + s;
    cout << "Cola q: " << q << endl;

    // Ejercicio 3a
    Cola<int> t = q;
    cout << "Cola t: " << t << endl;

    // Ejercicio 3d
    t = t - 3;
    cout << "Cola t: " << t << endl;
    cout << "Cola q: " << q << endl;
    cout << "Cola s: " << s << endl;

    return EXIT_SUCCESS;
}
