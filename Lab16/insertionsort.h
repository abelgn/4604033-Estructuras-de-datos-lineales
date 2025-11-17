#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H


long long insertionsort_ni(int A[], int n) {
    long long num_inst = 0;
    num_inst++;
    for (int i = 1; i < n; i++) {
        int k = A[i];
        int j = i-1;
        while ((j >= 0) && (A[j] > k)) {
            A[j+1] = A[j];
            j--;
            num_inst += 4;
        }
        A[j+1] = k;
        num_inst += 5;
    }
    return num_inst;
}


void insertionsort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int k = A[i];
        int j = i-1;
 
        // Se mueven los elementos de A[0..i-1], que son
        // mayores que k, a una posición hacia la derecha
        // de su posicion actual
        while (j >= 0 && A[j] > k) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = k;
    }
}

#endif // INSERTIONSORT_H
