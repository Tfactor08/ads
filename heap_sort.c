#include <stdio.h>

void heap_sort(int arr[], int n);
void heapify(int arr[], int n);
void sift_down(int arr[], int from, int to);
void sift_up(int arr[], int i);
void swap(int *a, int *b);

int main()
{
    int arr[] = {5, 69, 0, -2, 7, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; ++i)
        printf("%d\t", arr[i]);
    putchar('\n');

    heap_sort(arr, size);

    for (int i = 0; i < size; ++i)
        printf("%d\t", arr[i]);
    putchar('\n');

    return 0;
}

void heap_sort(int arr[], int n)
{
    heapify(arr, n);
    int last = n - 1;
    while (last > 0) {
        swap(&arr[0], &arr[last]);
        sift_down(arr, 0, last--);
    }
}

void heapify(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        sift_up(arr, i);
}

void sift_up(int arr[], int i)
{
    while (i > 0) {
        int j = (i-1) / 2; // parent node index
        if (arr[i] > arr[j])
            swap(&arr[i], &arr[j]);
        else
            break;
        i = j;
    }
}

void sift_down(int arr[], int from, int to)
{
    while (1) {
        int lj = 2*from + 1; // first child node index
        int rj = 2*from + 2; // second child node index
        int mxi = from;
        if (lj < to && arr[lj] > arr[mxi])
            mxi = lj;
        if (rj < to && arr[rj] > arr[mxi])
            mxi = rj;
        if (mxi != from) {
            swap(&arr[from], &arr[mxi]);
            from = mxi;
        }
        else
            break;
    }
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
