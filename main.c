#include <stdio.h>

typedef struct node_t node_t;
typedef struct stack stack;
typedef struct queue queue;

// dynamic-array.c
node_t* init_array(int n);
void go_through(node_t*);
void free_array(node_t*);
void add_element(node_t*, int, int);
int get_element(node_t*, int);

// stack.c
//stack init_stack();
//int is_empty(stack *s);
//void push(stack *s, int);
//int pop(stack *s);

// queue.c
queue init_queue();
int is_empty(queue *s);
void enqueue(queue *s, int);
int dequeue(queue *s);

struct queue {
    node_t *data;
    int top;
};

int main()
{
    queue q = init_queue();
    enqueue(&q, 69);
    enqueue(&q, 69);
    enqueue(&q, 42);
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    free_array(q.data);

    return 0;
}
