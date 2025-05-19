#include <stdio.h>
#include <time.h>

#include "array_util.h"

void cocktail_sort(int arr[], int n, int stats[]);
void heap_sort(int arr[], int n, int stats[]);
void bitonic_sort(int arr[], int n, int stats[]);

void test_each(int n);
double measure(void (*f)(int[], int, int[]), int arr[], int n, int stats[]);
void print_stats(double time, int stats[]);

void (*algos[3])(int[], int, int[]) = {cocktail_sort, heap_sort, bitonic_sort};
char *algo_names[] = {"cocktail", "heap", "bitonic"};
int ns[] = {100, 1000, 10000};

int main(int argc, char **argv)
{

    for (int i = 0; i < 3; i++) {
        int n = ns[i];

        printf("n = %d\n", n);
        printf("----------------------------------------------------------------\n");

        test_each(n);

        printf("----------------------------------------------------------------\n\n");
    }

    return 0;
}

void test_each(int n)
{
        for (int j = 0; j < 3; j++) {
            int arr[n];
            double time;
            int stats[2];

            fill_array(arr, n);

            time = measure(algos[j], arr, n, stats);

            printf("%s:\n", algo_names[j]);
            print_stats(time, stats);
            if (j != 2)
                putchar('\n');
        }
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
