#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "dynamic-array.h"

// 13.03.25
// current version is memory unsafe -- we don't free the memory we allocate
// 14.03.25
// now it has to be safe but not sure
// 16.03.25
// now can add new element for any index including adding to the end
// TODO
// add returning error codes in 'add_element()'

node_t* init_array(int n)
{
    node_t *p_start = (node_t *)malloc(sizeof(node_t));
    node_t *p = p_start;

    for (int i = 0; i < n-1; ++i) {
        p->data = rand() % 21 - 10; // -> means (*p).
        p->next = (node_t *)malloc(sizeof(node_t));
        p = p->next;
    }
    p->data = n-1; // for the last node we have to do it outside the loop because otherwise in the
                   // loop we would allocate extra memory we don't need
    p->next = NULL;

    return p_start;
}

// *pa -- the first node in the array
void go_through(node_t *pa)
{
    while (pa != NULL) {
        printf("%d\n", pa->data);
        pa = pa->next;
    }
}

// add new element to the array at the given index
// *pa -- the first node in the array
void add_element(node_t *pa, int index, int element)
{
    int i = 0;

    if (index == 0) {
        // to add an element to the start of the array we just need to add new node that points
        // to the old starting node. But in that case the address of the starting node will be
        // changed and we would have to return it. So instead we use the old starting node address
        // to create new one and replace its content to a new address
        node_t *p_new = (node_t *)malloc(sizeof(node_t)); // address to place the old starting node
        p_new->data = pa->data;
        p_new->next = pa->next;
        pa->data = element;
        pa->next = p_new;
        return;
    }

    while (pa != NULL) {
        if (i != index - 1) {
            pa = pa->next;
            i++;
            continue;
        }

        node_t *p_new = (node_t *)malloc(sizeof(node_t));
        p_new->data = element;
        p_new->next = pa->next;
        pa->next = p_new;
        return;
    }
}

int get_element(node_t *pa, int index) {
    for (int i = 0; i <= index && pa != NULL; ++i) {
        if (i != index) {
            pa = pa->next;
            continue;
        }
        return pa->data;
    }
    return -1;
}

void free_array(node_t *pa)
{
    while (pa != NULL) {
        node_t *pnext = pa->next;
        free(pa);
        pa = pnext;
    }
}

//int main()
//{
//    node_t *arr = init_array(10);    
//    go_through(arr);
//    free(arr);
//}
