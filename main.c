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

void test_each_arr_type();
void gen_random_arrs(int arr1[], int arr2[], int arr3[]);
void gen_arrs_with_repeated_element(int arr1[], int arr2[], int arr3[]);
void gen_arrs_with_sorted_subarrs(int arr1[], int arr2[], int arr3[]);
void gen_arrs_with_swapped_elements(int arr1[], int arr2[], int arr3[]);
void test_arrays(char *test_name, int *arr1, int *arr2, int *arr3);
void test_repeated_random(int *arr1, int *arr2, int *arr3);
double measure(void (*f)(int[], int, int[]), int arr[], int n, int stats[]);
void print_stats(double time, int stats[]);

static void (*algos[3])(int[], int, int[]) = {cocktail_sort, heap_sort, bitonic_sort};
static char *algo_names[] = {"cocktail", "heap", "bitonic"};
static int ns[] = {100, 1000, 10000};

// TODO
// Well, we need to generate 3*4 arrays.
// Of course it's better to generate a random one just once and then copy it and modify.
// I want to keep current logic, but repeat it for each array type.
// So I want testing different ns for each array type, not different arrays for each n.

int main(int argc, char **argv)
{
    srand(time(NULL));

    test_each_arr_type();

    return 0;
}

void test_each_arr_type()
{
    int arr1[ns[0]];
    int arr2[ns[1]];
    int arr3[ns[2]];
    int* arrs[] = {arr1, arr2, arr3};
    int **dupls;

    gen_random_arrs(arr1, arr2, arr3);

    dupls = duplicate_arrays(arrs, 3, ns);
    test_arrays("Random Arrays", dupls[0], dupls[1], dupls[2]);

    dupls = duplicate_arrays(arrs, 3, ns);
    gen_arrs_with_repeated_element(dupls[0], dupls[1], dupls[2]);
    test_arrays("Random Arrays With Repeated Element", dupls[0], dupls[1], dupls[2]);

    dupls = duplicate_arrays(arrs, 3, ns);
    gen_arrs_with_sorted_subarrs(dupls[0], dupls[1], dupls[2]);
    test_arrays("Arrays With Sorted Sub Arrays", dupls[0], dupls[1], dupls[2]);

    dupls = duplicate_arrays(arrs, 3, ns);
    gen_arrs_with_swapped_elements(dupls[0], dupls[1], dupls[2]);
    test_arrays("Sorted Arrays With Elements Swapped To Random", dupls[0], dupls[1], dupls[2]);

    free_arrays(dupls, 3);
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

    printf("Test: %s\n", test_name);
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
void gen_arrs_with_repeated_element(int arr1[], int arr2[], int arr3[])
{
    int n;
    n = ns[0];
    repeat_element(K, arr1, n);
    n = ns[1];
    repeat_element(K, arr2, n);
    n = ns[2];
    repeat_element(K, arr3, n);
}

// arr1[], arr2[], arr3[] must be filled with random elements
void gen_arrs_with_swapped_elements(int arr1[], int arr2[], int arr3[])
{
    int n;

    n = ns[0];
    heap_sort(arr1, n, (int[2]){});
    swap_with_random(M, arr1, n);

    n = ns[1];
    heap_sort(arr2, n, (int[2]){});
    swap_with_random(M, arr2, n);

    n = ns[2];
    heap_sort(arr3, n, (int[2]){});
    swap_with_random(M, arr3, n);
}

// arr1[], arr2[], arr3[] must be filled with random elements
void gen_arrs_with_sorted_subarrs(int arr1[], int arr2[], int arr3[])
{
    int n;

    n = ns[0];
    heap_sort(arr1, n, (int[2]){});
    break_into_sorted_subarrs(L, arr1, n);

    n = ns[1];
    heap_sort(arr2, n, (int[2]){});
    break_into_sorted_subarrs(L, arr2, n);

    n = ns[2];
    heap_sort(arr3, n, (int[2]){});
    break_into_sorted_subarrs(L, arr3, n);
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
