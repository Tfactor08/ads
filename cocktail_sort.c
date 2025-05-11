#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

void fill_array(int[], int);
void print_array(int[], int);
void cocktail_sort(int[], int);

int main()
{
    srand(time(NULL));

    int n = 10;
    int arr[n];

    fill_array(arr, n);

    print_array(arr, n);

    cocktail_sort(arr, n);

    print_array(arr, n);

    return 0;
}

void cocktail_sort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;

        for (int k = n-2; k >= i; k--) {
            if (arr[k] > arr[k+1]) {
                int tmp = arr[k];
                arr[k] = arr[k+1];
                arr[k+1] = tmp;
                swapped = true;
            }
        }
        
        if (!swapped)
            break;
    }
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    putchar('\n');
}

void fill_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 21 - 10;
}
