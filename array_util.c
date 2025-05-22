#include "array_util.h"

// TODO
// test break_into_sorted_subarrs

static void shuffle(int *arr, int n)
{
    if (n > 1) {
        for (int i = 0; i < n - 1; i++) {
            int j = i + rand() % (n - i);
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
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
    srand(time(NULL));

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 21 - 10;
}

// p -- repetition %
// n -- array size
void repeat_element(int p, int arr[], int n)
{
    int indexes[n];
    int rep_amount = n * ((double)p / 100);

    for (int i = 0; i < n; ++i)
        indexes[i] = i;

    shuffle(indexes, n);

    for (int i = 0; i < rep_amount; ++i)
        arr[indexes[i]] = 69;
}

// arr must be sorted!
// c -- desired amount of sorted sub arrays
// n -- array size
void break_into_sorted_subarrs(int c, int arr[], int n)
{
    int break_points[n];
    int min_rnd = -10;
    int max_rnd = 10;

    for (int i = 0; i < n; ++i)
        break_points[i] = i;
    shuffle(break_points, n);

    for (int i = 0; i < c-1; ++i) {
        int bp = break_points[i];
        // ensure new_val is not in range [arr[bp-1], arr[bp+1]] since in that case array would've stayed sorted
        int excluded_low = min_rnd, excluded_high = max_rnd;
        if (bp != 0)
            excluded_low = arr[bp-1];
        if (bp != n-1)
            excluded_high = arr[bp+1];

        int excluded_size = excluded_high - excluded_low + 1;
        int new_val = rand() % (22 - excluded_size) - 10;
        if (new_val >= excluded_low) new_val += excluded_size;

        arr[bp] = new_val;
    }
}
