#include <stdlib.h>
#include <stdio.h>

typedef struct node_t node_t;
typedef struct queue queue;

node_t* init_array(int n);
void add_element(node_t*, int, int);
int get_element(node_t*, int);

struct node_t {
    int data;
    node_t *next;
};

struct queue {
    node_t *data;
    int top;
    int first;
};

queue init_queue() {
    queue s; 
    s.top = -1;
    s.first = -1;
    s.data = init_array(0);
    return s;
}

int is_empty(queue *s) {
    return s->top == -1;
}

void enqueue(queue *s, int value) {
    if (s->top == -1) {
        s->data->data = value;
        s->top++;
        return;
    }
    add_element(s->data, ++(s->top), value);
}

int dequeue(queue *s) {
    if (is_empty(s)) {
        printf("Cannot pop from empty queue\n");
        return -1;
    }
    return get_element(s->data, ++(s->first));
}

queue gen_queue(int n)
{
    queue q = init_queue();
    for (int i = 0; i < n; ++i)
        enqueue(&q, rand() % 20);
    return q;
}
