#include <stdbool.h>

#include "array_util.h"

static int cmp_count = 0;
static int swp_count = 0;

// Compare and swap elements to make them bitonic
void compare_and_swap(int a[], int i, int j, bool dir)
{
    if (dir == (a[i] > a[j])) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        swp_count++;
    }
    cmp_count++;
}

// Recursively merge a bitonic sequence
void bitonic_merge(int a[], int low, int cnt, bool dir)
{
    if (cnt > 1) {
        int k = cnt / 2;
        for (int i = low; i < low + k; i++)
            compare_and_swap(a, i, i + k, dir);
        bitonic_merge(a, low, k, dir);
        bitonic_merge(a, low + k, k, dir);

        cmp_count++;
    }
}

// Recursively generate a bitonic sequence
void sort(int a[], int low, int cnt, bool dir)
{
    if (cnt > 1) {
        int k = cnt / 2;
        sort(a, low, k, true);    // Sort ascending
        sort(a, low + k, k, false); // Sort descending
        bitonic_merge(a, low, cnt, dir);  // Merge the whole sequence

        cmp_count++;
    }
}

void bitonic_sort(int a[], int n, int stats[])
{
    sort(a, 0, n, true);

    stats[0] = cmp_count;
    stats[1] = swp_count;
}

//int main(int argc, char **argv)
//{
//    int n = 10;
//    if (argc >= 2)
//        n = atoi(argv[1]) ? atoi(argv[1]) : 10;
//    int arr[n];
//    int stats[2];
//
//    printf("n = %d\n", n);
//
//    fill_array(arr, n);
//    //print_array(arr, n);
//
//    sort(arr, n, true, stats);
//    //print_array(arr, n);
//
//    //printf("cmp_count: %d\tswp_count: %d\n", stats[0], stats[1]);
//    //printf("cmp_count: %d\tswp_count: %d\n", cmp_count, swp_count);
//
//    return 0;
//}
