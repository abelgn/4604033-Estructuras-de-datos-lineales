#ifndef BUBBLESORT_H
#define BUBBLESORT_H


void intercambiar(int A[], int x, int y) {
    int aux = A[x];
    A[x] = A[y];
    A[y] = aux;
}


long long bubblesort_ni(int A[], int n) {
    long long num_inst = 0;
    num_inst++;
    for (int i = 0;  i < n-1; i++) {
        for (int j = n-1; j > i; j--) {
            if (A[j] < A[j-1]) {
                intercambiar(A, j, j-1);
                num_inst += 3;
            }
            num_inst += 3;
        }
        num_inst += 3;
    }
    return num_inst;
}


void bubblesort(int A[], int n) {
    for (int i = 0; i < n-1; i++) {
      
        // Los primeros i elementos ya estan ordenados
        for (int j = n-1; j > i; j--) {
            if (A[j] < A[j-1]) {
                intercambiar(A, j, j-1);
            }
        }
    }
}

#endif // BUBBLESORT_H
