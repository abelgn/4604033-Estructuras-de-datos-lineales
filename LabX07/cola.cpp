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

int main() {
    probarClaseCola();
    
    return EXIT_SUCCESS;
}
