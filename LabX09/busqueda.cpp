#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;


int buscarSec(vector<int> A, int x) {
    int i = 0;
    int indice = A.size();
    bool existe = false;
    
    while (!existe && (i < A.size()) && (A[i] <= x)) {
        if (A[i] == x)
            existe = true;
        else
            i += 1;
    }
    return i;
}



int buscarBin(vector<int> A, int x) {
    int inicio = 0;
    int fin = A.size() - 1;
    bool existe = false;
    int i = 0;
    
    while (!existe && (inicio <= fin)) {
        int mitad = (inicio + fin) / 2;
        if (A[mitad] == x) {
            existe = true;
        }
        else if (A[mitad] < x)
            inicio = mitad + 1;
        else
            fin = mitad - 1;
        i += 1;
    }
    return i;
}



int main() {

    int TAM_ARREGLO = 1000;
    vector<int> A;
    
    for (int i = 0; i < TAM_ARREGLO; i++)
        A.insert(A.end(), i);

    srand((unsigned) time(0));
    for (int i = 0; i < 10; i++) {
        int x = rand() % TAM_ARREGLO;
    
        int s = buscarSec(A, x);
        int b = buscarBin(A, x);
        cout << "Buscando: " << x << "; secuencial: " << s << "; binaria: " << b << endl;
    }

    return EXIT_SUCCESS;
}
