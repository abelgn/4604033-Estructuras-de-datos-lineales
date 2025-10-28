#include <iostream>
#include <string>

#include "pila.h"

using namespace std;


void probarClasePila() {
    Pila<int> p;
    
    p.push(5);
    cout << "push(5): " << p << endl;
    p.push(3);
    cout << "push(3): " << p << endl;
    p.pop();
    cout << "pop(): " << p << endl;
    p.push(2);
    cout << "push(2): " << p << endl;
    p.push(8);
    cout << "push(8): " << p << endl;
    p.pop();
    cout << "pop(): " << p << endl;
    p.pop();
    cout << "pop(): " << p << endl;
    p.push(9);
    cout << "push(9): " << p << endl;
    p.push(1);
    cout << "push(1): " << p << endl;
    p.pop();
    cout << "pop(): " <<p << endl;
    p.push(7);
    cout << "push(7): " << p << endl;
    p.push(6);
    cout << "push(6): " << p << endl;
    p.pop();
    cout << "pop(): " << p << endl;
    p.pop();
    cout << "pop(): " << p << endl;
    p.push(4);
    cout << "push(4): " << p << endl;
    p.pop();
    cout << "pop(): " << p << endl;
    p.pop();
    cout << "pop(): " << p << endl;
    p.pop();
    cout << "pop(): " << p << endl;
}


/**
 * Hace una copia de <code>s<\code> en <code>t<\code>.
 */
void copiar(Pila<int> &s, Pila<int> &t) {
    // implementar
}


/**
 * Determina si <code>s<\code> y <code>t<\code> son la misma
 * pila de elementos. Si son la misma pila, devuelve
 * <code>true<\code>, <code>false<\code> en caso contrario.
 */
bool sonIguales(Pila<int> &s, Pila<int> &t) {
    bool iguales = true;
    // implementar
    return iguales;
}


/**
 *  Agrega a <code>s<\code> una copia de los elementos de
 *  <code>t<\code>, quedando el tope de <code>t<\code> como el
 *  tope de <code>s<\code>. La pila <code>t<\code> no sufre
 *  modificaciones.
 */
void agregar(Pila<int> &s, Pila<int> &t) {
    // implementar
}


/**
 * Combina una copia de los elementos de las pilas
 * <code>s<\code> y <code>t<\code> en <code>u<\code>, de tal
 * forma que <code>u<\code> está ordenada en forma no
 * descendente. <code>s<\code> y <code>t<\code> están ordenadas
 * ascendentemente y <code>u<\code> está vacía. Las pilas
 * <code>s<\code> y <code>t<\code> no sufren modificaciones.
 */
void combinar(Pila<int> &s, Pila<int> &t, Pila<int> &u) {
    // implementar
}



int main() {
    cout << "Prueba de la clase Pila:" << endl;
    probarClasePila();
    
    Pila<int> s, t, u, v;
    
    // Ejercicio 2a
    cout << "\nEjercicio 2a: Copia pila s en t" << endl;
    s.push(10);
    s.push(8);
    s.push(6);
    s.push(4);
    s.push(2);
    copiar(s, t);
    cout << "Pila s: " << s << endl;
    cout << "Pila t: " << t << endl;

    // Ejercicio 2b
    cout << "\nEjercicio 2b: Verifica si s y t son iguales" << endl;
    if (sonIguales(s, t))
        cout << "Las pilas s y t son iguales" << endl;
    else
        cout << "Las pilas s y t no son iguales" << endl;

    u.push(9);
    u.push(7);
    u.push(5);
    u.push(3);
    u.push(1);
    cout << "\nEjercicio 2b: Verifica si s y u son iguales" << endl;
    cout << "Pila s: " << s << endl;
    cout << "Pila u: " << u << endl;
    if (sonIguales(s, u))
        cout << "Las pilas s y u son iguales" << endl;
    else
        cout << "Las pilas s y u no son iguales" << endl;

    // Ejercicio 2c
    cout << "\nEjercicio 2c: Agrega u a s" << endl;
    agregar(s, u);
    cout << "Pila s: " << s << endl;

    // Ejercicio 2d
    cout << "\nEjercicio 2c: Combina t y u en v" << endl;
    combinar(t, u, v);
    cout << "Pila v: " << v << endl;

    return EXIT_SUCCESS;
}
