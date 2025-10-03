long long insertionSort(int A[], int n) {
    long long num_inst = 0;
    for (int i = 1; i < n; i++) {
        int k = A[i];
        int j = i-1;
        while ((j >= 0) && (A[j] > k)) {
            A[j+1] = A[j];
            j -= 1;
            num_inst += 3;
        }
        A[j+1] = k;
        num_inst += 1;
    }
    return num_inst;
}


long long selectionSort(int A[], int n) {
    long long num_inst = 0;
    for (int i = 0; i < n-1; i++) {
        int menor = i;
        for (int j = i+1; j < n; j++) {
            if (A[j] < A[menor]) {
                menor = j;
                num_inst += 1;
            }
            num_inst += 2;
        }
        int temp = A[i];
        A[i] = A[menor];
        A[menor] = temp;
        num_inst += 4;
    }
    return num_inst;
}


long long bubblesort(int A[], int n) {
    long long num_inst = 0;
    for (int i = 0;  i < n-1; i++) {
        for (int j = n-1; j > i; j--) {
            if (A[j] < A[j-1]) {
                int temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
                num_inst += 3;
            }
            num_inst += 2;
        }
        num_inst += 1;
    }
    return num_inst;
}


