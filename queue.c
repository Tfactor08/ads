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

int is_queue_empty(queue *s) {
    return s->top == -1;
}

void enqueue(queue *q, int value) {
    if (q->top == -1) {
        q->data->data = value;
        q->top++;
        return;
    }
    add_element(q->data, ++(q->top), value);
}

int dequeue(queue *q) {
    if (is_queue_empty(q)) {
        printf("Cannot pop from empty queue\n");
        return -1;
    }
    return get_element(q->data, ++(q->first));
}

queue gen_queue(int n, char f)
{
    queue q = init_queue();
    for (int i = 0; i < n; ++i)
    {
        int r = rand() % 20;
        enqueue(&q, r);
        if (f) printf("%d\t", r);
    }
    return q;
}
