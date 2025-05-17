#include <stdio.h>
#include <stdbool.h>

// Compare and swap elements to make them bitonic
void compareAndSwap(int a[], int i, int j, bool dir) {
    if (dir == (a[i] > a[j])) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

// Recursively merge a bitonic sequence
void bitonicMerge(int a[], int low, int cnt, bool dir) {
    if (cnt > 1) {
        int k = cnt / 2;
        for (int i = low; i < low + k; i++)
            compareAndSwap(a, i, i + k, dir);
        bitonicMerge(a, low, k, dir);
        bitonicMerge(a, low + k, k, dir);
    }
}

// Recursively generate a bitonic sequence
void bitonicSort(int a[], int low, int cnt, bool dir) {
    if (cnt > 1) {
        int k = cnt / 2;
        bitonicSort(a, low, k, true);    // Sort ascending
        bitonicSort(a, low + k, k, false); // Sort descending
        bitonicMerge(a, low, cnt, dir);  // Merge the whole sequence
    }
}

// Helper function to sort an array
void sort(int a[], int N, bool ascending) {
    bitonicSort(a, 0, N, ascending);
}

// Test the implementation
int main() {
    int a[] = {3, 7, 4, 8, 6, 2, 1, 5};
    int N = sizeof(a) / sizeof(a[0]);
    bool ascending = true; // Change to `false` for descending order
                           //
    printf("Original array: \n");
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    putchar('\n');

    sort(a, N, ascending);

    printf("Sorted array: \n");
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    putchar('\n');

    return 0;
}
