#include <iostream>
#include <ctime>
using namespace std;

/* Muestra el funcionamiento del ciclo while. */
int main() {
    const int NUM_ELEMENTOS = 100;
    double a[NUM_ELEMENTOS];
    int i = 0;
    int suma = 0;

    /* initialize random seed: */
    srand (time(NULL));
    
    for (int i = 0; i < NUM_ELEMENTOS; i++) {
        a[i] = rand() % 100 + 1;
        if (rand() % 2 == 0)
            a[i] *= (-1);
    }
    
    while (i < 100 && a[i] >= 0) {
        suma += a[i++];
    }
    cout << suma << endl;

}
