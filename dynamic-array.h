#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct node_t node_t;

struct node_t {
    int data;
    node_t *next;
};

node_t* init_array(int n);
void go_through(node_t*);
void free_array(node_t*);
void add_element(node_t*, int, int);
int get_element(node_t*, int);

#endif
