#include <stdio.h>

typedef struct node_t node_t;

node_t* init_array(int n);
void go_through(node_t*);
void free_array(node_t*);
void add_element(node_t*, int, int);

struct node_t {
    int data;
    node_t *next;
};

void add_zeros(node_t *ap)
{
    int i = 0;
    
    while (ap != NULL) {
        if (ap->data < 0) {
            add_element(ap, i+1, 0);
        }
        ap = ap->next;
        i++;
    }
}

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
