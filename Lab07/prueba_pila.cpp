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


int main() {
    cout << "Prueba de la clase Pila:" << endl;
    probarClasePila();
    
    return EXIT_SUCCESS;
}
