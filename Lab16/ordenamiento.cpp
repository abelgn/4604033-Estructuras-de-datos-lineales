#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

#include "insertionsort.h"

using namespace std;


void mostrar_arreglo(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}


int* copiarArreglo(int A[], int n) {
    int *aux = new int[n];
    for (int i = 0; i < n; i++) {
        aux[i] = A[i];
    }
    return aux;
}


// Crea y devuelve un arreglo pseudoaleatorio
int* arreglo_pseudoaleatorio(int tamano, int rango) {
    int *A = new int[tamano];
    for (int i = 0; i < tamano; i++) {
        int x = rand() % rango;
        A[i] = x;
    }
    return A;
}



// Crea y devuelve un arreglo ordenado
int* arreglo_ordenado(int inicio, int fin) {
    int *A = new int[abs(fin - inicio) + 1];
    if (inicio < fin)
        for (int i = inicio; i <= fin; i++)
            A[i] = i;
    else
        for (int i = inicio; i >= fin; i--)
            A[inicio - i] = i;
    return A;
}


void experimentos(int tam, int modo, int reps) {

    int TAM_ARREGLO = tam;
    int RANGO_MAX = 10 * TAM_ARREGLO;
    int MODO = modo;
    int REPETICIONES = reps;
    double ops_prom_is = 0.0;
 
    srand((unsigned) time(0));
    for (int i = 0; i < REPETICIONES; i++) {
        cout << "*** REPETICION " << i+1 << " ***" << endl;

        int* A;
        if (MODO == 1) {
            cout << "Creando arreglo ordenado de forma ascendente de tamaño " << TAM_ARREGLO << "... ";
            A = arreglo_ordenado(0, TAM_ARREGLO-1);
        }
        else if (MODO == 2) {
            cout << "Creando arreglo ordenado de forma descendente de tamaño " << TAM_ARREGLO << "... ";
            A = arreglo_ordenado(TAM_ARREGLO-1, 0);
        }
        else {
            cout << "Creando arreglo aleatorio de tamaño " << TAM_ARREGLO << "... ";
            A = arreglo_pseudoaleatorio(TAM_ARREGLO, RANGO_MAX);
        }
        cout << "\tCreado. " << endl;

        int *aux;
        aux = copiarArreglo(A, TAM_ARREGLO);
        cout << "Iniciando ordenamiento con INSERTION SORT... ";
        long long ops_is = insertionsort_ni(aux, TAM_ARREGLO);
        cout << "\tOrdenado. ";
        delete [] aux;
        cout << "\tNúmero de operaciones: " << ops_is << endl;
        ops_prom_is += ops_is;
    }
    
    if (REPETICIONES > 1) {
        ops_prom_is = ops_prom_is / REPETICIONES;
        cout << "*** NÚMERO PROMEDIO DE OPERACIONES ***" << endl;
        cout << "Insertion sort:\t" << ops_prom_is << endl;
    }
}


int main(int argc, char * argv[]) {
    if ((argc < 3 || argc > 4) || (atoi(argv[2]) < 1 || atoi(argv[2]) > 3)) {
        cout << "Sintaxis: ordenamiento <tamaño_arreglo> <modo_arreglo_inicial> [<repeticiones> = 1]" << endl;
        cout << "Modo arreglo inicial:" << endl;
        cout << "1: arreglo ordenado de forma creciente" << endl;
        cout << "2: arreglo ordenado de forma decreciente" << endl;
        cout << "3: arreglo aleatorio" << endl;
    } else {
        if ((argc == 3) || (atoi(argv[2]) == 1 || atoi(argv[2]) == 2))
            experimentos(atoi(argv[1]), atoi(argv[2]), 1);
        else
            experimentos(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
    }
   
    return EXIT_SUCCESS;
}
