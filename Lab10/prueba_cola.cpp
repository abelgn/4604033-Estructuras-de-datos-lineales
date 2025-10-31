#include <iostream>
#include <string>

#include "cola.h"

using namespace std;


void probarClaseCola() {
    Cola<int> q;
    
    q.enqueue(5);
    cout << "enqueue(5): " << q << endl;
    q.enqueue(3);
    cout << "enqueue(3): " << q << endl;
    q.dequeue();
    cout << "dequeue(): " << q << endl;
    q.enqueue(2);
    cout << "enqueue(2): " << q << endl;
    q.enqueue(8);
    cout << "enqueue(8): " << q << endl;
    q.dequeue();
    cout << "dequeue(): " << q << endl;
    q.dequeue();
    cout << "dequeue(): " << q << endl;
    q.enqueue(9);
    cout << "enqueue(9): " << q << endl;
    q.enqueue(1);
    cout << "enqueue(1): " << q << endl;
    q.dequeue();
    cout << "dequeue(): " << q << endl;
    q.enqueue(7);
    cout << "enqueue(7): " << q << endl;
    q.enqueue(6);
    cout << "enqueue(6): " << q << endl;
    q.dequeue();
    cout << "dequeue(): " << q << endl;
    q.dequeue();
    cout << "dequeue(): " << q << endl;
    q.enqueue(4);
    cout << "enqueue(4): " << q << endl;
    q.dequeue();
    cout << "dequeue(): " << q << endl;
    q.dequeue();
    cout << "dequeue(): " << q << endl;
}


int main() {
    probarClaseCola();

    return EXIT_SUCCESS;
}
