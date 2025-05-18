#include "array_util.h"

void heapify(int arr[], int n);
void swap(int *a, int *b);
void sift_down(int arr[], int from, int to);
void sift_up(int arr[], int i);

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
//
//    //print_array(arr, n);
//    heap_sort(arr, n);
//    //print_array(arr, n);
//
//    printf("cmp_count: %d\tswp_count: %d\n", cmp_count, swp_count);
//
//    return 0;
//}

void heap_sort(int arr[], int n, int stats[])
{
    heapify(arr, n);
    int last = n - 1;
    while (last > 0) {
        swap(&arr[0], &arr[last]);
        sift_down(arr, 0, last--);
        cmp_count++; swp_count++;
    }

    stats[0] = cmp_count;
    stats[1] = swp_count;
}

void heapify(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        sift_up(arr, i);
}

void sift_up(int arr[], int i)
{
    while (i > 0) {
        int j = (i-1) / 2; // parent node index

        cmp_count += 2;

        if (arr[i] > arr[j]) {
            swap(&arr[i], &arr[j]);

            swp_count++;
        }
        else
            break;
        i = j;
    }
}

void sift_down(int arr[], int from, int to)
{
    while (1) {
        int lj = 2*from + 1; // first child node index
        int rj = 2*from + 2; // second child node index
        int mxi = from;

        cmp_count += 3;

        if (lj < to && arr[lj] > arr[mxi])
            mxi = lj;
        if (rj < to && arr[rj] > arr[mxi])
            mxi = rj;
        if (mxi != from) {
            swap(&arr[from], &arr[mxi]);
            from = mxi;

            swp_count++;
        }
        else
            break;
    }
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
