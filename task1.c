#include "dynamic-array.h"

void add_zeros(node_t*);

/* create and process list S: S is a list of integers; after each negative add new zero element */
int main()
{
    node_t *ap = init_array(5);
    go_through(ap);

    putchar('\n');

    add_zeros(ap);

    go_through(ap);
    free_array(ap);

    return 0;
}

void add_zeros(node_t *ap)
{
    int i = 0;
    node_t *start_p = ap;
    
    while (ap != NULL) {
        if (ap->data < 0) {
            add_element(start_p, i+1, 0);
        }
        ap = ap->next;
        i++;
    }
}
