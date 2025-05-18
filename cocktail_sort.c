#include <stdbool.h>

#include "array_util.h"

void cocktail_sort(int[], int, int[]);

static int cmp_count = 0;
static int swp_count = 0;

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
//    cocktail_sort(arr, n, stats);
//    //print_array(arr, n);
//
//    //printf("cmp_count: %d\tswp_count: %d\n", stats[0], stats[1]);
//    printf("cmp_count: %d\tswp_count: %d\n", cmp_count, swp_count);
//
//    return 0;
//}

void cocktail_sort(int arr[], int n, int stats[])
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

                swp_count++;
            }
            cmp_count++;
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

                swp_count++;
            }
            cmp_count++;
        }
        
        if (!swapped)
            break;
    }

    stats[0] = cmp_count;
    stats[1] = swp_count;
}
