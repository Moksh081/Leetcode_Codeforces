//DAA ass 1
//Quick_sort
#include<iostream>
using namespace std;

int partition(int A[], int p, int r) {
    int pivot = A[r];
    int i = p - 1;

    for (int j = p; j <= r - 1; j++) {
        if (A[j] <= pivot) {
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[r]);
    return i + 1;
}

void Quicksort(int A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        Quicksort(A, p, q - 1);
        Quicksort(A, q + 1, r);
    }
}

int main() {
    int A[] = {2, 8, 7, 1, 3, 5, 6, 4};
    int start = 0;  // corrected start index
    int end = 7;    // corrected end index
    int n = sizeof(A) / sizeof(A[0]);

    Quicksort(A, start, end);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    return 0;
}

