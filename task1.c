#include <stdio.h>

typedef struct node_t node_t;

node_t* init_array(int n);
void go_through(node_t*);
void free_array(node_t*);
void add_element(node_t*, int, int);

/* create and process list S: S is a list of integers; after each negative add new zero element */
int main()
{
    node_t *ap = init_array(5);
    go_through(ap);
    putchar('\n');
    add_element(ap, 5, 69);
    go_through(ap);
    free_array(ap);

    return 0;
}
