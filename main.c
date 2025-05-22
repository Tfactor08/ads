#include <stdio.h>
#include <time.h>
#include <string.h>

#include "array_util.h"

#define K 25 // elements repetition %
#define L 12 // sortetd subarrays amount
#define M 5  // amount of random elements in sorted array

void cocktail_sort(int arr[], int n, int stats[]);
void heap_sort(int arr[], int n, int stats[]);
void bitonic_sort(int arr[], int n, int stats[]);

void gen_arr_for_each_n(int arr1[], int arr2[], int arr3[]);
void test_random(int *arr1, int *arr2, int *arr3);
void test_repeated_random(int *arr1, int *arr2, int *arr3);
double measure(void (*f)(int[], int, int[]), int arr[], int n, int stats[]);
void print_stats(double time, int stats[]);

static void (*algos[3])(int[], int, int[]) = {cocktail_sort, heap_sort, bitonic_sort};
static char *algo_names[] = {"cocktail", "heap", "bitonic"};
static int ns[] = {100, 1000, 10000};

// TODO
// well, we need to generate 3*4 arrays.
// of course it's better to generate a random one just once and then copy it (don't know how) and modify.
// i want to keep current logic, but repeat it for each array type.
// so i want testing different ns for each array type, not different arrays for each n.

int main(int argc, char **argv)
{


    return 0;
}

void test_each_arr_type()
{
    int arr1[ns[0]];
    int arr2[ns[1]];
    int arr3[ns[2]];

    // define 3 array types (3 for each type)
    // generate 3 array types (3 for each type)
    // and pass to the test_arrays

    gen_arr_for_each_n(arr1, arr2, arr3);

    test_random(arr1, arr2, arr3);

    // here call
    // test_random(arr1, arr2, arr3);
    // test_repeated_random(arr1, arr2, arr3);
    // etc.
}

// arr1 must contain ns[0] elements
// arr2 must contain ns[1] elements
// arr3 must contain ns[2] elements
void test_arrays(char *test_name, int *arr1, int *arr2, int *arr3)
{
    int *arrs[] = {arr1, arr2, arr3};
    int *arrs_cpy[3];

    for (int i = 0; i < 3; i++) {
        int n = ns[i];
        arrs_cpy[i] = malloc(n * sizeof(int));
        memcpy(arrs_cpy[i], arrs[i], n * sizeof(int));
    }

    printf("%s\n", test_name);
    printf("----------------------------------------------------------------\n\n");
    for (int i = 0; i < 3; i++) {
        int n = ns[i];

        printf("n = %d\n", n);
        printf("----------------------------------------------------------------\n");
        for (int j = 0; j < 3; j++) {
            double time;
            int stats[2];

            time = measure(algos[j], arrs_cpy[i], n, stats);

            printf("%s:\n", algo_names[j]);
            print_stats(time, stats);
            if (j != 2)
                putchar('\n');
        }
        printf("----------------------------------------------------------------\n\n");
    }


    for (int i = 0; i < 3; ++i)
        free(arrs_cpy[i]);
}

void gen_random_arrs(int arr1[], int arr2[], int arr3[])
{
    int n;
    n = ns[0];
    fill_array(arr1, n);
    n = ns[1];
    fill_array(arr2, n);
    n = ns[2];
    fill_array(arr3, n);
}

// arr1[], arr2[], arr3[] must be filled with random elements
void gen_random_arrs_with_repeated_element(int arr1[], int arr2[], int arr3[])
{
    int n;
    n = ns[0];
    repeat_element(K, arr1, n);
    n = ns[1];
    repeat_element(K, arr2, n);
    n = ns[2];
    repeat_element(K, arr3, n);
}

double measure(void (*f)(int[], int, int[]), int arr[], int n, int stats[])
{
    clock_t start = clock();
    f(arr, n, stats);
    clock_t end = clock();
    return ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
}

void print_stats(double time, int stats[])
{
    printf("time: %gms\t\tcmp_count: %d\t\tswp_count: %d\n", time, stats[0], stats[1]);
}
