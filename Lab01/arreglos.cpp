#include <iostream>
using namespace std;

/* Muestra el funcionamiento de los arreglos. */
int main() {
    // arreglo de 5 double: f[0], ..., f[4]
    double f[5];
    // arreglo de 10 int: m[0], ..., m[9]
    int m[10];
    f[4] = 2.5;
    m[2] = 4;
    // despliega f[4], que es 2.5
    cout << f[m[2]] << endl;

    // declara e inicializa a[4]
    int a[] = {10, 11, 12, 13};
    // declara e inicializa b[2]
    bool b[] = {false, true};
    // declara e inicializa c[3]
    char c[] = {'c', 'a', 't'};
}
