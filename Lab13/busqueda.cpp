#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <ctime>

using namespace std;


int buscar(vector<int> A, int x) {
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



int busquedaBinaria(vector<int> A, int x) {
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


int maximo(int a, int b) {
    return a >= b ? a : b;
}


int minimo(int a, int b) {
    return a <= b ? a : b;
}



void ejecutarExperimentos(int tam, char busquedas) {
    int TAM_ARREGLO = tam;
    int BUSQUEDAS = busquedas;
    vector<int> A(TAM_ARREGLO);
    float it_sec = 0.0;
    float it_bin = 0.0;
    int min_it_sec = INT_MAX;
    int max_it_sec = 0;
    int min_it_bin = INT_MAX;
    int max_it_bin = 0;

    for (size_t i = 0; i < TAM_ARREGLO; i++)
        A[i] = i;

    srand((unsigned) time(0));
    for (int i = 0; i < BUSQUEDAS; i++) {
        int x = rand() % TAM_ARREGLO;
    
        int iter_s = buscar(A, x);
        int iter_b = busquedaBinaria(A, x);
        cout << "Búsqueda " << i+1 << ": " << x << "\n\tNum. iteraciones secuencial: " << iter_s << endl << "\tNum. iteraciones binaria: " << iter_b << endl;
        it_sec += iter_s;
        it_bin += iter_b;
        min_it_sec = minimo(min_it_sec, iter_s);
        max_it_sec = maximo(max_it_sec, iter_s);
        min_it_bin = minimo(min_it_bin, iter_b);
        max_it_bin = maximo(max_it_bin, iter_b);
    }
    cout << "***** Resultados *****" << endl;
    cout << "Búsqueda secuencial:" << endl;
    cout << "\tPromedio iteraciones: " << (it_sec/BUSQUEDAS) << endl;
    cout << "\tMínimo iteraciones: " << min_it_sec << endl;
    cout << "\tMáximo iteraciones: " << max_it_sec << endl;
    cout << "Búsqueda binaria:" << endl;
    cout << "\tPromedio iteraciones: " << (it_bin/BUSQUEDAS) << endl;
    cout << "\tMínimo iteraciones: " << min_it_bin << endl;
    cout << "\tMáximo iteraciones: " << max_it_bin << endl;
}


int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Sintaxis: busqueda.out TAM_ARREGLO NUM_BUSQUEDAS" << endl;
        return EXIT_FAILURE;
    }
    ejecutarExperimentos (stoi(argv[1]), stoi(argv[2]));
    return EXIT_SUCCESS;
}
