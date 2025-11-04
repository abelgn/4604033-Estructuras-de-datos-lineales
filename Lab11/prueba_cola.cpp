#include <iostream>
#include <string>

#include "cola.h"

using namespace std;


void probarClaseCola() {
    Cola<int> q(10);
    
    q.enqueue(5);
    cout << "q.enqueue(5): " << q << endl;
    q.enqueue(3);
    cout << "q.enqueue(3): " << q << endl;
    q.dequeue();
    cout << "q.dequeue(): " << q << endl;
    q.enqueue(2);
    cout << "q.enqueue(2): " << q << endl;
    q.enqueue(8);
    cout << "q.enqueue(8): " << q << endl;
    q.dequeue();
    cout << "q.dequeue(): " << q << endl;
    q.dequeue();
    cout << "q.dequeue(): " << q << endl;
    q.enqueue(9);
    cout << "q.enqueue(9): " << q << endl;
    q.enqueue(1);
    cout << "q.enqueue(1): " << q << endl;
    q.dequeue();
    cout << "q.dequeue(): " << q << endl;
    q.enqueue(7);
    cout << "q.enqueue(7): " << q << endl;
    q.enqueue(6);
    cout << "q.enqueue(6): " << q << endl;
    q.dequeue();
    cout << "q.dequeue(): " << q << endl;
    q.dequeue();
    cout << "q.dequeue(): " << q << endl;
    q.enqueue(4);
    cout << "q.enqueue(4): " << q << endl;
    q.dequeue();
    cout << "q.dequeue(): " << q << endl;
    q.dequeue();
    cout << "q.dequeue(): " << q << endl;
    q.enqueue(0);
    cout << "q.enqueue(0): " << q << endl;
    q.enqueue(1);
    cout << "q.enqueue(1): " << q << endl;
    q.enqueue(2);
    cout << "q.enqueue(2): " << q << endl;
    q.enqueue(3);
    cout << "q.enqueue(3): " << q << endl;
    q.dequeue();
    cout << "q.dequeue(): " << q << endl;
    q.dequeue();
    cout << "q.dequeue(): " << q << endl;
    q.dequeue();
    cout << "q.dequeue(): " << q << endl;
}


int main() {
    probarClaseCola();
    
    return EXIT_SUCCESS;
}
