#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

void intercambiar(int A[], int x, int y) {
    int aux = A[x];
    A[x] = A[y];
    A[y] = aux;
}


long long selection_sort_ni(int A[], int n) {
    long long num_inst = 0;
    num_inst++;
    for (int j = 0; j < n-1; j++) {
        int menor = j;
        for (int i = j+1; i < n; i++) {
            if (A[i] < A[menor]) {
                menor = i;
                num_inst += 1;
            }
            num_inst += 3;
        }
        intercambiar (A, j, menor);
        num_inst += 7;
    }
    return num_inst;
}


void selection_sort(int A[], int n) {
    for (int j = 0; j < n-1; j++) {
        int menor = j;
 
        // Encuentra el elemento minimo del subarreglo
        // que no está ordenado
        for (int i = j+1; i < n; i++) {
            if (A[i] < A[menor]) {
                menor = i;
            }
        }
        intercambiar (A, j, menor);
    }
}


#endif // SELECTIONSORT_H
