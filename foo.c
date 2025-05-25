#include <string.h>

#include "array_util.h"

static int ns[] = {1, 2, 3};

//void test_arr_copy(int *arr1, int *arr2, int *arr3)
//{
//    int *arrs[] = {arr1, arr2, arr3};
//    int *arrs_cpy[3];
//
//    for (int i = 0; i < 3; i++) {
//        int n = ns[i];
//        arrs_cpy[i] = malloc(n * sizeof(int));
//        memcpy(arrs_cpy[i], arrs[i], n * sizeof(int));
//    }
//
//    arrs_cpy[0][0] = 69;
//
//    for (int i = 0; i < 3; ++i) {
//        printf("array %d\n", i);
//        int n = ns[i];
//        for (int j = 0; j < n; ++j) {
//            printf("%d\t", arrs_cpy[i][j]);
//        }
//        putchar('\n');
//    }
//}

void test_arr_breaking()
{
    int arr[] = {0, 1, 1, 5, 5, 8, 9, 10, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; ++i)
        printf("%d\t", arr[i]);
    putchar('\n');

    break_into_sorted_subarrs(4, arr, n);

    for (int i = 0; i < n; ++i)
        printf("%d\t", arr[i]);
}

// TODO
// well, array breaking seems to be working, but i'm not sure, so it needs further testing.

int main()
{
    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        int left_bound = 5;
        int right_bound = 10;
        printf("%d\n", (rand() % (right_bound+1 - left_bound)) + left_bound); // [0, 10]; [0, 5]; [5, 10]
    }
    exit(0);

    test_arr_breaking();
    
    // [-10, 10] / [-8, 10]

    //int excluded_low = -10, excluded_high = 10;

    //int excluded_size = excluded_high - excluded_low + 1;
    //for (int i = 0; i < 100; ++i) {
    //    int new_val = rand() % (22 - excluded_size) - 10;
    //    if (new_val >= excluded_low) new_val += excluded_size;

    //    printf("%d\t", new_val);
    //}


    //int *arrs[] = {
    //    (int[]){1},
    //    (int[]){3, 5},
    //    (int[]){7, 9, 11}
    //};

    //test_random(arrs[0], arrs[1], arrs[2]);
    //putchar('\n');

    //for (int i = 0; i < 3; ++i) {
    //    printf("array %d\n", i);
    //    int n = ns[i];
    //    for (int j = 0; j < n; ++j) {
    //        printf("%d\t", arrs[i][j]);
    //    }
    //    putchar('\n');
    //}

    return 0;
}

// TODO
// it seems to be working (excpet getting out of bounds), but needs to be tested.
// also i'm sure it's a very dumb way, so better approach needs to be found.
// Update: it indeed was very dumb since it's easier to just shuffle pre-generated range.

// p -- repetition %
// n -- array size
//void repeat_element(int p, int arr[], int n)
//{
//    int rep_amount = n * (double)p / 100;
//    int indexes[rep_amount];
//
//    // create random range from 0 to n-1 containing 'rep_amount' unique indexes
//    indexes[0] = rand() % n;
//    for (int i = 1; i < rep_amount; ++i) {
//        int already_used = 0;
//        int j = rand() % n;
//        do {
//            // TODO
//            // we need to start decreasing j if increasing gets out of bounds
//            j++;
//            // check if j already in indexes
//            for (int k = 0; k < i; ++k) {
//                if (indexes[k] == j) {
//                    already_used = 1;
//                    break;
//                }
//            }
//            if (!already_used)
//                indexes[i] = j;
//        } while (already_used);
//    }
//
//    for (int i = 0; i < rep_amount; ++i) 
//        printf("%d\t", indexes[i]);
//    putchar('\n');
//}
