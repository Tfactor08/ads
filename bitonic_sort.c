#include <stdio.h>
#include <stdbool.h>

// Compare and swap elements to make them bitonic
void compare_and_swap(int a[], int i, int j, bool dir) {
    if (dir == (a[i] > a[j])) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

// Recursively merge a bitonic sequence
void bitonic_merge(int a[], int low, int cnt, bool dir) {
    if (cnt > 1) {
        int k = cnt / 2;
        for (int i = low; i < low + k; i++)
            compare_and_swap(a, i, i + k, dir);
        bitonic_merge(a, low, k, dir);
        bitonic_merge(a, low + k, k, dir);
    }
}

// Recursively generate a bitonic sequence
void bitonic_sort(int a[], int low, int cnt, bool dir) {
    if (cnt > 1) {
        int k = cnt / 2;
        bitonic_sort(a, low, k, true);    // Sort ascending
        bitonic_sort(a, low + k, k, false); // Sort descending
        bitonic_merge(a, low, cnt, dir);  // Merge the whole sequence
    }
}

// Helper function to sort an array
void sort(int a[], int N, bool ascending) {
    bitonic_sort(a, 0, N, ascending);
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
