#include "array_util.h"

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    putchar('\n');
}

void fill_array(int arr[], int n)
{
    srand(time(NULL));

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 21 - 10;
}
