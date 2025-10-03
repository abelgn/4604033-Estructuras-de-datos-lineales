#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <chrono>

#include "ordenamiento_t.h"

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


duration<double> ordenar_insertion_sort(int* A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    insertion_sort(A, TAM_ARREGLO);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}


duration<double> ordenar_selection_sort(int* A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    selection_sort(A, TAM_ARREGLO);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}


duration<double> ordenar_bubblesort(int* A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    bubblesort(A, TAM_ARREGLO);
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


void experimentos(int tam, int reps, bool is, bool ss, bool bs) {

    int TAM_ARREGLO = tam;
    int RANGO_MAX = 10 * TAM_ARREGLO;
    int REPETICIONES = reps;
    double t_prom_is = 0.0;
    double t_prom_ss = 0.0;
    double t_prom_bs = 0.0;

    srand((unsigned) time(0));
    for (int i = 0; i < REPETICIONES; i++) {
        cout << "*** REPETICION " << i+1 << " ***" << endl;
        int *A = new int[TAM_ARREGLO];
        duration<double> tiempo;

        // Arreglo aleatorio
        cout << "Creando arreglo aleatorio de tamaño " << TAM_ARREGLO << "... ";
        tiempo = crear_arreglo(A, TAM_ARREGLO, RANGO_MAX);
        cout << "\tCreado. ";
        cout << "\tTiempo: " << tiempo.count() << "s" << endl;

        int *aux;
        if (is) {
            aux = copiar_arreglo(A, TAM_ARREGLO);
            cout << "Iniciando ordenamiento con INSERTION SORT... ";
            tiempo = ordenar_insertion_sort(aux, TAM_ARREGLO);
            cout << "\tOrdenado. ";
            cout << "\tTiempo: " << tiempo.count() << "s" << endl;
            t_prom_is = t_prom_is + tiempo.count();
            delete [] aux;
        }

        if (ss) {
            aux = copiar_arreglo(A, TAM_ARREGLO);
            cout << "Iniciando ordenamiento con SELECTION SORT... ";
            tiempo = ordenar_selection_sort(aux, TAM_ARREGLO);
            cout << "\tOrdenado. ";
            cout << "\tTiempo: " << tiempo.count() << "s" << endl;
            t_prom_ss = t_prom_ss + tiempo.count();
            delete [] aux;
        }

        if (bs) {
            aux = copiar_arreglo(A, TAM_ARREGLO);
            cout << "Iniciando ordenamiento con BUBBLESORT... ";
            tiempo = ordenar_bubblesort(aux, TAM_ARREGLO);
            cout << "\tOrdenado. ";
            cout << "\tTiempo: " << tiempo.count() << "s" << endl;
            t_prom_bs = t_prom_bs + tiempo.count();
            delete [] aux;
        }

        delete [] A;
        cout << endl;
    }
    t_prom_is = t_prom_is / REPETICIONES;
    t_prom_ss = t_prom_ss / REPETICIONES;
    t_prom_bs = t_prom_bs / REPETICIONES;
    cout << "*** TIEMPO PROMEDIO ***" << endl;
    if (is) {
        cout << "Insertion sort:\t" << t_prom_is << endl;
    }
    if (ss) {
        cout << "Selection sort:\t" << t_prom_ss << endl;
    }
    if (bs) {
        cout << "Bubblesort:\t" << t_prom_bs << endl;
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
        cout << "i: insertion sort" << endl;
        cout << "s: selection sort" << endl;
        cout << "b: bubblesort" << endl;
    } else {
        bool is = incluirAlgoritmo(argv[3], 'i');
        bool ss = incluirAlgoritmo(argv[3], 's');
        bool bs = incluirAlgoritmo(argv[3], 'b');
        experimentos(atoi(argv[1]), atoi(argv[2]), is, ss, bs);
    }
    return EXIT_SUCCESS;
}
