#include "array_util.h"

// TODO
// so, now we know the edge cases -- when the split points are adjacent.
// and even edge cases within edge cases -- when the split points are located at the array bounds.
// look [breaking_hell]

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
//
// TODO
// manage edge cases.
void break_into_sorted_subarrs(int c, int arr[], int n)
{
    int break_points[n];
    int min_rnd = -11;
    int max_rnd = 11;

    for (int i = 0; i < n; ++i)
        break_points[i] = i;
    shuffle(break_points, n);

    for (int i = 0; i < c-1; ++i) {
        int bp = break_points[i];
        int excluded_low = min_rnd, excluded_high = max_rnd;

        // edge case: adjacent split points (may cancel each other)
        if (bp == break_points[i+1] + 1) {

            // edge case within edge case: index at left array bound
            if (bp == 0) {
                // here, we have only one option -- "gt next; gt next and lt prev" (i.e. isolate)
                
                // another edge case: the element we need to isolate can't be isolated
                if (arr[bp] == arr[bp+2]) {
                    // skip as I'm no clue what to do here
                    i++;
                    continue;
                }

                // must be gt next
                int lb = arr[1] + 1;
                int new_val1 = (rand() % (max_rnd+1 - lb)) + lb; // [arr[1]+1, max_rnd]
                arr[0] = new_val1;

                // must be gt next and lt prev
                int lb = arr[2] + 1;
                int new_val2 = (rand() % (new_val1 - lb)) + lb; // [arr[2]+1, new_val1-1]
                arr[1] = new_val2;

                i++;
                continue;
            }

            // edge case within edge case: index at right array bound
            if (bp == n-2) {
                // here, we must start and end with lt prev
                int rb = arr[n-2-1] - 1;
                int new_val1 = (rand() % (rb+1 - min_rnd)) + min_rnd; // [min_rnd, arr[n-2-1]]
                arr[n-2] = new_val1;

                int rb = arr[n-1-1] - 1;
                int new_val2 = (rand() % (rb+1 - min_rnd)) + min_rnd; // [min_rnd, arr[n-1-1]]
                arr[n-1] = new_val2;

                i++;
                continue;
            }
            
            // not edge case

            i++;
            continue;
        }

        // ensure new_val is not in range [arr[bp-1], arr[bp+1]] since otherwise array stays sorted
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
