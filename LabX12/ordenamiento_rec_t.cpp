
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <chrono>

#include "ordenamiento_rec_t.h"

using namespace std;
using namespace std::chrono;


duration<double> crear_arreglo(int *A, int TAM_ARREGLO, int RANGO_MAX) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    for (int i = 0; i < TAM_ARREGLO; i++) {
        int x = rand() % RANGO_MAX;
        A[i] = x;
    }
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}


duration<double> ordenar_merge_sort(int* A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    merge_sort(A, 0, TAM_ARREGLO-1);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}


duration<double> ordenar_quicksort(int* A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    quicksort(A, 0, TAM_ARREGLO-1);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}


int* copiar_arreglo(int A[], int n) {
    int *aux = new int[n];
    for (int i = 0; i < n; i++) {
        aux[i] = A[i];
    }
    return aux;
}


void mostrar_arreglo(int *A, int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}


void experimentos(int tam, int reps, bool ms, bool qs) {

    int TAM_ARREGLO = tam;
    int RANGO_MAX = 10 * TAM_ARREGLO;
    int REPETICIONES = reps;
    double t_prom_ms = 0.0;
    double t_prom_qs = 0.0;

    srand((unsigned) time(0));
    for (int i = 0; i < REPETICIONES; i++) {
        cout << "*** REPETICION " << i+1 << " ***" << endl;
        int *A = new int[TAM_ARREGLO];
        duration<double> tiempo;

        // Arreglo aleatorio
        cout << "Creando arreglo aleatorio de tamaño " << TAM_ARREGLO << "... " << flush;
        tiempo = crear_arreglo(A, TAM_ARREGLO, RANGO_MAX);
        cout << "\tCreado. ";
        cout << "\tTiempo: " << tiempo.count() << "s" << endl;

        int *aux;
        if (ms) {
            aux = copiar_arreglo(A, TAM_ARREGLO);
            cout << "Iniciando ordenamiento con MERGE SORT... " << flush;
            tiempo = ordenar_merge_sort(aux, TAM_ARREGLO);
            cout << "\tOrdenado. ";
            cout << "\tTiempo: " << tiempo.count() << "s" << endl;
            t_prom_ms = t_prom_ms + tiempo.count();
            delete [] aux;
        }

        if (qs) {
            aux = copiar_arreglo(A, TAM_ARREGLO);
            cout << "Iniciando ordenamiento con QUICKSORT... " << flush;
            tiempo = ordenar_quicksort(aux, TAM_ARREGLO);
            cout << "\tOrdenado. ";
            cout << "\tTiempo: " << tiempo.count() << "s" << endl;
            t_prom_qs = t_prom_qs + tiempo.count();
            delete [] aux;
        }

        delete [] A;
        cout << endl;
    }
    t_prom_ms = t_prom_ms / REPETICIONES;
    t_prom_qs = t_prom_qs / REPETICIONES;
    cout << "*** TIEMPO PROMEDIO ***" << endl;
    if (ms) {
        cout << "Merge sort:\t" << t_prom_ms << endl;
    }
    if (qs) {
        cout << "Quicksort:\t" << t_prom_qs << endl;
    }
}


bool incluirAlgoritmo(string listaAlgs, char alg) {
    size_t incluir = listaAlgs.find(alg);
    return incluir != string::npos;
}


int main(int argc, char * argv[]) {
    if (argc != 4) {
        cout << "Sintaxis: ordenamiento_t <tamaño_arreglo> <repeticiones> <lista_algoritmos>" << endl;
        cout << "Algoritmos:" << endl;
        cout << "m: merge sort" << endl;
        cout << "q: quicksort" << endl;
    } else {
        bool ms = incluirAlgoritmo(argv[3], 'm');
        bool qs = incluirAlgoritmo(argv[3], 'q');
        experimentos(atol(argv[1]), atoi(argv[2]), ms, qs);
    }
    return EXIT_SUCCESS;
}
