#include <iostream>
#include <ctime>
using namespace std;

/* Muestra el funcionamiento del ciclo for. */
int main() {
    const int NUM_ELEMENTOS = 100;
    double b[NUM_ELEMENTOS];

    /* initialize random seed: */
    srand (time(NULL));
    
    for (int i = 0; i < NUM_ELEMENTOS; i++) {
        b[i] = rand() % 100 + 1;
        if (rand() % 2 == 0)
            b[i] *= (-1);
    }
    
    for (int i = 0; i < NUM_ELEMENTOS; i++) {
        if (b[i] > 0)
            cout << b[i] << '\n';
    }
}
